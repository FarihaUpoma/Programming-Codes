#include <stdio.h>
#include <string.h>

int g[101][101];

int main()
{
	int i, j, k, n, a, b;
	//freopen("in.txt", "r", stdin);
	while ( scanf("%d", &n) && n)
	{
		memset(g, 0, sizeof(g));
		while ( scanf("%d", &a) && a ) {
			while ( scanf("%d", &b) && b ) {
				g[a][b] = 1;
			}
		}
		for ( k = 1; k <= n; k ++ ) for ( i = 1; i <= n;i ++ ) for ( j = 1; j <= n; j ++ )
		{
			if ( g[i][k] && g[k][j] ) g[i][j] = 1;
		}
		scanf("%d", &a);
		for ( k = 0; k < a; k ++ ) 
		{
			scanf("%d", &b);
			for ( i = 0, j = 1; j <= n; j ++ ) if ( !g[b][j] ) i ++ ;
			printf("%d", i);
			for ( j = 1; j <= n; j ++ ) if ( !g[b][j] ) printf(" %d", j);
			printf("\n");
		}
	}
	return 0;
}