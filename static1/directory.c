#include <string.h>
#include <stdlib.h>
#include "directory.h"


static Entry *directory = NULL;
static int directory_size = 0;
static int directory_capacity = 0;

static int generateID(char *first, char *last) {
    int id = 0;
    for (int i=0; i<strlen(first); i++) {
        id += first[i];
    }
    for (int i=0; i<strlen(last); i++) {
        id += last[i];
    }

    while (findByID(id) != NULL) {
        id++;
    }

    return id;
}
    

Entry *find(char *first, char *last) {
    for(int i=0; i<directory_size; i++) {
        if ((strcmp(first, directory[i].first) == 0) && 
            (strcmp(last, directory[i].last) == 0)) {
            return &directory[i];
        }
    }
    return NULL;
}

Entry *findOrCreate(char *first, char *last) {
    Entry *entry = find(first, last);
    if (entry == NULL) {
        if (directory_size == directory_capacity) {
            // Need more room.
            directory_capacity += 10;
            directory = (Entry *) realloc(directory, sizeof(Entry)*directory_capacity);
        }
        directory[directory_size].first = first;
        directory[directory_size].last = last;
        directory[directory_size].id = generateID(first, last);
        entry = &directory[directory_size];
        directory_size += 1;
    }
    return entry;
}
            
Entry *findByID(int id) {
    for (int i=0; i<directory_size; i++) {
        if (directory[i].id == id) {
            return &directory[i];
        }
    }
    return NULL;
}
