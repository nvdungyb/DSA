#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long a[1000005];

long long count(int n, int k)
{
	a[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		a[i] = 0;
		for(int j = 1; j <= k; j++)
		{
			if(i >= j)
				a[i] = (a[i]+a[i-j])%mod;
		}	
	}
	return a[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		
	 	cout<<count(n,k);
	 	cout<<endl;
	}


	return 0;
}
