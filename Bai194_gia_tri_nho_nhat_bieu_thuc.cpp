#include<bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b)
{
	return a > b;
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
		long long a[n+5], b[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < n; i++)
			cin>>b[i];
		
		sort(a,a+n);
		sort(b,b+n,cmp);
		
		long long sum = 0;
		for(int i = 0; i < n; i++)
		{
			sum += (a[i]*b[i]);
		}
		cout<<sum<<endl;
	}


	return 0;
}
