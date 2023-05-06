#ifndef _AMETHYST_TYPES_
#define _AMETHYST_TYPES_

#include <stddef.h>
#include "../../trie/src/trie.h"

typedef enum {
    STRING,
    NUMBER,
    BOOLEAN,
    RAW,
} DataType;

typedef struct {
    void *value;
    size_t size;
    DataType type;
} Types;

typedef struct {
    union {
        int n;
        short b;
        char *s;
        void *r;
    } val;
    short status;
    DataType type;
} DBResult;

void DB_addString(Trie *tree, char *name, char *str);
void DB_addNumber(Trie *tree, char *name, int num);
void DB_addBoolean(Trie *tree, char *name, short val);
void DB_addRaw(Trie *tree, char *name, void *data, size_t length);
Types *DB_getType(Trie *tree, char *name);

#endif
