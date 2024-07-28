#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	int t;
	ll n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int cnt = 0;
		for(ll i=1;i*i <= n; i++)
		{
			if(n%i==0)
			{
				if(i%2==0)
				{
					cnt++;
					if(i*i==n)
						cnt--;
				}
				if((n/i)%2==0)
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	
	return 0;
}