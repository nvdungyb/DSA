#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int n;

void multiphy(long long a[][3], long long b[][3])
{
	long long x, y, z, k;
	x = ((b[0][0]*a[0][0])%mod + (b[0][1]*a[1][0])%mod)%mod;
	y = ((b[0][0]*a[0][1])%mod + (b[0][1]*a[1][1])%mod)%mod;
	z = ((b[1][0]*a[0][0])%mod + (b[1][1]*a[1][0])%mod)%mod;
	k = ((b[1][0]*a[0][1])%mod + (b[1][1]*a[1][1])%mod)%mod;
	
	b[0][0] = x;
	b[0][1] = y;
	b[1][0] = z;
	b[1][1] = k;
	
}

long long process(long long a[][3])
{
	int ans = n;
	long long b[3][3];
	b[0][0] = b[0][1] = b[1][0] = 1; b[1][1] = 0;
	
	while(ans)
	{
		if(ans%2)
		{
			multiphy(a,b);
		}
		ans /= 2;
		multiphy(a,a);
	}

	return b[1][1];		
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long a[3][3];
		a[0][0] = a[0][1] = a[1][0] = 1; a[1][1] = 0;
		
		long long resul = process(a);
		
		cout<<resul<<endl;
	}


	return 0;
}

/*							 n 
	ma trận đơn vị: 	1  1	F(n+1)  F(n)	 
						1  0	F(n)  F(n-1)
*/

