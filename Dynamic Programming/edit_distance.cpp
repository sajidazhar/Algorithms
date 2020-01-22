#include<iostream>
#include<string.h>
using namespace std;
int min(int a,int b,int c)
{
    return min(min(a,b),c);
}
int editdistance(string str1,string str2,int m,int n)
{
    int dp[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0)
            dp[i][j]=j;
            else if(j==0)
            dp[i][j]=i;
            else if(str1[i-1]==str2[j-1])
            dp[i][j]=dp[i-1][j-1];
            else
            dp[i][j]=1+min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string str1="sunday";
    string str2="saturday";
    cout<<editdistance(str1,str2,str1.length(),str2.length());
    return 0;
}
