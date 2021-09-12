#include<bits/stdc++.h>
using namespace std;

int dp[101][1001];

int sol(int a[],int sum,int n)
{
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0) dp[i][j] =0;
			if(j==0) dp[i][j] =1; 
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j-a[i-1]] + dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int sum;
	cin>>sum;
	cout<<sol(a,sum,n)<<endl;
	return 0;
}