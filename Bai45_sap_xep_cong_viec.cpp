#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int>b)
{
	if(a.second < b.second)
		return true;
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
		pair<int,int> a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i].first;
			
		for(int i = 0; i < n; i++)	
			cin>>a[i].second;
		
		sort(a,a+n,cmp);
		
		int cnt = 1;
		int j = 0;
		for(int i = 1; i < n; i++)
		{
			if(a[j].second <= a[i].first)
			{
				j = i;
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
 
	
	return 0;
}