#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		double a[n+5], b[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i]>>b[i];
		
		int dp[n+5];
		for(int i = 1; i <= n; i++)
		{
			dp[i] = 1;
			for(int j = 1; j < i; j++)
			{
				if(a[j] < a[i] && b[j] > b[i])	
				{
					dp[i] = max(dp[i],dp[j]+1);
				}	
			}
		}	
		
		int resul = 1;
		for(int i = 1; i <= n; i++)
			resul = max(resul,dp[i]);
		
		cout<<resul<<endl;
	}


	return 0;
}
