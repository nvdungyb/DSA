#include<bits/stdc++.h>
using namespace std;

struct val{
	int u, w;
	
	bool operator < (const val &b)const{
		return w < b.w;
	}
};

void Dijkstra(vector<pair<int,int>> adj[], int v, int s)
{
	vector<int> d(v+5,INT_MAX);
	//int parent[v+5];
	d[s] = 0;
	// Cần lưu cặp đỉnh và trọng số, đỉnh u và trọng số từ đỉnh s tới đỉnh u.
	priority_queue<val> que;
	que.push(val{s,0});
	
	while(!que.empty())
	{
		val top = que.top(); que.pop();
		int u = top.u;
		int kc = top.w;
		// Nếu đỉnh u đã tối ưu hơn cặp đỉnh u và trọng số hiện tại.
		if(kc > d[u]) continue;
		// Nếu chưa xét các đỉnh v kề với u, cập nhật trọng số nhỏ nhất từ s tới v.
		for(auto it : adj[u])
		{
			int v = it.first;
			int w = it.second;
			// d[v] là trọng số từ đỉnh s tới đỉnh v.
			if(d[v] > d[u] + w)
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
	
	int t,v,e,s;
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

// Khai báo: priorty_queue tiêu chuẩn.
// priority_queue< T, Container, Compare>.



