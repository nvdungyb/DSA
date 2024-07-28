#include<bits/stdc++.h>
using namespace std;


int v, subnode[200005];
long long val[200005];					// Giá trị của node có thể rất lớn;
vector<int> adj[200005];

void dfs(int u)
{
	for(int x:adj[u])
	{
		dfs(x);
		subnode[u] += subnode[x]+1;		// số node con của u bằng số node con của ke[u] + với chính node ke[u] đó.
		val[u] += val[x];				// Giá trị của node cha bằng tổng giá trị của các node kề với nó + số subnode của nó.
	}
	
	val[u] += subnode[u];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>v;
	for(int i = 1; i <= v; i++)
	{
		adj[i].clear();
		subnode[i] = 0;
		val[i] = 1;
	}	
	
	for(int i = 2; i <= v; i++)
	{
		int x;
		cin>>x;
		adj[x].push_back(i);
	}
	
	dfs(1);

	for(int i = 1; i <= v; i++)
	{
		cout<<val[i]<<" ";
	}
	

	return 0;
}
