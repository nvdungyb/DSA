#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
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
		int a[n+5];
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		
		sort(a+1,a+n+1,cmp);
		
		 
	}


	return 0;
}
