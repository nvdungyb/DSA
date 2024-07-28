#include<bits/stdc++.h>
using namespace std;


// Tìm đường đi theo DFS với đồ thị có hướng

bool visited[1005];
int parent[1005];

void dfs(vector<int>adj[],int u)
{
	visited[u]=true;
	for(int x:adj[u])
	{
		if(!visited[x])
		{
			parent[x]=u;
			dfs(adj,x);
		}
	}
}

int main()
{
	int y,v,e,s,t;
	cin>>y;
	while(y--)
	{
		cin>>v>>e>>s>>t;
		vector<int>adj[v+5];
		for(int i=1;i<=e;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		memset(visited,false,sizeof(visited));
		memset(parent,0,sizeof(parent));
		
		dfs(adj,s);
		
		if(!visited[t])
			cout<<"-1";
		else
		{
			vector<int>sul;
			while(t!=s)
			{
				sul.push_back(t);
				t=parent[t];
			}
			sul.push_back(s);
			reverse(sul.begin(),sul.end());
			for(int x:sul)
				cout<<x<<" ";
		}
		cout<<endl;
	}
	
		
	return 0;
}