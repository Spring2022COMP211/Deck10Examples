#include <stdlib.h>
#include <stdio.h>
#include "directory.h"


void printEntry(Entry *e) {
    if (e == NULL) {
        printf("NULL entry\n");
    } else {
        printf("%s, %s (%d)\n", e->last, e->first, e->id);
    }
}

int main() {
    Entry *e = findOrCreate("Leaky", "Black");
    printEntry(e);

    e = find("Ketan", "Mayer-Patel");
    printEntry(e);

    e = findOrCreate("Ketan", "Mayer-Patel");
    printEntry(e);

    printEntry(find("Ketan", "Mayer-Patel"));
    printEntry(find("Ketan", "Mayer-Patel"));
    printEntry(find("Ketan", "Mayer-Patel"));
    printEntry(find("Leaky", "Black"));
    printEntry(find("Leaky", "Black"));
    printEntry(find("Ketan", "Mayer-Patel"));
    printEntry(find("Leaky", "Black"));
    printEntry(find("Ketan", "Mayer-Patel"));
    printEntry(find("Ketan", "Mayer-Patel"));


    Entry *e2 = findByID(e->id);
    printEntry(e2);

}

