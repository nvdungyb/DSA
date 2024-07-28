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
		long long dp1[n+5]={0}, dp2[n+5]={0};
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		for(int i = 1; i < n; i++)
			dp1[i] = dp1[i-1] + a[i-1];
		
		for(int i = n-2; i >= 0; i--)
			dp2[i] = dp2[i+1] + a[i+1];
	
		int check = 1;
		for(int i = 1; i < n-1; i++)
		{
			if(dp1[i] == dp2[i])
			{
				cout<<i+1;
				check = 0;
				break;
			}
		}
		if(check)
			cout<<"-1";
		
		cout<<endl;
	}
 
	
	return 0;
}