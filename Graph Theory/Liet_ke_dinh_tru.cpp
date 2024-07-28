//Đỉnh trụ u thuộc đồ thị, nếu loại bỏ u cùng các cạnh nối với u sẽ làm tăng thành phần liên thông của đồ thị.

#include<bits/stdc++.h>
using namespace std;

int v,e;
bool visited[1001];

void input(vector<int>adj[])
{
	for(int i=0; i<e; i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(vector<int>adj[],int u)
{
	visited[u]=true;
	for(int x:adj[u])
	{
		if(!visited[x])
			dfs(adj,x);
	}
}

void dinhTru(vector<int>adj[])
{
	int cnt=0;
	memset(visited,false,sizeof(visited));
	for(int i=1; i <= v; i++)
	{
		if(!visited[i])
		{
			cnt++;
			dfs(adj,i);
		}
	}
	
	for(int i=1; i <= v; i++)
	{
		memset(visited,false,sizeof(visited));
		int dem=0;
		visited[i]=true;
		for(int j=1; j <= v; j++)
		{
			if(!visited[j])
			{
				dem++;
				dfs(adj,j);
			}
		}
		if(dem>cnt)
			cout<<i<<" ";
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		vector<int>adj[1001];
		input(adj);
	 	dinhTru(adj);
	 	
		cout<<endl;
	}
	
	return 0;
}