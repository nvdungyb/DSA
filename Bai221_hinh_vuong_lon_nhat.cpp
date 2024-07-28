#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n, m;
		cin>>n>>m;
		int a[n+5][m+5];
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cin>>a[i][j];
		}
		
		int dp[n+5][m+5];
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(a[i][j])
				{
					dp[i][j] = min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1])+1;
				}else{
					dp[i][j] = 0;
				}
			}	
		}	
		
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				ans = max(ans, dp[i][j]);
		}
		
		cout<<ans<<endl;
	}


	return 0;
}
