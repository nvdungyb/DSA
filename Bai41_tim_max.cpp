#include<bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
 
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
		
		sort(a,a+n);
		
		long long ans = 0;
		for(int i = 0; i < n; i++)
		{
			ans += a[i]*i;
			ans %= mod;	
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}