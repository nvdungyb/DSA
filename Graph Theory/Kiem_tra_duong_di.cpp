#include<bits/stdc++.h>
using namespace std;


// Kiểm tra đường đi từ đỉnh i tới j với q truy hồi.

bool visited[1005];

void bfs(vector<int>adj[],int u)
{
	queue<int>que;
	que.push(u);
	visited[u] = true;
	while(!que.empty())
	{
		int v = que.front();
		que.pop();
		for(int x:adj[v])
		{
			if(!visited[x])
			{
				visited[x] = true;
				que.push(x);
			}
		}
	}
}

int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<int>adj[n+5];
		for(int i = 1; i <= m; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
	
		int b[n+5][n+5];
		memset(b,0,sizeof(b));
		for(int i = 1; i <= n; i++)				// Kiểm tra có hay không đường đi của từng đỉnh với các đỉnh còn lại, nếu đỉnh i có đường đi tới đỉnh j => b[i][j] = 1;
		{
			memset(visited,false,sizeof(visited));		// Khởi tạo mảng đánh dấu cho từng lần bfs
			bfs(adj,i);
			for(int j = i+1; j <= n; j++)
			{
				if(visited[j])
				{
					b[i][j] = b[j][i] = 1;
				}
			}
		}
		int q,x,y;
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
	}
	
	
	return 0;
}