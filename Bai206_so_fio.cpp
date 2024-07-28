#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long c[2][2];

void mul(long long a[][2], long long b[][2])
{
	long long x, y, z, k;
	x = ((a[0][0]*b[0][0])%mod + (a[0][1]*b[1][0])%mod)%mod;
	y = ((a[0][0]*b[0][1])%mod + (a[0][1]*b[1][1])%mod)%mod;
	z = ((a[1][0]*b[0][0])%mod + (a[1][1]*b[1][0])%mod)%mod;
	k = ((a[1][0]*b[0][1])%mod + (a[1][1]*b[1][1])%mod)%mod;
	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = k;
}

void dequi(long long a[][2],int n)
{
	if(n == 1)
		return;
	
	dequi(a,n/2);
	mul(a,a);
	if(n%2)
		mul(a,c);
}

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
		long long a[2][2];
		a[0][0] = a[0][1] = a[1][0] = 1;
		a[1][1] = 0;
		
		c[0][0] = c[0][1] = c[1][0] = 1;
		c[1][1] = 0;
		
		dequi(a,n);
		
		cout<<a[1][0]<<endl;
	}


	return 0;
}
