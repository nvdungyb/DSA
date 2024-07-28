#include <bits/stdc++.h>
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
		vector<int> adj[n+5];
		for(int i = 1; i < n; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		
		queue<pair<int,int>> que;
		que.push({1,0});
		int height = 0;
		while(!que.empty())
		{
			pair<int,int> ans = que.front(); 
			que.pop();
			height = max(height, ans.second);
			for(int x : adj[ans.first])
			{
				que.push({x,ans.second+1});
			}
		}
		
		cout<<height<<endl;
	}
	
	
	return 0;
}
