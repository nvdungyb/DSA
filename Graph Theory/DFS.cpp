#include<bits/stdc++.h>
using namespace std;


bool visited[1005];

void dfs(vector<int>adj[],int u)
{
	cout<<u<<" ";
	visited[u]=true;
	for(int x:adj[u])
	{
		if(!visited[x])
		{
			dfs(adj,x);
		}
	}
}

int main()
{
	int t,v,e,u;
	t = 1;
	while(t--)
	{
		cin>>v>>e;
		vector<int>adj[v+5];
		int x,y;
		for(int i=1; i<=e; i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		u = 1;
		memset(visited,false,sizeof(visited));
		dfs(adj,u);
		cout<<endl;
	}
	
	
	return 0;
}