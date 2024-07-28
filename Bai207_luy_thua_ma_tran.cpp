#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
int n; long long c[15][15];

void mul(long long a[][15], long long b[][15])
{
	long long ans[15][15];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			long long x = 0;
			for(int k = 1; k <= n; k++)
			{
				x = ((x%mod) + (a[i][k]*b[k][j])%mod)%mod;
			}
			ans[i][j] = x;
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			a[i][j] = ans[i][j];
	}
}

void dequi(long long a[][15],int k)
{
	if(k == 1)
		return;
	
	dequi(a,k/2);
	mul(a,a);
	if(k%2)
		mul(a,c);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, k;
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
				c[i][j] = a[i][j];
			}
		}
		
		dequi(a,k);
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}


	return 0;
}
