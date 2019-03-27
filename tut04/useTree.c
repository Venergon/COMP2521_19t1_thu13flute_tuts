
#include "BSTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMS 10

Tree createExampleTree(int *nums, int len);

int main(void) {
    int elems[NUM_ELEMS] = { 1, 2, 3, 7, 9, 5, 0, 4, 13, 54 };
    Tree t = createExampleTree(elems, NUM_ELEMS);
    printf("Tree is: \n");
    showTree(t);

    printf("Printing height difference of tree:\n");
    printHeightDiff(t);

    int height = isAVL(t);
    if (height == -1) {
        printf("Tree is not an avl tree\n");
    } else {
        printf("Tree is an avl tree with height %d\n", height);
    }

    freeTree(t);


    return EXIT_SUCCESS;
}

Tree createExampleTree(int *nums, int len) {
    Tree t = newTree();
    for (int i = 0; i < len; i++) {
        t = TreeInsert(t, nums[i]);
    }

    return t;
}
