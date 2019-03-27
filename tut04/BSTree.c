// Binary Search Tree ADT implementation ... 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BSTree.h"

#define data(tree)  ((tree)->data)
#define left(tree)  ((tree)->left)
#define right(tree) ((tree)->right)

typedef struct Node {
   int  data;
   Tree left, right;
} Node;

Tree newNode(Item it);
void showTreeR(Tree t, int depth);
Tree joinTrees(Tree t1, Tree t2);
int max(int a, int b);

// make a new node containing data
Tree newNode(Item it) {
   Tree new = malloc(sizeof(Node));
   assert(new != NULL);
   data(new) = it;
   left(new) = right(new) = NULL;
   return new;
}

// create a new empty Tree
Tree newTree() {
   return NULL;
}

// free memory associated with Tree
void freeTree(Tree t) {
   if (t != NULL) {
      freeTree(left(t));
      freeTree(right(t));
      free(t);
   }
}

// display Tree sideways
void showTreeR(Tree t, int depth) {
   if (t != NULL) {
      showTreeR(right(t), depth+1);
      int i;
      for (i = 0; i < depth; i++)
	 putchar('\t');            // TAB character
      printf("%d\n", data(t));
      showTreeR(left(t), depth+1);
   }
}

void showTree(Tree t) {
   showTreeR(t, 0);
}

// compute height of Tree
int TreeHeight(Tree t) {
    (void) t;

   // not yet implemented

   return -1;
}

// count #nodes in Tree
int TreeNumNodes(Tree t) {
   if (t == NULL)
      return 0;
   else
      return 1 + TreeNumNodes(left(t)) + TreeNumNodes(right(t));
}

// check whether a key is in a Tree
bool TreeSearch(Tree t, Item it) {
   if (t == NULL)
      return false;
   else if (it < data(t))
      return TreeSearch(left(t), it);
   else if (it > data(t))
      return TreeSearch(right(t), it);
   else                                 // it == data(t)
      return true;
}

// insert a new item into a Tree
Tree TreeInsert(Tree t, Item it) {
   if (t == NULL)
      t = newNode(it);
   else if (it < data(t))
      left(t) = TreeInsert(left(t), it);
   else if (it > data(t))
      right(t) = TreeInsert(right(t), it);
   return t;
}

Tree joinTrees(Tree t1, Tree t2) {
   if (t1 == NULL)
      return t1;
   else if (t2 == NULL)
      return t2;
   else {
      Tree curr = t2;
      Tree parent = NULL;
      while (left(curr) != NULL) {    // find min element in t2
	 parent = curr;
	 curr = left(curr);
      }
      if (parent != NULL) {
	 left(parent) = right(curr);  // unlink min element from parent
	 right(curr) = t2;
      }
      left(curr) = t1;
      return curr;                    // min element is new root
   }
}

// delete an item from a Tree
Tree TreeDelete(Tree t, Item it) {
   if (t != NULL) {
      if (it < data(t))
	 left(t) = TreeDelete(left(t), it);
      else if (it > data(t))
	 right(t) = TreeDelete(right(t), it);
      else {
	 Tree new;
	 if (left(t) == NULL && right(t) == NULL) 
	    new = NULL;
	 else if (left(t) == NULL)    // if only right subtree, make it the new root
	    new = right(t);
	 else if (right(t) == NULL)   // if only left subtree, make it the new root
	    new = left(t);
	 else                         // left(t) != NULL and right(t) != NULL
	    new = joinTrees(left(t), right(t));
	 free(t);
	 t = new;
      }
   }
   return t;
}

Tree rotateRight(Tree n1) {
   if (n1 == NULL || left(n1) == NULL)
      return n1;
   Tree n2 = left(n1);
   left(n1) = right(n2);
   right(n2) = n1;
   return n2;
}

Tree rotateLeft(Tree n2) {
   if (n2 == NULL || right(n2) == NULL)
      return n2;
   Tree n1 = right(n2);
   right(n2) = left(n1);
   left(n1) = n2;
   return n1;
}

Tree insertAtRoot(Tree t, Item it) {
    (void) t;
    (void) it;

   printf("Not yet implemented.\n");

   return t;
}

Tree partition(Tree t, int i) {
   if (t != NULL) {
      assert(0 <= i && i < TreeNumNodes(t));
      int m = TreeNumNodes(left(t));
      if (i < m) {
	 left(t) = partition(left(t), i);
	 t = rotateRight(t);
      } else if (i > m) {
	 right(t) = partition(right(t), i-m-1);
	 t = rotateLeft(t);
      }
   }
   return t;
}

Tree rebalance(Tree t) {
   int n = TreeNumNodes(t);
   if (n >= 3) {
      t = partition(t, n/2);           // put node with median key at root
      left(t) = rebalance(left(t));    // then rebalance each subtree
      right(t) = rebalance(right(t));
   }
   return t;
}

int countInternal(Tree t) {
    if (t == NULL) {
        return 0;
    }

    if (left(t) == NULL && right(t) == NULL) {
        return 0;
    }

    int leftInternal = countInternal(left(t));

    int rightInternal = countInternal(right(t));

    return leftInternal + rightInternal + 1;
}

int nodeDepth(Tree t, int key) {
    if (t == NULL) {
        return -1;
    }

    int curr = data(t);
    if (curr == key) {
        return 0;
    } else if (curr > key) {
        int leftDepth = nodeDepth(left(t), key);

        if (leftDepth != -1) {
            return leftDepth + 1;
        } else {
            return -1;
        }
    } else { // curr < key
        int depth = nodeDepth(right(t), key);

        if (depth != -1) {
            return depth + 1;
        } else {
            return -1;
        }
    }
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int BSTreeMaxBranchLen(Tree t) {
    if (t == NULL) {
        return 0;
    }

    if (left(t) == NULL && right(t) == NULL) {
        return 0;
    } else {
        int leftLen = BSTreeMaxBranchLen(left(t));
        int rightLen = BSTreeMaxBranchLen(right(t));

        return max(leftLen, rightLen) + 1;
    }
}

int BSTSum(Tree t) {
    if (t == NULL) {
        return 0;
    } else {
        return data(t) + BSTSum(left(t)) + BSTSum(right(t));
    }
}

int printHeightDiff(Tree t) {
    if (t == NULL) {
        printf("empty tree, height difference 0\n");
        return -1;
    }

    if (t->left == NULL && t->right == NULL) {
        printf("data: %d, height diff: %d\n", t->data, 0);
        return 0;
    }

    int leftHeight = printHeightDiff(t->left);
    int rightHeight = printHeightDiff(t->right);

    int diff = leftHeight - rightHeight;
    printf("data: %d, height diff: %d\n", t->data, diff);

    return max(leftHeight, rightHeight) + 1;
}

int isAVL(Tree t) {
    if (t == NULL) {
        return 0;
    }

    if (t->left == NULL && t->right == NULL) {
        return 0;
    }

    int leftHeight = isAVL(t->left);
    int rightHeight = isAVL(t->right);

    if (leftHeight == -1 || rightHeight == -1) {
        return -1;
    } else if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return max(leftHeight, rightHeight) + 1;
}
