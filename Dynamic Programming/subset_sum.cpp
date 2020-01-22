#include<iostream>
using namespace std;
bool issubset(int set[],int n,int sum)
{
    bool subset[n+1][sum+1];
    for(int i=0;i<=sum;i++)
        subset[i][0]=true;
    for(int i=0;i<=n;i++)
        subset[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
          {
             if(j<set[i-1])
                subset[i][j]=subset[i-1][j];
             if(j>=set[i-1])
                subset[i][j]=subset[i-1][j] || subset[i-1][j-set[i-1]];
          }
    }
    return subset[n][sum];
}
int main()
{
    int set[]={1,2,5,7};
    int sum=9;
    int n=sizeof(set)/sizeof(set[0]);
    if(issubset(set,n,sum)==true)
    cout<<"YES";
    else
    cout<<"NO";
}
