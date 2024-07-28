#include<bits/stdc++.h>
using namespace std;

bool visited[1005];

void dfs(vector<int>vt[], int u)
{
	visited[u] = true;
	for(int x:vt[u])
	{
		if(!visited[x])
			dfs(vt,x);
	}
}

bool check(int v)
{
	for(int i = 1; i <= v; i++)
		if(!visited[i])
			return false;
	return true;
}

bool strong_Conective(vector<int>vt[], int v)
{
	for(int i = 1; i <= v; i++)
	{
		memset(visited, false, sizeof(visited));
		dfs(vt,i);
		if(!check(v))
			return false;
	}
	return true;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, e, v;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		vector<int>vt[v+5];
		int x,y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
		}
		
		if(strong_Conective(vt,v))
			cout<<"YES";
		else
			cout<<"NO";
			
		cout<<endl;
	}
 
	
	return 0;
}

// Đồ thị có hướng G(v,e) là liên thông mạnh nếu giữa hai đỉnh bất kỳ của nó đều tồn tại đường đi.
// => tức là khi dfs hoặc bfs một đỉnh của đồ thị liên thông mạnh sẽ duyệt hết tất cả các đỉnh còn lại của đồ thị.
