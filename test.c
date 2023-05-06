#include <stdio.h>
#include <time.h>

#include "trie/src/trie.h"
#include "types/src/types.h"

int main() {
    Trie *root = Trie_init();
    Trie *json = Trie_init();

    DB_addDB(root, "json", json);
    DB_addString(json, "kek", "I am fake json");

    Types *child = DB_getType(root, "json");
    if (child->type == DB) {
        printf("%s\n", (char*) DB_getType(child->value, "kek")->value);
    }
    return 0;
}
