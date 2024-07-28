#include<bits/stdc++.h>
using namespace std;

int v, e, t;
int parent[1005];
bool visited[1005];
int a[1005][1005];

void dfs(int u)
{
	visited[u] = true;
	cout<<u<<" ";
	for(int i = 1; i <= v; i++)
	{
		if(!visited[i] && a[u][i] == 1)
		{	
			dfs(i);
		}
	}
}

void dfs_stack(int u)
{
	stack<int> st;
	st.push(u);
	visited[u] = true;
	cout<<u<<" ";
	while(!st.empty())
	{
		int u = st.top(); st.pop();
		visited[u] = true;
		for(int i = 1; i <= v; i++)
		{
			if(!visited[i] && a[u][i])
			{
				cout<<i<<" ";
				st.push(u);
				st.push(i);
				break;	
			}	
		}	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int t, u;
	cin>>t;
	while(t--)
	{
		cin>>v>>e>>u;
		int x, y;
		memset(a, 0, sizeof(a));
		
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			a[x][y] = 1;
			a[y][x] = 1;
		}
		
		memset(visited, false, sizeof(visited));
		parent[u] = 0;
		
		dfs_stack(u);
		
		cout<<endl;
	}
	

	return 0;
}
