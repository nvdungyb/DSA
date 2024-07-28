#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, v;
	cin>>t;
	while(t--)
	{
		cin>>n>>v;
		pair<int,int> a[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i].first;
		for(int i = 1; i <= n; i++)
			cin>>a[i].second;
			
		int dp[n+5][v+5];
		memset(dp, 0, sizeof(dp));
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= v; j++)
			{
				dp[i][j] = dp[i-1][j];
				if(j >= a[i].first)
				{
					dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].first]+a[i].second);
				}
			}
		}
		
		cout<<dp[n][v]<<endl;
	}


	return 0;
}

// Giải thích chi tiết tại bài 166.