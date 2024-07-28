#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int n;

long long M[15][15], b[15][15];

void mul(long long a[][15],long long M[][15])
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			long long x = 0;
			for(int k = 1; k <= n; k++)
			{
				x += (a[i][k]*M[k][j])%mod;
				x %= mod;
			}
			b[i][j] = x;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			a[i][j] = b[i][j];
	}
	
}

long long sum(long long a[][15])
{
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += a[i][n];
		ans %= mod;
	}
	return ans;
}

void process(long long a[][15], long long k)
{
	if(k <= 1)
		return;
		
	process(a,k/2);		
	mul(a,a);
	
	if(k%2 == 1)
		mul(a,M);	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	long long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long a[15][15];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin>>a[i][j];
				M[i][j] = a[i][j];
			}
		}
		
		process(a,k);
		long long ans = sum(a);
		
		cout<<ans<<endl;
	}


	return 0;
}
