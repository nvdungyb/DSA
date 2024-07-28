#include<bits/stdc++.h>
using namespace std;

struct val{
	int u, w;
	
	bool operator < (const val& b)const{
		return w < b.w;
	}
};

void Dijkstra(vector<pair<int,int>> adj[], int v, int s)
{
	vector<int> d(v+5,INT_MAX);
	d[s] = 0;
	priority_queue<val> que;
	que.push(val{s,0});
	
	while(!que.empty())
	{
		val top = que.top();  que.pop();
		int u = top.u;
		int k = top.w;
		
		if(k > d[u]) 
			continue;
			
		for(auto it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			if(d[v] > d[u]+w)
			{
				d[v] = d[u]+w;
				que.push(val{v,d[v]});
			}
		}
	}
	
	for(int i = 1; i <= v; i++)
		cout<<d[i]<<" ";
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, v, e, s;
	cin>>t;
	while(t--)
	{
		cin>>v>>e>>s;
		vector<pair<int,int>> adj[v+5];
		for(int i = 1; i <= e; i++)
		{
			int x, y, z;
			cin>>x>>y>>z;
			adj[x].push_back({y,z});
			adj[y].push_back({x,z});
		}
		
		Dijkstra(adj,v,s);
		
	}
	

	return 0;
}
