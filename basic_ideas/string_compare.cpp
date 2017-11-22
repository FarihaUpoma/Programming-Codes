#include <stdio.h>
#include <string.h>



int main()
{
    char a[230], b[200];
    strcpy(a, "1111111");
    strcpy(b, "5");
    printf("%d %d", strcmp(a, b), strcmp(b, a));
    return 0;
}
