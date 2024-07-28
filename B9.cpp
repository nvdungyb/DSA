#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		for(int i = k; i < n; i++)
			cout<<a[i]<<" ";
		for(int i = 0; i < k; i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	
		
	return 0;
}