#include<iostream>
using namespace std;
int max(int a,int b)
{
    return (a>b) ? a:b;
}
int min(int a,int b)
{
    return (a<b) ? a:b;
}
int optimal(int* arr,int n)
{
    int tb[n][n];
    for(int gap=0;gap<n;++gap)
    {
        for(int i=0,j=gap;j<n;++i,++j)
        {
            int x=((i+2)<=j)?tb[i+2][j]:0;
            int y=((i+1)<=(j-1))?tb[i+1][j-1]:0;
            int z=(i<=(j-2))?tb[i][j-2]:0;
            tb[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
        }
    }
    return tb[0][n-1];
}
int main()
{
    int arr1[]={3,9,1,2};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    cout<<optimal(arr1,n);
}
