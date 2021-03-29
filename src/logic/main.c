#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wurfl.h>
#include "ll.h"
#include "hTable.h"
#include "logger.h"

#if IM_VERSION > 6
    #include <MagickWand/MagickWand.h>
#else
    #include <ImageMagick-6/wand/MagickWand.h>
#endif // IM_VERSION

int main()
{
    // SOME TESTS. Might delete later

    // hello world
    logMsg(D,"Hello world!\n");

    // ImageMagick version check
    logMsg(D, "ImageMagick version detected: %d\n", IM_VERSION);

    // Linked list test
    Node *head = makeNode("hello");
	printLL (head, "%s");

	appendLL(&head, "ao");
	appendLL(&head, "oa");
	appendLL(&head, "eeee");
	appendLL(&head, "ecco");
    printLL (head, "%s");

    char *buf;
    popLL(&head, 3, &buf);
    printLL (head, "%s");
    logMsg(D, "%s", buf);

	deleteLL(head);

	// Hash table test
    HashTable *hashTable = makeHashTable();
    add(hashTable, "key", "value");
    logMsg(D, "value is: %s\n", getValue(hashTable, "key"));
    destroyHashTable(hashTable);

    // END TESTS

    return 0;
}
