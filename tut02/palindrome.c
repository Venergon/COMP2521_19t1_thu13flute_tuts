// palindrome.c
// A program that takes in a single word and checks whether it is a palindrome or not
// By thu13-flute
// 28th Feb 2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE (!FALSE)

int isPalindrome(const char *str);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <word>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (isPalindrome(argv[1])) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return EXIT_SUCCESS;
}

int isPalindrome(const char *str) {
    int length = strlen(str);
    for (int i = 0; i < length/2; i++) {
        if (str[i] != str[length - i - 1]) {
            return FALSE;
        }
    }

    return TRUE;
}
