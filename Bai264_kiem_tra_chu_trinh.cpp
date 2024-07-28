#include<bits/stdc++.h>
using namespace std;

int v, e;
bool visited[1005];
int parent[1005];

bool dfs(vector<int> adj[], int u)
{
	visited[u] = true;
	for(int x:adj[u])
	{
		if(!visited[x])
		{
			parent[x] = u;
			if(dfs(adj,x))
				return true;		
		}else{
			if(x != parent[u])
				return true;
		}
	}
	return false;
}

bool check(vector<int> adj[])
{
	for(int i = 1; i <= v; i++)
	{
		if(!visited[i])
		{
			if(dfs(adj,i))
				return true;	
		}
	}
	return false;
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
		cin>>v>>e;
		vector<int> adj[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		memset(visited, false, sizeof(visited));
		
		if(check(adj))
			cout<<"YES";
		else
			cout<<"NO";
		
		cout<<endl;
	}


	return 0;
}
