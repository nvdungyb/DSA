#include<bits/stdc++.h>
using namespace std;

 
int v, e, s;
vector<int> adj[1005];
int parent[1005];
bool visited[1005];

void bfs(int u)
{
	queue<int> que;
	que.push(u);
	visited[u] = true;
	parent[u] = 0;
	while(!que.empty())
	{
		int v = que.front();
		que.pop();
		
		for(int x : adj[v])
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

	int t;
	cin>>t;
	while(t--)
	{
		cin>>v>>e>>s;
		for(int i = 1; i <= e; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		memset(visited, false, sizeof(visited));
		bfs(s);
		
		for(int i = 2; i <= v; i++)
		{
			if(visited[i])
			{
				stack<int> st;
				int x = i;
				while(x != 0)
				{
					st.push(x);
					x = parent[x];
				}
				
				while(!st.empty())
				{
					cout<<st.top()<<" ";
					st.pop();
				}
			}else{
				cout<<"No Path";
			}
			
			cout<<endl;
		}
	}


	return 0;
}
