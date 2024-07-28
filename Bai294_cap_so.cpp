#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int>b)
{
	return a.second < b.second;
}

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
		pair<int,int> a[n+5];
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i].first>>a[i].second;
		}
		
		sort(a+1,a+n+1,cmp);
		
		int dp[n+5];
		for(int i = 1; i <= n; i++)
		{
			dp[i] = 1;
			for(int j = 1; j < i; j++)
			{
				if(a[j].second < a[i].first)
					dp[i] = max(dp[i],dp[j]+1);
			}
		}

		int resul = 1;
		for(int i = 1; i <= n; i++)
			resul = max(resul,dp[i]);
		
		cout<<resul<<endl;		
	}


	return 0;
}
