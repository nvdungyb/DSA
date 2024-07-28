#include<bits/stdc++.h>
using namespace std;

int v, e, ans;
int parent[1005];
bool visited[1005];
 
bool dfs(vector<int> adj[], int u)
{
	visited[u] = true;
	for(int x:adj[u])
	{
		if(!visited[x])
		{
			parent[x] = u;
			if(dfs(adj,x))
				return true;
		}else{
			if(x == 1 && x != parent[u])		// Điều kiện kiểm tra xem đồ thị có chu trình từ đỉnh 1 hay ko.
			{
				ans = u;
				return true;
			}
		}
	}
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
		cin>>v>>e;
		vector<int> adj[v+5];
		int x, y;
		for(int i = 0; i < e; i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		for(int i = 1; i <= v; i++)
		{
			sort(adj[i].begin(),adj[i].end());
		}
		
		memset(visited, false, sizeof(visited));
		memset(parent, 0, sizeof(parent));
		
		if(dfs(adj,1))
		{
			vector<int> vt;
			vt.push_back(1);
			
			while(ans != 0)
			{
				vt.push_back(ans);
				ans = parent[ans];
			}
			
			for(auto x = vt.rbegin(); x != vt.rend(); x++)
				cout<<*x<<" ";
			
		}else{
			cout<<"NO";
		}
		
		cout<<endl;
	}


	return 0;
}