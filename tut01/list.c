#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
        int value;
        struct _Node *next;
} Node;

typedef Node *List;  // pointer to first Node

List newList(int value);
void append(List oldList, int value);
int sumList(List l);
void freeList(List l);

int main() {
    List l = newList(7);
    assert(l != NULL);

    append(l, 3);
    append(l, 6);
    append(l, 10);
    append(l, 4);

    int sum = sumList(l);
    printf("The sum of the list is %d\n", sum);
    freeList(l);
}

List newList(int value) {
    List l = malloc(sizeof(Node));
    assert(l != NULL);
    l->value = value;
    l->next = NULL;
    return l;
}

void append(List oldList, int value) {
    assert(oldList != NULL);
    List curr = oldList;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    List new = newList(value);
    curr->next = new;
}

int sumList(List l) {
    if (l == NULL) {
        return 0;
    } else {
        return l->value + sumList(l->next);
    }
}

void freeList(List l) {
    if (l == NULL) {
        return;
    }
    List next = l->next;
    free(l);
    freeList(next);
}

