#include "trie/src/trie.h"
#include "types/src/types.h"

Trie *createDB() {
    return Trie_init();
}

void setNumber(Trie *tree, char* key, int num) {
    DB_addNumber(tree, key, num);
}

void setString(Trie *tree, char* key, char *value) {
    DB_addString(tree, key, value);
}

void setBoolean(Trie *tree, char* key, short num) {
    DB_addBoolean(tree, key, num);
}

void setRaw(Trie *tree, char* key, void *data, unsigned long size) {
    DB_addRaw(tree, key, data, size);
}

DBResult getValue(Trie *tree, char *key) {
    DBResult res = {};

    Types *val = DB_getType(tree, key);
    if (!val) {
        res.val.r = NULL;
        res.type = RAW;
        res.status = 1;
    }

    res.status = 0;
    res.type = val->type;

    switch (val->type) {
        case NUMBER:
            res.val.n = *(int*) val->value;
            break;
        case STRING:
            res.val.s = (char*) val->value;
            break;
        case BOOLEAN:
            res.val.b = *(short*) val->value;
            break;
        case RAW:
            res.val.r = val->value;
            break;
    }

    return res;
}

int getNumber(Trie *tree, char *key) {
    return getValue(tree, key).val.n;
}

char *getString(Trie *tree, char *key) {
    return getValue(tree, key).val.s;
}

short getBoolean(Trie *tree, char *key) {
    return getValue(tree, key).val.b;
}

void *getRaw(Trie *tree, char *key) {
    return getValue(tree, key).val.r;
}
