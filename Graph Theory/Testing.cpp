#include<bits/stdc++.h>
using namespace std;

// Tìm chu trình euler của đồ thị có hướng, vô hướng.

vector<int> resul;
bool visited[30][30];
int v, e;

void euler_circle(set<int> adj[], int u)
{
	for(int x:adj[u])
	{	
		if(!visited[u][x])
		{	
			visited[u][x] = true;
			euler_circle(adj,x);
		}
	}
	resul.push_back(u);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>v>>e;
	set<int> adj[v+5];
	for(int i = 1; i <= e; i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].insert(y);
	}
	
	
	memset(visited, false, sizeof(visited));
	euler_circle(adj,1);
	
	for(auto it = resul.rbegin(); it != resul.rend(); it++)
		cout<<*it<<" ";
		

	return 0;
}
