#ifndef DIRECTORY_H
#define DIRECTORY_H

typedef struct Entry {
    char *first;
    char *last;
    int id;
} Entry;

Entry *find(char *first, char *last);
Entry *findOrCreate(char *first, char *last);
Entry *findByID(int id);

#endif


