#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.second > b.second)
		return true;
	else if (a.second == b.second)
	{
		if(a.first < b.first)
			return true;
	}
	return false;
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
		map<int,int> mp;
		int x;
		for(int i = 0; i < n; i++)
		{
			cin>>x;
			mp[x]++;
		}
		
		int m = mp.size();
		pair<int,int> a[m]; 
		int k = -1;
		for(auto x:mp)
		{
			a[++k] = x;
		}
		
		sort(a,a+m,cmp);
		
		for(auto x:a)
		{
			while(x.second)
			{
				cout<<x.first<<" ";
				x.second--;
			}
		}
		
		cout<<endl;
	}
 
	
	return 0;
}