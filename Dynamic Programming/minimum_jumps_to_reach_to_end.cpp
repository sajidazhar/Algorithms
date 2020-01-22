#include<iostream>
#include<limits.h>
using namespace std;
int min(int x, int y) 
{
    return (x < y) ? x : y;
}
int minjumps(int arr[],int n)
{
    int* jumps=new int[n];
    int i,j;
    if(n==0 || arr[0]==0)
    return INT_MAX;
    jumps[0]=0;
    for(i=1;i<n;i++)
    {
        jumps[i]=INT_MAX;
        for(j=0;j<i;j++)
        {
            if(i<=j+arr[j] && jumps[j]!=INT_MAX)
            {
                jumps[i]=min(jumps[i],jumps[j]+1);
                break;
            }
        }
    }
    return jumps[n-1];
}
int main()
{
    int arr[]={ 1, 3, 6, 1, 0, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minjumps(arr,n);
    return 0;
}
