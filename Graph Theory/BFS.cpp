#include<bits/stdc++.h>
using namespace std;

bool visited[1005];

void bfs(vector<int>adj[],int u)
{
	//step1: Khởi tạo một hàng đợi rỗng (có chức năng lấy phần tử ra ở đầu và thêm phần tử vào cuối)
	queue<int>que;				// Tạo một hàng đợi rỗng
	que.push(u);				// Đẩy đỉnh u vào hàng đợi 
	visited[u]=true;			// Đánh dấu đỉnh u đã thăm
	while(!que.empty())			// Lặp khi mà hàng đợi vẫn còn phần tử 
	{
		int v = que.front();	// Lấy ra đỉnh ở đầu hàng đợi 
		cout<<v<<" ";
		que.pop();				// xóa đỉnh khỏi đầu hàng đợi
		for(int x:adj[v])		// duyệt các đỉnh kề với đỉnh v mà chưa được thăm và đẩy vào hàng đợi.
		{
			if(!visited[x])
			{
				que.push(x);
				visited[x]=true;
			}
		}
	}
}

int main()
{
	int t,v,e,u;
	t = 1;
	while(t--)
	{
		u = 1;
		cin>>v>>e;
		vector<int>adj[v+5];
		int x,y;
		for(int i=1;i<=e;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(visited,false,sizeof(visited));
		bfs(adj,u);
		cout<<endl;
	}
	
	
	return 0;
}