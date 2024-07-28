#include<bits/stdc++.h>
using namespace std;

int v, e, cnt, ok, parent[1005];
bool visited[1005];

void dfs(vector<int>adj[], int u)
{
	visited[u] = true;
	for(int i:adj[u])
	{
		if(!visited[i]){
			parent[i] = u;
			dfs(adj,i);
			cnt++;
		}else{
			if(i != parent[u])
				ok = 1;
		}
	}
}

bool check(vector<int> adj[])
{
	cnt = 0, ok = 0;
	memset(visited, false, sizeof(visited));
	
	dfs(adj,1);
	
 	if(ok)				// Cây là đồ thị không có chu trình.
 		return false;
	if(cnt == v-1)		// Cây có N đỉnh và N-1 cạnh, liên thông.
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
		cin>>v;
		e = v-1;
		vector<int> adj[v+5];
		int x, y;
		for(int i = 0; i < e; i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		if(check(adj))
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}


	return 0;
}
