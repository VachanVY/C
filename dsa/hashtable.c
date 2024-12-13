// Given a file of N employee records with a set K of Keys (4-digits) which uniquely determine the
// records in the file F. Assume that file F is maintained in memory by a hash table of m memory
// locations with L as set of memory addresses (2-digit) of locations in HT. Let the keys in K and 
// adresses in L are integers. Design and develop a program in C that uses Function H: K -> L as
// H(K) = K mod m (remainder method), and implement hashing technique to map a given key K to the 
// address space L. Resolve the collision (if any) using linear probing

#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1

typedef struct HMap{
    size_t size;
    int* value;
    int count;
} HMap;

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE); // Terminates the program
}

HMap* init(size_t size){
    HMap* hmap = malloc(sizeof(HMap));
    hmap->value = malloc(sizeof(int)*size);
    for(size_t i=0; i<size; i++)
        hmap->value[i] = -1;
    hmap->size = size; // Set the size of the hash map
    hmap->count = 0;
    return hmap;
}

void insert(HMap* hmap, int value){
    size_t idx = value % hmap->size;
    size_t init_idx = idx;
    // only if idx is not empty go to the next one
    while(hmap->value[idx] != EMPTY){
        idx = (idx+1)%hmap->size;
        if(idx==init_idx)
            printf("Hash Table is Full");
    }
    hmap->value[idx] = value;
    hmap->count += 1;
}

size_t get_idx(HMap* hmap, int value){
    size_t idx = value % hmap->size;
    size_t init_idx = idx;

    // only if index is not empty go to the next one to search
    while (hmap->value[idx] != EMPTY){
        if(hmap->value[idx] == value){
            return idx;
        }
        idx = (idx + 1) % hmap->size;
        if(idx==init_idx){
            handleError("Error: Element with given key not found");
        }
    }
}

void display(HMap* hmap){
    printf("HashMap([\n");
    for(size_t i=0; i<hmap->size; i++){ // Iterate over the entire size of the hash map
        if(hmap->value[i] == EMPTY)
            printf("\t[%d]: [%s],\n", i, "EMPTY");
        else
            printf("\t[%d]: [%d],\n", i, hmap->value[i]);
    }
    printf("])\n");
}

int main(){
    HMap* hmap = init(10);
    insert(hmap, 111);
    insert(hmap, 100);
    insert(hmap, 111);
    insert(hmap, 132);
    insert(hmap, 321);
    insert(hmap, 35421);
    insert(hmap, 2536);
    insert(hmap, 32323);
    insert(hmap, 43245);
    insert(hmap, 5236111);
    display(hmap);
    printf("Search Index: %zu\n", get_idx(hmap, 111));
    printf("Search Index: %zu\n", get_idx(hmap, 43245));
}
