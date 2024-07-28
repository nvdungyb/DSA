#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long luyThua(int n,int k)
{
	long long ans = 1;
	long long a = n, b = k;
	while(b)
	{
		if(b%2 == 1)
		{
			ans *= a;
			ans %= mod;
		}
		b /= 2;
		a *= a;
		a %= mod;
	}	
	return ans;
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
		cout<< luyThua(n,k)<<endl;
	}
 
	
	return 0;
}