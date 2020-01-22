#include<iostream>
#include<limits.h>
using namespace std;
int max(int a,int b)
{
    return (a>b) ? a:b;
}
// n eggs and k floors
int eggdrop(int n,int k)
{
    int ef[n+1][k+1];
    int res;
    int i,j,x;
    for(i=1;i<=n;i++)
    {
        ef[i][1]=1;
        ef[i][0]=0;
    }
    for(j=1;j<=k;j++)
    ef[1][j]=j;
    for(i=2;i<=n;i++)
    {
        for(j=2;j<=k;j++)
        {
            ef[i][j]=INT_MAX;
            for(x=1;x<=j;x++)
            {
                res=1+max(ef[i-1][x-1],ef[i][j-x]);
                if(res<ef[i][j])
                ef[i][j]=res;
            }
        }
    }
    return ef[n][k];
}
int main()
{
    int n=2,k=6;
    cout<<eggdrop(n,k);
}
