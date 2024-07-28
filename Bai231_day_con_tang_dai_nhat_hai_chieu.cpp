#include<bits/stdc++.h>
using namespace std;
 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	pair<int,int> a[n+5];
	for(int i = 0; i < n; i++)
		cin>>a[i].first>>a[i].second;
	
	int dp[n+5];
	for(int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if(a[i].first > a[j].first && a[i].second > a[j].second)
				dp[i] = max(dp[i],dp[j]+1);
		}
	}
	
	int resul = 1;
	for(int i = 0; i < n; i++)
		resul = max(resul,dp[i]);
	
	cout<<resul;
	

	return 0;
}
