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
		
		int dp1[n+5], dp2[n+5];
		dp1[0] = 1;
		for(int i = 1; i < n; i++)
		{
			if(a[i]>a[i-1])
				dp1[i] = dp1[i-1]+1;
			else
				dp1[i] = 1;
		}	
		
		dp2[n-1] = 1;
		for(int i = n-2; i >= 0; i--)
		{
			if(a[i] > a[i+1])
				dp2[i] = dp2[i+1]+1;
			else
				dp2[i] = 1;
		}
		
		int ans = 1;	
		for(int i = 0; i < n; i++)
		{
			ans = max(ans, dp1[i]+dp2[i]-1);
		}	
		
		cout<<ans;
		cout<<endl;
	}
 
	
	return 0;
}