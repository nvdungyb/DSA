#include<bits/stdc++.h>
using namespace std;

int a[10];

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
		int a[10];
		long long x;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
		{
			cin>>x;
			while(x)
			{
				int ans = x % 10;
				a[ans]++;
				x /= 10;
			}
		}
		
		for(int i = 0; i <= 9; i++)
		{
			if(a[i])	
				cout<<i<<" ";
		}
		cout<<endl;
	}
 
	
	return 0;
}