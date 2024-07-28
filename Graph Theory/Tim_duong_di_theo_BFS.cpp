#include<bits/stdc++.h>
using namespace std;


// Tìm đường đi theo BFS với đồ thị có hướng
// Thuật Toán BFS cho ta độ dài đường đi ngắn nhất từ đỉnh nguồn tới mọi đỉnh.
// Trong đồ thị bất kì, tổng số bậc của tất cả các đỉnh bằng gấp đôi số cạnh của đồ thị => số lượng đỉnh bậc lẻ là một số chẵn.

bool visited[1005];
int parent[1005];

void bfs(vector<int>adj[],int u)
{
	queue<int>que;
	que.push(u);
	visited[u]=false;
	while(!que.empty())
	{
		int v=que.front();
		que.pop();
		for(int x:adj[v])
		{
			if(!visited[x])
			{
				que.push(x);
				visited[x]=true;
				parent[x]=v;
			}
		}
	}
}

int main()
{
	int k,v,e,s,t;
	cin>>k;
	while(k--)
	{
		cin>>v>>e>>s>>t;
		vector<int>adj[v+5];
		for(int i=1;i<=e;i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		memset(visited,false,sizeof(visited));
		memset(parent,0,sizeof(parent));
		
		bfs(adj,s);
		
		if(!visited[t])
		{
			cout<<"-1";
		}else{
			vector<int>sul;
			while(t!=s)
			{
				sul.push_back(t);
				t=parent[t];
			}
			sul.push_back(s);
			reverse(sul.begin(),sul.end());
			for(int x:sul)
				cout<<x<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}