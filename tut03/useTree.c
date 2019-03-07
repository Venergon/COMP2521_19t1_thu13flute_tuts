
#include "BSTree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_ELEMS 10

Tree createExampleTree(int *nums, int len);

int main(int argc, char **argv) {
    int elems[NUM_ELEMS] = { 1, 2, 3, 7, 9, 5, 0, 4, 13, 54 };
    Tree t = createExampleTree(elems, NUM_ELEMS);
    t = BSTBalance(t);
    printf("Tree is: \n");
    showTree(t);

    printf("Tree has %d non-leaf nodes\n", countInternal(t));

    printf("Node 5 has depth %d, node 3 has depth %d, node 9 has depth %d\n", nodeDepth(t, 5), nodeDepth(t, 3), nodeDepth(t, 9));

    printf("Max branch length is %d\n", BSTreeMaxBranchLen(t));

    printf("Tree sum is %d\n", BSTSum(t));

    return EXIT_SUCCESS;
}

Tree createExampleTree(int *nums, int len) {
    Tree t = newTree();
    for (int i = 0; i < len; i++) {
        t = TreeInsert(t, nums[i]);
    }

    return t;
}
