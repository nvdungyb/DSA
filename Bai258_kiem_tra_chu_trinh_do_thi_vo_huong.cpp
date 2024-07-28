#include<bits/stdc++.h>
using namespace std;


int parent[1005], s, t;
bool visited[1005];

bool bfs(vector<int>vt[], int u)
{
	queue<int> que;
	que.push(u);
	visited[u] = true;
	while(!que.empty())
	{
		int v = que.front();
		que.pop();
		for(auto x:vt[v])
		{
			if(!visited[x])
			{
				parent[x] = v;
				visited[x] = true;
				que.push(x);
			}else{
				if(x != parent[v])
					return true;
			}
		}
	}
	return false;
}

bool dfs(vector<int>vt[], int u)
{
	visited[u] = true;
	for(auto x:vt[u])
	{
		if(!visited[x])
		{
			parent[x] = u;
			if(dfs(vt,x))
				return true;
		}else{
			if(x != parent[u])
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

	int v, e, t;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		vector<int> vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}	
		
		memset(parent, 0, sizeof(parent));
		memset(visited, false, sizeof(visited));
		
		int ok = 0;
		for(int i = 1; i <= v; i++)
		{
			if(!visited[i])
			{
				if(dfs(vt,i))
				{
					ok = 1;
					cout<<"YES";
					break;
				}
			}
		}
		if(!ok)
			cout<<"NO";
		
		cout<<endl;
	}
	
	
	return 0;
}