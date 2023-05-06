#include <stdlib.h>
#include <string.h>

#include "../../trie/src/trie.h"
#include "types.h"

void DB_addString(Trie *tree, char *name, char *str) {
    Types *type = malloc(sizeof(Types));
    memset(type, 0, sizeof(Types));
    type->type = STRING;
    type->size = strlen(str) + 1;
    type->value = malloc(strlen(str) + 1);
    memcpy(type->value, str, strlen(str) + 1);

    Trie_addNode(tree, name, type, sizeof(Types));
}

void DB_addNumber(Trie *tree, char *name, int num) {
    Types *type = malloc(sizeof(Types));
    memset(type, 0, sizeof(Types));
    type->type = NUMBER;
    type->size = sizeof(int);
    type->value = malloc(sizeof(int));
    *(int*) type->value = num;

    Trie_addNode(tree, name, type, sizeof(Types));
}

void DB_addBoolean(Trie *tree, char *name, short value) {
    Types *type = malloc(sizeof(Types));
    memset(type, 0, sizeof(Types));
    type->type = BOOLEAN;
    type->size = sizeof(short);
    type->value = malloc(sizeof(short));
    *(short*) type->value = value;

    Trie_addNode(tree, name, type, sizeof(Types));
}

void DB_addRaw(Trie *tree, char *name, void *data, size_t length) {
    Types *type = malloc(sizeof(Types));
    memset(type, 0, sizeof(Types));
    type->type = RAW;
    type->size = length;
    type->value = malloc(length);
    memcpy(type->value, data, length);

    Trie_addNode(tree, name, type, sizeof(Types));
}

Types *DB_getType(Trie *tree, char *name) {
    return Trie_getNode(tree, name);
}
