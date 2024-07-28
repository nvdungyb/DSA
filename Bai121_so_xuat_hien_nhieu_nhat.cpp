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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		map<int,int> mp;
		for(int i = 0; i < n; i++)
			mp[a[i]]++;
		
		int ans = 0, tmp;
		for(auto x:mp)
		{
			if(ans < x.second)
			{
				ans = x.second;
				tmp = x.first;	
			}	
		}
		if(ans > floor(n/2))
			cout<<tmp;
		else
			cout<<"NO";
			
		cout<<endl;
	}
 
	
	return 0;
}