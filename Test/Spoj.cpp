#include<bits/stdc++.h>
using namespace std;


#define maxn 10005

int v, e,
	low[maxn],
	id[maxn],
	bridge = 0,
	articulation_point = 0,
	cnt = 0;
vector<int>adj[maxn];
	
void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	int node = (p != 0);			// đỉnh gốc 
	
	for(int v : adj[u])
	{
		if(v == p)
			continue;
		if(id[v])
			low[u] = min(low[u],id[v]);
		else{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			
			if(low[v] == id[v])		// từ v không có đường tới tổ tiên.
				bridge++;
			if(low[v] >= id[u])		// từ v không có đường tới cha của u.
				node++;
		}
	}
	
	if(node >= 2)
		cout<<u<<" ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>v>>e;
	for(int i = 1; i <= v; i++)
	{
		adj[i].clear();
		low[i] = 0;
		id[i] = 0;
	}
	
	for(int i = 1; i <= e; i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	bridge = 0, articulation_point = 0, cnt = 0;
	for(int i = 1; i <= v; i++)
	{
		if(!id[i])
			dfs(i,0);
	}


	return 0;
}
