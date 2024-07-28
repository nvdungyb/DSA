#include<bits/stdc++.h>
using namespace std;


vector<int> adj[1005];
int id[1005], low[1005], v, e, cnt;
vector<pair<int,int>> result;

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	
	for(int v : adj[u])
	{
		if(v == p)	
			continue;
		if(id[v]){
			low[u] = min(low[u], id[v]);
		}else{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			
			if(low[v] == id[v]){
				if(v > u)
					result.push_back({u,v});
				else
					result.push_back({v,u});
			}
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
		for(int i = 1; i <= v; i++)
		{
			adj[i].clear();
			id[i] = 0, low[i] = i;
		}
		
		for(int i = 1; i <= e; i++){
			int x, y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		cnt = 0;
		result.clear();
		for(int i = 1; i <= v; i++)
		{
			if(!id[i])
				dfs(i,0);
		}
		
		sort(result.begin(), result.end());
		for(pair<int,int> x : result)
			cout<<x.first<<" "<<x.second<<" ";
		
		cout<<endl;
	}


	return 0;
}
