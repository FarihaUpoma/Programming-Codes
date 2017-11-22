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

struct Node {
    int val;
    Node *next;
};

Node *start, *prev, *later, *now;
int notFound, noPrev, noLater, noElmnt;

void insert(int nodeVal)
{
    Node *tmp, *current;
    tmp= (Node *)malloc(sizeof(Node));
    tmp->val= nodeVal;
    tmp->next=NULL;
    if(start==NULL) {
        start= tmp;
        return ;
    }
    current= start;
    while(current->next!=NULL) current= current->next;
    current->next= tmp;
    return ;
}

void find(int nodeVal)
{
    notFound=0;
    noElmnt=0;
    noLater=0;
    noPrev=0;
    printf("%d ", nodeVal);
    Node *current;
    current= start;
    if(current==NULL) noElmnt=1;
    else {
        while(1) {
            if(current->val==nodeVal) break;
            prev= current;
            if(current->next==NULL) {
                notFound=1;
                return;
                break;
            }
            current= current->next;
        }
        if(current->next==NULL) noLater=1;
        else
            later= current->next;
    }
    if(current==start) {
        prev= start;
        noPrev=1;
    }
    now=current;
    //printf("notFound=%d\n", notFound);
}

void Delete(int nodeVal)
{
    find(nodeVal);
    if(notFound) printf("not found\n", nodeVal);
    else if(noElmnt) printf("no element to delete\n");
    else if(noPrev && noLater) start=NULL;
    else if(noPrev && !noLater) start= later;
    else if(!noPrev && noLater) prev->next= NULL;
    else prev->next= later;
}

Node *tmp1, *tmp2, *tmp3, *tmp4;

void swap(int val1, int val2)
{
    Node *now1, *now2, *prev1, *prev2;
    /*tmp1= (Node *)malloc(sizeof(Node));
    tmp2= (Node *)malloc(sizeof(Node));
    tmp3= (Node *)malloc(sizeof(Node));
    tmp4= (Node *)malloc(sizeof(Node));*/
    find(val1);
    now1= now;
    prev1=prev;
    tmp1= now;
    tmp2= prev2;
    find(val2);
    now2= now;
    prev2=prev;
    tmp3= now;
    tmp4= later;
    prev1->next= tmp3;
    now1->next= tmp4;
    prev2->next= tmp1;
    now2->next= tmp2;
}

void p()
{
    if(start==NULL) printf("no element to print\n");
    else {
        printf("the list:\t");
        Node *current;
        current= start;
        while(1) {
            printf("%d ", current->val);
            if(current->next==NULL) break;
            current= current->next;
        }
        printf("\n");
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    FILE *fp;
    fp = fopen("input.txt", "r");

    int n, x, s, t, i;
    fscanf(fp, "%d", &n);
    for(i=0 ; i<n ; i++) {
        fscanf(fp, "%d", &x);
        fscanf(fp, "%d", &s);
        if(x==1) {
            printf("Inserting %d-\n", s);
            insert(s);
        }
        else if(x==2) {
            printf("Deleting %d-\n", s);
            Delete(s);
        }
        else if(x==3) {
            printf("Searching %d-\n", s);
            find(s);
            if(notFound) printf("%d not found\n");
            else printf("found\n");
        }
        else {
            fscanf(fp, "%d", &t);
            swap(s, t);
        }
        p();
    }
    return 0;
}
