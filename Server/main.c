#include <stdio.h>

#include "research.h"
#include "create.h"


int main(){
    Realisator * real = createRealisator("tou", 3);
    Realisator * real2 = createRealisator("tab", 4);
    Node_realisator * root = initNode('R');
    addWord(root, "tou", real);
    addWord(root, "tab", real2);
    printTree(root);
    return 0;
}