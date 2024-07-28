#include<bits/stdc++.h>
using namespace std;

bool visited[1005];
int parent[1005];

void dfs(vector<int>vt[], int u)
{
	visited[u] = true;
	for(auto x:vt[u])
	{
		if(!visited[x])
		{
			dfs(vt,x);
		}
	}
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
		
		int b[v+5][v+5];
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= v; i++)
		{
			memset(visited, false, sizeof(visited));
			dfs(vt,i);
			for(int j = i+1; j <= v; j++)
			{
				if(visited[j])
					b[i][j] = b[j][i] = 1;
			}
		}
		
		int q;
		cin>>q;
		for(int i = 1; i <= q; i++)
		{
			cin>>x>>y;
			if(b[x][y])
				cout<<"YES";
			else
				cout<<"NO";
			cout<<endl;
		}

		cout<<endl;
	}
	
	return 0;
}