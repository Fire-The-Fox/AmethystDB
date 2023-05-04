#include <stdio.h>

#include "trie/src/trie.h"

int main() {
    Trie *root = Trie_init();
    int d = 77;
    Trie_addNode(root, "hello", &d, sizeof(int));
    d = 50;
    Trie_addNode(root, "hell", &d, sizeof(int));
    d = 10;
    Trie_addNode(root, "help", &d, sizeof(int));

    printf("d1 = %d\n", *(int*) Trie_getNode(root, "hello"));
    printf("d1 = %d\n", *(int*) Trie_getNode(root, "hell"));
    printf("d1 = %d\n", *(int*) Trie_getNode(root, "help"));

    printf("Should be nil %p\n", Trie_getNode(root, "xhellp"));
    return 0;
}
