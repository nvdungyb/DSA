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
		
		int dp[n+5];
		for(int i = 0; i < n; i++)
		{	
			dp[i] = a[i];
			for(int j = 0; j < i; j++)
			{
				if(a[i]>a[j])
					dp[i] = max(dp[i],dp[j]+a[i]);	
			}	
		}	
		
		int ans = dp[0];
		for(int i = 1; i < n; i++)
			ans = max(ans,dp[i]);
			
		cout<<ans<<endl;
	}

	return 0;
}
