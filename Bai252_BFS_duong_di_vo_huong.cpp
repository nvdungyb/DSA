#include<bits/stdc++.h>
using namespace std;


int parent[1005], s, t;
bool visited[1005];

void bfs(vector<int>vt[], int u)
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
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, k;
	cin>>k;
	while(k--)
	{
		cin>>v>>e>>s>>t;
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
		parent[s] = 0;
		bfs(vt, s);
		
		if(!visited[t])
			cout<<"-1";
		else{
			vector<int> list;
			int u = t;
			while(parent[u])
			{
				list.push_back(u);
				u = parent[u];
			}
			list.push_back(u);
			reverse(list.begin(),list.end());
			
			for(auto x:list)
				cout<<x<<" ";
		}
		
		cout<<endl;
	}
	
	return 0;
}