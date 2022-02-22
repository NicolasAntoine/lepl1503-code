#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

int eq(int integer1, int integer2){
    if (integer1 == integer2){
        return 0;
    } else {
        return 1;
    }
}

int ge(int integer1, int integer2){
    if (integer1 >= integer2){
        return 0;
    } else {
        return 1;
    }
}

int gt(int integer1, int integer2){
    if (integer1 > integer2){
        return 0;
    } else {
        return 1;
    }
}

int le(int integer1, int integer2){
    if (integer1 <= integer2){
        return 0;
    } else {
        return 1;
    }
}

int lt(int integer1, int integer2){
    if (integer1 < integer2){
        return 0;
    } else {
        return 1;
    }
}

int ne(int integer1, int integer2){
    if (integer1 != integer2){
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char const *argv[])
{
    int first = atoi(argv[1]);
    int second = atoi(argv[3]);
    if (strcasecmp("-eq", argv[2]) == 0){
        return eq(first, second);
    } 
    if (strcasecmp("-ge", argv[2]) == 0){
        return ge(first, second);
    } 
    if (strcasecmp("-gt", argv[2]) == 0){
        return gt(first, second);
    } 
    if (strcasecmp("-le", argv[2]) == 0){
        return le(first, second);
    } 
    if (strcasecmp("-lt", argv[2]) == 0){
        return lt(first, second);
    } 
    if (strcasecmp("-ne", argv[2]) == 0){
        return ne(first, second);
    } 
    return 0;
}
