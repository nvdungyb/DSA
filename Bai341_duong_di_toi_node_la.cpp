#include<bits/stdc++.h>
using namespace std;


#define maxn 1005

vector<int> adj[maxn];
int parent[maxn];
bool visited[maxn];

void bfs()
{
	queue<int> que;
	que.push(1);
	visited[1] = true;
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

void path(int u)
{
	stack<int> st;
	while(u != 0)
	{
		st.push(u);
		u = parent[u];
	}
	
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
			adj[i].clear();
		
		int node[n+5];						// Mảng đánh dấu, kiểm tra xem node nào là node lá.
		memset(node, 0, sizeof(node));
		
		for(int i = 1; i <= n-1; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			node[x] = 1;
		}
		
		memset(parent, 0, sizeof(parent));
		memset(visited, false, sizeof(visited));
		bfs();
		
		for(int i = 2; i <= n; i++)
		{
			if(!node[i])
				path(i);
		}
	}


	return 0;
}

// Khi bài toán không quan tâm tới sự phân cấp nữa
// thì dùng ma trận kề để lưu chữ tính liên kết giữa các node cũng thỏa mãn.

