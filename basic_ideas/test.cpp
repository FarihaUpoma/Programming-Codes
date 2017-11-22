#include <stdio.h>


int max(int a, int b)
{
	if ( a > b ) return a;
	return b;
}

/*void print(int i, int j, int pos ) {

	if ( g[i][j] == 0 ) {
		printf("%s\n", buff);
	}
	else
	{
		if ( a[i-1] == b[j-1] )
		{
			buff[pos] = a[i-1];
			print(i-1,j-1,pos-1);
		}
		else {

			int maxi = max(g[i-1][j] , g[i][j-1]);
			if ( maxi == g[i-1][j] ) print(i-1,j, pos);
			if ( maxi == g[i][j-1]) print(i, j-1, pos);
		}
	}
}*/

int main()
{
    char st[] = "hello world";
    printf("%s\n", st);
	return 0;
}
