#include <stdio.h>
#include <string.h>

int main()
{
    int t, i;
    char a[1000009];
    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        scanf("%s", a);
        if( strlen(a) == 3) {
            if( (a[0]=='o' && a[1]=='n') || (a[0]=='o' && a[2]=='e') || (a[1]=='n' && a[2]=='e') )
                printf("1\n");
            else
                printf("2\n");
        }
        else
            printf("3\n");
    }
    return 0;
}
