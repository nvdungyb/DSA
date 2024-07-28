#include<bits/stdc++.h>
using namespace std;

using ll = long long;

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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		ll ans = a[0],sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum +=a[i];
			if(sum < 0)
				sum = 0;
			ans = max(ans,sum);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}