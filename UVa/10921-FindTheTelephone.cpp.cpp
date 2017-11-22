#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char a[1000009];
    while(gets(a)!=NULL)
    {
        for(i=0 ; i<strlen(a) ; i++) {
            if( a[i]>64 && a[i]<68) a[i] =2+48;
            else if( a[i]>67 && a[i]<71) a[i] =3+48;
            else if( a[i]>70 && a[i]<74) a[i] =4+48;
            else if( a[i]>73 && a[i]<77) a[i] =5+48;
            else if( a[i]>76 && a[i]<80) a[i] =6+48;
            else if( a[i]>79 && a[i]<84) a[i] =7+48;
            else if( a[i]>83 && a[i]<87) a[i] =8+48;
            else if( a[i]>86 && a[i]<91) a[i] =9+48;
        }
        printf("%s\n", a);
    }
    return 0;
}
