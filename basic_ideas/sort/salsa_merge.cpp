#include <cstdio>
#include <iostream>

using namespace std;

void Merge(int left[],int nL,int right[],int nR,int a[])
{
    int i,j,k;
    i=j=k=0;
    while(i<nL && j<nR)
    {
        if(left[i]<=right[j])
            a[k]=left[i++];
        else
            a[k]=right[j++];
        k++;
    }
    while(i<nL)
        a[k++]=left[i++];
    while(j<nR)
        a[k++]=right[j++];
}

void MergeSort(int a[],int n)
{
    if(n<2)
        return;
    int mid=n/2;

    int left[mid],right[n-mid];

    int i,j;

    for(i=0;i<mid;i++)
        left[i]=a[i];

    for(i=mid;i<n;i++)
        right[i-mid]=a[i];

    MergeSort(left,mid);
    MergeSort(right,n-mid);
    Merge(left,mid,right,n-mid,a);
}

int main()
{
    int n,a[100];
    cin>>n;

    for(int i=0;i<n;i++)
        cin>>a[i];

    MergeSort(a,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
