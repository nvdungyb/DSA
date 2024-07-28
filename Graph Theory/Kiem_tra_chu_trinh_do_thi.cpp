#include<bits/stdc++.h>
using namespace std;

//Kiểm tra chu trình trên đồ thị vô hướng 
//Bằng thuật toán DFS và BFS
// sử dụng DFS check thì truy vấn đc chu trình còn BFS chỉ check đc có tồn tại chu trình hay ko thôi.

int v,e;
bool visited[1001];
int parent[1001];

void input(vector<int>adj[])
{
	for(int i=0;i<e;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(visited,false,sizeof(visited));
}

bool bfs(vector<int>adj[],int u)
{
	queue<int>que;
	que.push(u);
	visited[u]=true;
	while(!que.empty())
	{
		int v = que.front();
		que.pop();
		visited[v] = true;
		for(int x:adj[v])
		{
			if(!visited[x])
			{
				que.push(x);
				visited[x] = true;
				parent[x] = v;
			}else if(x != parent[v]){
				return true;
			}
		}	
	}
	return false;
}

bool dfs(vector<int>adj[],int u)
{
	visited[u] = true;
	for(int x:adj[u])
	{
		if(!visited[x])
		{
			parent[x] = u;
			if(dfs(adj,x))
				return true;
		}else if(x != parent[u]){
			return true;
		}
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		vector<int>adj[v+5];
		input(adj);
		int check = 0;
		for(int i = 1; i <= v; i++)
		{
			if(!visited[i])
			{
				if(dfs(adj,i))
				{
					cout<<"YES";
					check = 1;	
					break;
				}	
			}	
		}
		if(!check)
			cout<<"NO";
		cout<<endl;
	}
	
	
	return 0;
}