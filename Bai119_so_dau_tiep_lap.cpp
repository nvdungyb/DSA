#include<bits/stdc++.h>
using namespace std;


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
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		map<int,int>mp;
		int check = 0;
		for(int i = 0; i < n; i++)
		{
			mp[a[i]]++;
		}
		
		for(int i = 0; i < n; i++)
		{
			if(mp[a[i]] > 1)
			{
				cout<<a[i]<<" ";
				check = 1;
				break;
			}
		}
		if(!check)
			cout<<"NO";
		 
		cout<<endl;
	}
 
	
	return 0;
}