#include<bits/stdc++.h>
using namespace std;

int a[1000000];
void sieve()
{
	a[1] = 1;
	for(int  i = 2; i <= 1000; i++)
	{
		for(int j = i*i; j <= 1000000; j+=i)
		{
			a[j] = 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	sieve();
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int cnt = 0;
		for(int i = 2; i < n; i++)
		{
			if(!a[i])
			{
				if(!a[n-i])
				{
					cnt = 1;
					cout<<i<<" "<<n-i;
					break;
				}
			}
		}
		if(!cnt)
			cout<<"-1";
			
		cout<<endl;	
	}
 
	
	return 0;
}