// swap.c
//
// A program containing a function to swap two elements in an array and demonstrating that it works
// By Alex Rowell z5116848
// Written on 21st Feb 2019

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 5

void print_array(int *arr, int size);
void swap(int arr[], int index1, int index2);

int main() {
    int arr[ARRAY_SIZE] = {0, 1, 2, 3, 4};

    printf("Before swapping: ");
    print_array(arr, ARRAY_SIZE);
    printf("\n");

    swap(arr, 2, 3);
    printf("After swapping: ");
    print_array(arr, ARRAY_SIZE);
    printf("\n");

    return EXIT_SUCCESS;
}


void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d,", arr[i]);
    }

    printf("\n");
}

void swap(int arr[], int index1, int index2) {
    /*
     * int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
    */

    arr[index1] = arr[index1] + arr[index2];
    arr[index2] = arr[index1] - arr[index2];
    arr[index1] = arr[index1] - arr[index2];
}
