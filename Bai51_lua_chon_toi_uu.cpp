#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int> b)
{
	return a.second < b.second;
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
		pair<int,int>a[n+5];
		int x, y;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i].first>>a[i].second;
		}
		
		sort(a,a+n,cmp);
		
		int l = 0, cnt = 1, cur = 0;
		while(cur < n)
		{
			if(a[cur].first >= a[l].second)
			{
				cnt++;
				l = cur;
			}
			cur++;
		}
		
		cout<<cnt<<endl;
	}


	return 0;
}
