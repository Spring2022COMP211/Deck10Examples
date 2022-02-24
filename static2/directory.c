#include <string.h>
#include <stdlib.h>
#include <stdio.h>
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

    static Entry *last_lookup = NULL;

    if (last_lookup != NULL) {
        if ((strcmp(first, last_lookup->first) == 0) &&
            (strcmp(last, last_lookup->last) == 0)) {
            printf("DEBUG: found in last lookup cache!\n");
            return last_lookup;
        }
    }

    for(int i=0; i<directory_size; i++) {
        if ((strcmp(first, directory[i].first) == 0) && 
            (strcmp(last, directory[i].last) == 0)) {
            last_lookup = &directory[i];
            return last_lookup;
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
