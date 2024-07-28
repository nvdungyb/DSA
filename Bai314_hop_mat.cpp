#include<bits/stdc++.h>
using namespace std;


int n, k, m;
bool visited[1005];
int num[1005];
vector<int> adj[1005];

void dfs(int u)
{
	visited[u] = true;
	num[u]++;
	for(int x : adj[u])
	{
		if(!visited[x])
		{
			dfs(x);
		}
	}
}

int process(int possion[])
{
	for(int i = 1; i <= k; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(possion[i]);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(num[i] == k)
			cnt++;
	}
	
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>k>>n>>m;
	int possion[k+1];
	for(int i = 1; i <= k; i++)
	{
		cin>>possion[i];	
	}
	
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
	
	cout<<process(possion);
	
	
	return 0;
}

// Điểm mà k người có thể đi đến là điểm là mà khi dfs hoặc bfs ở vị trí k người đều đến được.
