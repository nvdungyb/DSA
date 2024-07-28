#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		long long dp[n+5];
		dp[0] = a[0];
		dp[1] = max(a[0],a[1]);
		
		for(int i = 2; i < n; i++)
		{
			dp[i] = max(dp[i-1], a[i]+dp[i-2]);
		}
		cout<<dp[n-1]<<endl;
	}	
	

	return 0;
}