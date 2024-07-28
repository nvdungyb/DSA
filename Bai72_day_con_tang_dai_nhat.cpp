#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 1, n;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i]; 
		
		int dp[n];
		for(int i = 0; i < n; i++)
		{
			dp[i] = 1;
			for(int j = 0; j < i; j++)
			{
				if(a[i] > a[j])
					dp[i] = max(dp[i],dp[j]+1);
			}
		}
		
		int ans = 1;
		for(int i = 0; i < n; i++)
			ans = max(ans,dp[i]);
		cout<<ans;
			
		cout<<endl;
	}
 
	
	return 0;
}