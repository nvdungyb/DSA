#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;

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
		ll a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		 
		int ans = 0;
		for(int i = 0; i < n-1; i++)
		{
			if(a[i] > a[i+1])
			{
				ans = i+1;
				break;
			}
		}
		cout<<ans <<endl;
	}
 
	
	return 0;
}