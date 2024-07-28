#include<bits/stdc++.h>
using namespace std;

int v, e, s, cnt, parent[1005];
vector<int> resul;
bool visited[1005];

void tree(vector<int> adj[], int u)
{
	queue<int> que;
	que.push(u); 
	visited[u] = true;
	while(!que.empty())
	{
		int v = que.front(); que.pop();
		for(int i : adj[v])
		{
			if(!visited[i])
			{
				parent[i] = v;
				resul.push_back(i);
				cnt++;
				visited[i] = true;
				que.push(i);
			}
		}
	}
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
		cin>>v>>e>>s;
		vector<int> adj[1005];
		int x, y;
		for(int i = 0; i < e; i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		resul.clear();
		cnt = 0;
		memset(visited, false, sizeof(visited));
		
		tree(adj,s);
		
		if(cnt == v-1)				// Đồ thị liên thông => xây dựng được cây khung.
		{
			for(int i:resul){
				cout<<parent[i]<<" "<<i<<endl;
			}
		}else{
			cout<<"-1"<<endl;
		}
	}


	return 0;
}
