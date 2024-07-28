#include<bits/stdc++.h>
using namespace std;

// sử dụng thuật toán welsh_powell

int v, e, k;
int degree[20], color;
int colored[20];
bool visited[20];


bool check()
{
	for(int i = 1; i <= v; i++)
	{
		if(!colored[i])
			return true;
	}
	return false;
}

void delete_vertice(set<int> adj[], int u)
{
	for(int i = 1; i <= v; i++)
	{
		if(adj[i].count(u))
		{
			degree[i]--;
			adj[i].erase(u);
		}
	}
}

bool can_color(set<int> adj[], int u, int y)
{
	if(adj[u].count(y) || colored[y])
		return false;
	for(int x:adj[y])
	{
		if(colored[x] == color)
			return false;
	}
	return true;
}

bool can_be(set<int> adj[])
{
	// sort(theo đỉnh có bậc tăng dần).
	while(check())
	{
		set<pair<int,int>> st;
		for(int i = 1; i <= v; i++)
		{
			if(!visited[i])
				st.insert({degree[i],i});
		}
		
		auto it = st.end(); it--;
		int u = (*it).second;
		color++;
		colored[u] = color;
		for(int i = 1; i <= v; i++)
		{
			if(i != u && can_color(adj,u,i))
			{
				colored[i] = color;
				visited[i] = true;
			}
		}
		
		for(int i = 1; i <= v; i++)
		{
			if(visited[i])
				delete_vertice(adj,i);
		}
		delete_vertice(adj,u);
		visited[u] = true;
	
	}
	
	if(color <= k)
		return true;
	return false;
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
		cin>>v>>e>>k;
		set<int> adj[v+5];
		memset(degree, 0, sizeof(degree));
		for(int i = 1; i <= e; i++)
		{
			int x, y;
			cin>>x>>y;
			adj[x].insert(y);
			adj[y].insert(x);
			degree[x]++, degree[y]++;
		}
		
		color = 0;
		memset(colored, 0, sizeof(colored));
		memset(visited, false, sizeof(visited));
		
		if(can_be(adj))
			cout<<"YES";
		else
			cout<<"NO";
		
		cout<<endl;
	}
	

	return 0;
}
