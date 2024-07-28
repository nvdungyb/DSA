#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x;
	cin>>n;
	int a[n+5];
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
		ans = max(ans,a[i]);
	}
	
	int b[ans];
	memset(b, 1,sizeof(b));
	for(int i = 0; i < n; i++)
	{
		if(b[a[i]])
		{
			cout<<a[i]<<" ";
			b[a[i]] = 0;
		}
	}	
	
	
	return 0;
}