#include <stdio.h>
#include <time.h>

#include "trie/src/trie.h"
#include "types/src/types.h"

int main() {
    Trie *root = Trie_init();
    int arr[] = {7, 1, 9, 5, 2};

    DB_addNumber(root, "num", 77);
    DB_addString(root, "string", "Anny");
    DB_addBoolean(root, "bool", 0);
    DB_addRaw(root, "arr", arr, sizeof(int) * 5);

    printf("num = %d\n", *(int*) DB_getType(root, "num")->value);
    printf("string = %s\n", (char*) DB_getType(root, "string")->value);
    printf("bool = %d\n", *(short*) DB_getType(root, "bool")->value);

    Types *type = DB_getType(root, "arr");
    if (type->type == RAW) {
        int *arr = type->value;
        for (int i = 0; i < type->size / sizeof(int); i++) {
            printf("arr[%d] = %d\n", i, arr[i]);
        }
    }

    return 0;
}
