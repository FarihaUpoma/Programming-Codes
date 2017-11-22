#include <stdio.h>
#include <string.h>

char c[1000009];
int a[1000009], top=0;

int push( int n)
{
    a[top]= n;
    top++;
    return a[top];
}

void pop()
{
    top--;
}

int main()
{
    int f, l, i, k, tst;
    scanf("%d", &tst);
    for(k=0 ; k<tst ; k++) {
        scanf("%s", c);
        l=strlen(c);
        if(c==NULL) printf("No\n");
        else {
            f=0;
            for(i=0 ; i<l ; i++) {
                if(c[i]=='(' ) push(1);
                else if( c[i]==')') push(2);
                else if( c[i]=='[') push(3);
                else if( c[i]==']') push(4);
                if( a[f-1]==1 && a[f]==2) {pop();pop();f=f-2;}
                else if( a[f-1]==3 && a[f]==4) {pop();pop();f=f-2;}

                f++;

                }

            if(f==0) printf("Yes\n");
            else printf("No\n");
            top=0;
        }
    }
    return 0;
}
