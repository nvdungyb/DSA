#include<bits/stdc++.h>
using namespace std;


#define maxn 1005

vector<int> adj[maxn];
bool visited[maxn];
int u,v;

int bfs()
{
	queue<pair<int,int>> que;
	que.push({u,0});
	visited[u] = true;
	while(!que.empty())
	{
		pair<int,int> ans = que.front();
		que.pop();
		for(int x : adj[ans.first])
		{
			if(x == v && !visited[x]){			// Nếu u == v thì return 0;
				return ans.second+1;
			}
				
			if(!visited[x])
			{
				que.push({x,ans.second+1});
				visited[x] = true;
			}
		}
	}
	
	return 0;
}

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
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		
		for(int i = 1; i <= n-1; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);	
		}	
		
		int q;
		cin>>q;
		for(int i = 1; i <= q; i++)
		{
			memset(visited, false, sizeof(visited));
			cin>>u>>v;
			cout<<bfs()<<endl;
		}
	}


	return 0;
}
