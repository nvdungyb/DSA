#include<bits/stdc++.h>
using namespace std;


#define maxn 10005
int v, e,
	low[maxn],
	id[maxn],
	on_stack[maxn],
	cnt, ans;
	
vector<int> adj[maxn];
stack<int> st;

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	st.push(u);
	on_stack[u] = 1;
	
	for(int v : adj[u])
	{
		if(id[v]){
			if(on_stack[v])
				low[u] = min(low[u],id[v]);
		}
		else{
			dfs(v,0);
			low[u] = min(low[u],low[v]);
		}
	}
	
	if(low[u] == id[u])
	{
		int v;
		do{
			v = st.top();
			st.pop();
			on_stack[v] = 0;
		}while(v != u);
		
		ans++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	t = 1;
	while(t--)
	{
		cin>>v>>e;
		for(int i = 1; i <= v; i++)
		{
			adj[i].clear();
		}
		
		for(int i = 1; i <= e; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		
		for(int i = 1; i <= v; i++)
		{
			if(!id[i])
				dfs(i,0);
		}

		cout<<ans<<endl;
	}


	return 0;
}