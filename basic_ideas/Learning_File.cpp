#include <stdio.h>

int main()
{
    FILE *fp;
    char a[1000];
    fp= fopen("fariha.txt", "r");
    fgets(fp,a);
    printf("%s\n", a);
    fclose(fp);
    return 0;
}
