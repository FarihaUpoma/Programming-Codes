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

struct node {
    int a;
    int freq;
    node *right;
    node *left;
};

struct node *arr[28];

void ini()
{
    int i;
    for(i=0 ; i<28 ; i++) {
        arr[i]= new node();
        arr[i]->a= i;
        arr[i]->freq= 0;
        arr[i]->right= arr[i]->left= NULL;
    }
}

void huffman()
{
    int i, min1, min2, indx, indy, k=127, j;
    node *tmp , *temp;
    for(j=0 ; j<27 ; j++) {
        min1= 1000009; min2= 1000009;
        for(i=0 ; i<28 ; i++) {
            if(arr[i]->freq < min1 && arr[i]->freq>-1) {
                min1= arr[i]->freq;
                indx= i;
            }
        }
        for(i=0 ; i<28 ; i++) {
            if(arr[i]->freq < min2 && arr[i]->freq >-1 && i!=indx) {
                min2= arr[i]->freq;
                indy= i;
            }
        }
        /*for( i=0 ; i<28 ; i++) {
            if(arr[i]->freq !=-1)
                printf("%d ", arr[i]->freq);
        }printf("\n");
        printf("\n%c-> %d , %c-> %d\n\n", arr[indx]->a+97 , min1 , arr[indy]->a+97 , min2);
*/
        tmp = new node();
        tmp->a = arr[indy]->a;
        tmp->freq= arr[indy]->freq;
        tmp->right = tmp->left = NULL;

        arr[indx]->freq= -1;
        arr[indy]->a = k++;
        arr[indy]->freq = min1 + min2;
        arr[indy]->right = arr[indx];
        arr[indy]->left = tmp;
        //printf("min1=%d min2=%d arr[indy]->freq=%d\n", min1, min2, arr[indy]->freq);
    }
}

int p=0;
char s[1000];

void print(node *current)
{
    if( current->left!= NULL) {
        s[p++] = '0';
        print(current->left);
    }

    if(current->right!= NULL) {
        s[p++] ='1';
        print(current->right);
    }
    printf("%c->%s\n", current->a+97 , s);
    p=0;
}

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    int i, max=0, ind;
    char ch;
    ini();
    while( (ch=fgetc(fp)) != EOF) {

        if( ch==' ') arr[26]->freq++;
        else if( ch=='\n') arr[27]->freq++;
        else arr[ch-97]->freq++;
    }
    int tot=0;
    for(i=0 ; i<28 ; i++) {
        tot += arr[i]->freq;
        //printf("%c -> %d\n",arr[i]->a+97, arr[i]->freq);
    }
    printf("total freq = %d\n", tot);
    huffman();
    for( i=0 ; i<28 ; i++) {
        //printf("%d ", arr[i]->freq);
        if(arr[i]->freq > max) {
            max= arr[i]->freq;
            ind= i;
        }
    }
    //printf("\nmax=%d arr[ind]->freq=%d arr[ind]->right->freq=%d arr[ind]->left->freq=%d\n", max,arr[ind]->freq, arr[ind]->right->freq , arr[ind]->left->freq);
    //print(arr[ind]);
    return 0;
}
