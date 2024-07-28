#include<bits/stdc++.h>
using namespace std;

int v, e;
bool visited[1005];

void dfs(vector<int> adj[], int u)
{
	visited[u] = true;
	for(int x:adj[u])
	{
		if(!visited[x])
			dfs(adj,x);
	}
}

int count(vector<int> adj[])
{
	int cnt = 0;
	for(int i = 1; i <= v; i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(adj,i);
		}
	}
	return cnt;
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
		int num = count(adj);
		
		for(int i = 1; i <= v; i++)
		{
			memset(visited, false, sizeof(visited));
			visited[i] = true;
			int ans = count(adj);
			if(ans != num)
				cout<<i<<" ";
		}
		
		cout<<endl;
	}


	return 0;
}
