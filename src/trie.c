#include <stdlib.h>
#include <string.h>

#include <trie.h>

Trie *Trie_init() {
    Trie *t = malloc(sizeof(Trie));
    memset(t, 0, sizeof(Trie));
    return t;
}

void Trie_addNode(Trie *tree, char *name, void *data, size_t length) {
    char *walk = name;
    Trie *current = tree;

    while (*walk) {
        if (!current->letters[(*walk)-32]) {
            current->letters[(*walk)-32] = Trie_init();
        }
        current = current->letters[(*walk)-32];
        walk++;
    }

    current->data = malloc(length);
    memcpy(current->data, data, length);
}

void *Trie_getNode(Trie *tree, char *name) {
    char *walk = name;
    Trie *current = tree;

    while (*walk) {
        if (current->letters[(*walk)-32]) {
            current = current->letters[(*walk)-32];
        } else return NULL;
        walk++;
    }

    return current->data;
}
