#include<bits/stdc++.h>
using namespace std;

int a[10000];

void pre()
{
	for(int i = 1; i <= 100; i++)
	{
		a[i*i] = 1;
	}

	int tam = 0;
	for(int i = 1; i <= 10000; i++)
	{
		if(a[i] == 0)
		{
			a[i] = INT_MAX;
			for(int j = 1; j <= i; j++)
			{
				if(a[j] == 1)
				{
					a[i] = min(a[i],a[i-j]+1);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	pre();
		
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<a[n]<<endl;
	}
	

	return 0;
}