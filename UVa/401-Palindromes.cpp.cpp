#include <stdio.h>
#include <string.h>

char a[1000009], b[1000009];

int main()
{
    int l, m, i, k, c, f ,p;
    while(gets(a)!=NULL)
    {
        c=0;p=0;f=0;
        l=strlen(a);
        m=l/2;
        for(i=0 ,k=l-1 ; i<=m ; i++, k--)
            if( a[i]==a[k])
                c++;
        for(i=0 ; i<l ; i++) {
            if(a[i]=='A' || a[i]=='H' || a[i]=='M' || a[i]=='O' || a[i]=='T' || a[i]=='U' || a[i]=='V' || a[i]=='W' || a[i]=='X' || a[i]=='Y' || a[i]=='1' || a[i]=='8' || a[i]=='I')
                f++;
        }

        if(f==l && c>m) {
            printf("%s -- is a mirrored palindrome.\n", a);
            f=2;
        }
        else if(f!=l && c>m) {
            printf("%s -- is a regular palindrome.\n", a);
            f=2;
        }
        strcpy(b,a);
        if( f!=2) {
            for(i=0 ; i<l; i ++) {
                if( a[i]=='E') b[i]= '3';
                else if( a[i]=='3') b[i]= 'E';
                else if( a[i]=='J' ) b[i]='L';
                else if( a[i]=='L') b[i]= 'J';
                else if( a[i]=='O') b[i]='0';
                else if( a[i]=='0') b[i]='O';
                else if( a[i]=='S') b[i]='2';
                else if( a[i]=='2') b[i]='S';
                else if( a[i]=='Z') b[i]='5';
                else if( a[i]=='5') b[i]='Z';
            }
            for(i=0, k=l-1 ; i<=m ; i++,k --) {
                if( a[i] != b[k]) break;
            }
            if(i<=m) printf("%s -- is not a palindrome.\n", a);
            else printf("%s -- is a mirrored string.\n", a);
        }
        printf("\n");
    }
    return 0;
}
