#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5], b[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int j = 0; j < n-1; j++)
			cin>>b[j];
		
		int i = n-1;
		while(a[i] == b[i-1])
		{
			i--;
		}
		cout<<i+1;
		cout<<endl;
	}
 
	
	return 0;
}