#include<bits/stdc++.h>
using namespace std;
 
#define mod 1000000007

long long luyThua(long long a, long long b)
{
	long long res = 1; 
	while(b)
	{
		if(b%2==1)
		{
			res *= a;
			res %= mod;	
		}	
		a *= a;
		a %= mod;
		b /= 2;
	}	
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long a, b;
	cin>>a>>b;
	while(a != 0 || b!= 0)
	{
		cout<<luyThua(a,b);
		cout<<endl;
		cin>>a>>b;
	}
 
	
	return 0;
}