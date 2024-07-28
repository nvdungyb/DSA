#include<bits/stdc++.h>
using namespace std;


int adj[1005][1005];
bool visited[1005];
int v, e;

void dfs(int u)
{
	visited[u] = true;
	for(int i = 1; i <= v; i++)
	{
		if(adj[u][i] && !visited[i])
		{
			dfs(i);
		}
	}
}

int lien_Thong()
{
	int cnt = 0;
	for(int i = 1; i <= v; i++)
	{
		if(!visited[i])
		{
			dfs(i);
			cnt++;
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

		memset(adj, 0, sizeof(adj));
		memset(visited, false, sizeof(visited));
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			adj[x][y] = 1;
			adj[y][x] = 1;
		}
		
		int ans = lien_Thong();
		
		for(int i = 1; i <= v; i++)
		{
			for(int j = i+1; j <= v; j++)
			{
				memset(visited, false, sizeof(visited));
				if(adj[i][j])
				{
					adj[i][j] = 0, adj[j][i] = 0;
					int check = lien_Thong();
					adj[i][j] = 1, adj[j][i] = 1;
					if(check != ans)
						cout<<i<<" "<<j<<" ";
				}
			}
		}
		cout<<endl;
	}	
		

	return 0;
}