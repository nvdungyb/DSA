#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	int n;
	cin>>n;
	ll ans = 1, tong = 0;
	for(int i = 1; i <= n; i++)
	{
		ans *= i;
		tong += ans;
	}
	cout<<tong;
	

	
	return 0;
}