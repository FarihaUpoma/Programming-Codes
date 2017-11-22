#include <stdio.h>
#include <string.h>

int main()
{
    int i=1;
    char a[100];
    while(scanf("%s", a)!= EOF)
    {
        if(a[0] == '*') break;
        else {
            if( a[0] == 'H' )
                printf("Case %d: Hajj-e-Akbar\n", i);
            else
                printf("Case %d: Hajj-e-Asghar\n",i);
            i++;
        }
    }
    return 0;
}
