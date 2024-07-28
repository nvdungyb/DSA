#include<bits/stdc++.h>
using namespace std;

bool visited[1005];

void dfs(vector<int> vt[], int u)
{
	cout<<u<<" ";
	visited[u] = true;
	for(auto x:vt[u])
	{
		if(!visited[x])
			dfs(vt,x);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int v, e, u;
		cin>>v>>e>>u;
		vector<int>vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		
		memset(visited,false,sizeof(visited));
		dfs(vt,u);
		
		cout<<endl;
	}
	
	return 0;
}