#include <stdio.h>
#include <string.h>

char a[1000009];

int main()
{
    int i=1;
    while(scanf("%s", a))
    {
        if( strcmp(a, "#")==0) break;
        else {
            printf("Case %d: ", i);i++;
            if( strcmp(a, "HELLO")==0) printf("ENGLISH\n");
            else if( strcmp(a, "HALLO")==0) printf("GERMAN\n");
            else if( strcmp(a, "CIAO")==0) printf("ITALIAN\n");
            else if( strcmp(a, "BONJOUR")==0) printf("FRENCH\n");
            else if( strcmp(a, "HOLA")==0 ) printf("SPANISH\n");
            else if( strcmp( a, "ZDRAVSTVUJTE")==0) printf("RUSSIAN\n");
            else printf("UNKNOWN\n");
        }
    }
    return 0;
}
