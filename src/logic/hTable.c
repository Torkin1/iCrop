/*
    This file describes an implementation of an Hash Table with Collision Lists.
    Every key used to index a value is converted in a small unsigned integer used to index an array of
    table entries. Each table entry holds all values associated with that hash value.
*/

#include <string.h>
#include <stdlib.h>
#include "hTable.h"
#include "logger.h"

#define PRIME 31        // Prime number used to calculate hash. Using a prime number decreases the odds of incurring in a collision

// Calculates hash from key
unsigned hash(char *key){

    unsigned hash = 0;
    for (int i = 0; key[i] != '\0'; i ++){
        hash = key[i] + (PRIME * hash);
    }
    return (hash % HASHSIZE);
}

// Creates an HashTable
HashTable *newHashTable(){

    HashTable *hashTable = calloc(1, sizeof(HashTable));
    return hashTable;
}

// Return entry paired with given hash if present in table, NULL otherwise
Entry *getCollisionList (HashTable *self, unsigned hash){

    return (self -> table)[hash];
}

// Returns value paired with given key if present in table, NULL otherwise
char* getValueFromHashTable(HashTable *self, char* key){

    // gets collision list at calculated hash
    unsigned h = hash(key);
    Entry *collisionList = getCollisionList(self, h);

    if (collisionList != NULL){

        // There is at least one value associated with given hash. Returns the value associated with the given key
        for (Entry *currentEntryPointer = collisionList; currentEntryPointer != NULL; currentEntryPointer = (currentEntryPointer -> next)){
            Pair *pair = currentEntryPointer -> value;
            if (strcmp(pair -> key, key) == 0){
                return pair -> value;
            }
        }
    }

    // No entry was found, or no pair with given key was previously added to the table
    return NULL;
}

// Adds given pair key-value
void addToHashTable(HashTable *self, char *key, char *value){

    // calculates target index
    unsigned h = hash(key);

    // Creating a new pair with given key and value
    Pair *pair = calloc(1, sizeof(Pair));
    pair -> key = key;
    pair -> value = value;

    // Checks if already exists an entry in table with given hash
    Entry *collisionList = getCollisionList(self, h);
    if(collisionList == NULL){

        // Adds new collisionList to table paired with calculated hash
        (self -> table)[(int)h] = newNode(pair);

    } else {

        // Must check if key is already bound to a value
        Pair *currentPair;
        for (Entry *current = collisionList; current != NULL; current = current -> next){
            currentPair = current -> value;
            if (strcmp(currentPair -> key, key) == 0){

                // A pair already exists, dropping new pair and updating old pair it with new value
                free(pair);
                currentPair -> value = value;
                return;
            }
        }

        // No pair was found, adding a new one
        appendLL((self -> table) + (int) h, pair);

    }
}
void destroyHashTable(HashTable *self){

    // destroys every collision list on the list
    Entry *currentCollisionList;
    for (int i = 0; i < HASHSIZE; i ++){
        currentCollisionList = (self -> table)[i];

        // deletes every pair in collision list
        for (Entry *currentEntry = currentCollisionList; currentEntry != NULL; currentEntry = currentEntry -> next){
            free(currentEntry -> value);
        }

        // deletes collision list
        destroyLL(currentCollisionList);
    }

    // Deletes reference to hash table
    free(self);
}
