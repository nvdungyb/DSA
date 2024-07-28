#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
using ll = long long long;
ll b[205][205];
ll to_hop(int n,int m)
{
	if(n == m || n == 0)
	{
		b[n][m] = 1;
		return b[n][m];
	}
	if(b[n][m])
		return b[n][m];
	b[n][m] = (to_hop(n-1,m-1)%mod + to_hop(n,m-1)%mod)%mod;
	return b[n][m];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll ans = to_hop(n,n+m);
		cout<<ans<<endl;
	}
	
	
	return 0;
}