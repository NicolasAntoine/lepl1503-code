#include <string.h>
#include <stdio.h>
/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
    int pal(char *str) {
    if (str == NULL){
        return -1;
    }
    int start = 0;
    int end = strlen(str)-1;

    while (start <= end){
        while (str[start] == ' ' && start < end){
            start++;
        }
        while (str[end] == ' ' && end > start){
            end--;
        }
        if (str[start] != str[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}


int main(int argc, char const *argv[])
{
    printf("%d\n", pal("a man a plan a canal panama"));
    return 0;
}
