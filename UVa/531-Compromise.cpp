#include <stdio.h>
#include <string.h>

int n, m, g[105][100], p[105][100];
char a[105][100], b[105][100], q[105][100];

void lcs()
{
    int i, j;
    for(i=0 ; i<=n ; i++) {
        g[i][0]=0;
        p[i][0]=0;
    }
    for(i=0 ; i<=m ; i++) {
        g[0][i]=0;
        p[0][i]=0;
    }
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=m ; j++) {
            if( strcmp(a[i-1], b[j-1])==0) {
                g[i][j]= g[i-1][j-1]+1;
                p[i][j]= 2;
            }
            else {
                if(g[i-1][j]>g[i][j-1]) {
                    g[i][j]= g[i-1][j];
                    p[i][j]=3;
                }
                else {
                    g[i][j]= g[i][j-1];
                    p[i][j] = 1;
                }
            }
        }
    }
}

int main()
{
    int i, j, k=0;

	while ( true ) {

		if ( scanf("%s", &a[0]) == EOF ) break;
		//if ( a[0][0] == '#' ) break;
		n = 1;
		while(scanf("%s", &a[n]))
		{
			if(a[n][0]=='#') break;
			n++;
		}
		m = 0;
		while(scanf("%s", &b[m]))
		{
			if(b[m][0]=='#') break;
			m++;
		}
		lcs();

		//printf("%d %d\n", n,m);
		/*for(i=0 ; i<=n ; i++){
        for(j=0 ; j<=m ; j++) printf("%d ", p[i][j]);
		printf("\n");}
		*/
		i=n;j=m;k=0;
		while(1) {
			if( p[i][j]==2) {
				strcpy( q[k++], a[i-1]);
				i--;
				j--;
			}
			else if( p[i][j]==1) {
				j--;
			}
			else
				i--;
			if(i==0 || j==0) break;
		}
		for(i=k-1 ; i>=0 ; i--) {
			if(i==k-1) printf("%s", q[i]);
			else
				printf(" %s", q[i]);
		}
		printf("\n");
	}
    return 0;
}
