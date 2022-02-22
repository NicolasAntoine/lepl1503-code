int main(int argc, char const *argv[])
{
    int * tab = (int*) malloc(sizeof(int)*4);
    tab[0] = 1;
    tab[1] = 2;
    tab[2] = 3;
    tab[4] = '\0';
    printf("%d\n", *tab+2);
    return 0;
}
