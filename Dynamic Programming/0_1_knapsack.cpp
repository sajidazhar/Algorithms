#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int w,int wt[],int val[],int n)
{
    if(n==0 || w==0) //wt or size is zero
    return 0;
    if(wt[n-1]>w) //if wt is larger than bag capacity
    return knapsack(w,wt,val,n-1);
    else
     return max(val[n-1]+knapsack(w-wt[n-1],wt,val,n-1),knapsack(w,wt,val,n-1));
}
int main()
{
    int wt[]={2,3,4,5};
    int val[]={1,2,5,6};
    int w=8;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<"maximum profit is "<<knapsack(w,wt,val,n);
    return 0;
}
