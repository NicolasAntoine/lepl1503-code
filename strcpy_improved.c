#include <stdio.h>
#include <string.h>

/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src) {
    if (src == NULL){
        return NULL;
    }
    char *dest = (char *) malloc(strlen(src)*sizeof(char));
    if (dest == NULL){
        return NULL;
    }
    for (int i = 0; i<strlen(src); i++){
        dest[i] = src[i];
    }
    dest[strlen(src)] = '\0';
    return dest;
}

int main(int argc, char const *argv[])
{
    /* code */
    char* chaine[20];
    printf("%s\n", strcpy(chaine, "Bonjour"));
    printf("%s\n", buf_strcpy("Cacahuètesbnbnbnbnbnbnbnbnbnbnbnb"));
}
