#define HASHSIZE 101    // Maximum number of collision lists in hash table

// Key-value pair
typedef struct {
    char *key;      // Key
    char *value;    // value
} Pair;

// Entries of hash table are collision lists implemented as linked lists. Value of nodes must be of Pair type
typedef Node Entry;

// Hash table implemented as an array of collision list
typedef struct {
    Entry *table[HASHSIZE];  // array of collision lists
} HashTable;

// Creates an HashTable
HashTable *makeHashTable();

// Returns value paired with given key if present in table, NULL otherwise
char* getValue(HashTable *self, char* key);

// Adds given pair key-value
void add(HashTable *self, char *key, char *value);

// Frees resources associated with HashTable object
void destroyHashTable(HashTable *self);
