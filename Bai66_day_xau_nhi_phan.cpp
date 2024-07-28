#include<bits/stdc++.h>
using namespace std;
 

long long dp[93];

char find(int n, long long k)
{
	if(n == 1)
		return '0';
	if(n == 2)
		return '1';
	if(k >= dp[n-2])	
		return find(n-1,k-dp[n-2]);
	else
		return find(n-2,k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	dp[1] = 1, dp[2] = 1;
	for(int i = 3; i < 93; i++)
	{
		dp[i] = dp[i-2] + dp[i-1];
	}
	
	int t, n;
	long long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<find(n,k);
		cout<<endl;
	}
	
	
	return 0;
}