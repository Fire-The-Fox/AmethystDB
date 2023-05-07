#ifndef _AMETHYST_TRIE_
#define _AMETHYST_TRIE_

#include <stddef.h>

#define KEY_COUNT 95 // ascii characters

typedef struct _TrieNode Trie;

typedef struct _TrieNode {
    Trie *letters[KEY_COUNT];
    void *data;
} Trie;

Trie *Trie_init();
void Trie_addNode(Trie *tree, char *name, void *data, size_t length);
void *Trie_getNode(Trie *tree, char *name);
#endif
