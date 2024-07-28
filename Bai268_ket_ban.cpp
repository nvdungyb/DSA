#include<bits/stdc++.h>
using namespace std;

int v, e, cnt;
bool visited[100005];

void dfs(set<int> adj[], int u)
{
	visited[u] = true;
	for(int i : adj[u])
	{
		if(!visited[i])
		{
			cnt++;
			dfs(adj,i);
		}
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
		cin>>v>>e;
		set<int> adj[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			adj[x].insert(y);
			adj[y].insert(x);
		}
		
		memset(visited, false, sizeof(visited));
		int max = 1;
		for(int i = 1; i <= v; i++)
		{
			cnt = 1;
			if(!visited[i])
				dfs(adj,i);
			if(cnt > max)
				max = cnt;
		}
		
		cout<<max<<endl;
	}


	return 0;
}
