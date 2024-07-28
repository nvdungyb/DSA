#include<bits/stdc++.h>
using namespace std;

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
		cout<<v<<" ";
		for(auto x:vt[v])
		{
			if(!visited[x])	
			{
				que.push(x);
				visited[x] = true;
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
		int v, e, u;
		cin>>v>>e>>u;
		vector<int>vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
		}
		
		memset(visited,false,sizeof(visited));
		bfs(vt,u);
		
		cout<<endl;
	}
	
	return 0;
}