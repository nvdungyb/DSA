#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int a[1005][1005];

int to_Hop(int n,int k)
{
	if(n == k || k == 0)
	{
		a[n][k] = 1;
		return a[n][k];
	}
	if(a[n][k])
		return a[n][k];
	a[n][k] = (to_Hop(n-1,k-1)%mod + to_Hop(n-1,k)%mod)%mod;
	
	return a[n][k];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<to_Hop(n,k);
		cout<<endl;
	}
	
	
	return 0;
}