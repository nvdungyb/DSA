#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int v, e;
bool visited[1005];

void bfs(vector<int>vt[], int u)
{
	queue<int>que;
	que.push(u);
	visited[u] = true;
	while(!que.empty())
	{
		int v = que.front(); que.pop();
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
		cin>>v>>e;
		vector<int>vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for(int i = 1; i <= v; i++)
		{
			if(!visited[i])
			{
				bfs(vt,i);
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	
	
	return 0;
}