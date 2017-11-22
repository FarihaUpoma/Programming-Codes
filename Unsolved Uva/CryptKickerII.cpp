 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define eps 1e-10
#define PI acos(-1)

int dirx[8]= {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8]= {-1, -1, -1, 0, 0, 1, 1, 1};

int dx[4]= {-1, 0, 1, 0};
int dy[4]= {0, -1, 0, 1};

int min(int x, int y)
{
    if( x<y) return x;
    else return y;
}

int max(int x, int y)
{
    if( x>y) return x;
    else return y;
}

char a[150][200], q[20];
int alph[200];

int main()
{
    //freopen("input.txt", "r", stdin);

    int stl, t, k, f, i, j, indx, c1, c2, p1, p2, l, g, n, m;
    char st[]= "the quick brown fox jumps over the lazy dog";
    stl= strlen(st);
    scanf("%d", &t);
    getchar();
    getchar();
    while(t--) {
        memset(a, 0, sizeof(a));
        k=0;
        /*while(1) {
            gets(a[k++]) ;
            if( strlen(a[k-1] )==0)
                break;
        }*/
        while(gets(a[k++]))
        {
            if(a[k-1][0]=='\0')
            {
                break;
            }
        }
        for(n=0 ; n<k ; n++) {
            f=0;
            if(strlen( a[n] ) == stl) {
                memset(alph, 0, sizeof(alph));
                for(m=0 ; m<stl ; m++) {
                    if( st[m] == ' ' && a[n][m]!= ' ') {
                        break;
                    }
                }
            }
            if(m==stl) {
                f=1;
                indx = n;

                g=0;
                for(j=0 ; j<stl ; j++) {
                    if(j==stl-1)
                        //printf("alph[a[indx][j]]=%c st[j]=%c\n", alph[a[indx][j]], st[j]);
                    if(alph[ a[indx][j] ] !=0 && alph[ a[indx][j] ] != st[j]) {
                        g=1;
                        break;
                    }
                    if(alph[ a[indx][j] ] ==0) alph[ a[indx][j] ] = st[j];
                }
                memset(q, 0, sizeof(q));
                for(j=0 ; j<stl ; j++) {
                    q[j] = alph[ a[indx][j] ];
                }
                q[j]=0;
                if( strcmp(q, st)!=0) g=1;
                if(g == 0 ) {
                    for(i=0 ; i<k ; i++) {
                        l= strlen(a[i]);
                        for(j=0 ; j<l ; j++) {
                            if(a[i][j] != ' ')
                                printf("%c", alph[ a[i][j] ]);
                            else printf("%c", a[i][j]);
                        }
                        if(i<k-1) printf("\n");
                    }
                }
            }
            if(f==1 && g==0) break;
        }
        //printf("f=%d g=%d\n", f, g);
        if(f==0 || g==1) {
            printf("No solution.\n");
        }
        /*else {
            g=0;
            for(j=1 ; j<stl ; j++) {
                if(alph[ a[indx][j] ] !=0 && alph[ a[indx][j] ] != st[j]) {
                    f=1;
                    break;
                }
                alph[ a[indx][j] ] = st[j];
            }
            if(f==1) printf("No solution.\n");
            else {
                for(i=0 ; i<k ; i++) {
                    l= strlen(a[i]);
                    for(j=0 ; j<l ; j++) {
                        if(a[i][j] != ' ')
                            printf("%c", alph[ a[i][j] ]);
                        else printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
            }
        }*/
        if(t>0) printf("\n");
    }
    return 0;
}
