#include<bits/stdc++.h>
using namespace std;

// Tìm cầu, khớp nối bằng thuật toán tarjan.
// Thuật toán này có rất nhiều ứng dụng trong lý thuyết đồ thị, cần phải nắm vững.
// bridge, articultation_point.

// id[u] : là định danh của u, là giá trị được gán khi thực hiện dfs. Đó là giá trị của node trên cây dfs, được gán bằng cnt.
// low[u]: là giá trị định danh nhỏ nhất của node mà u có thể đi tới.

#define MAXN 10005
int v, e, cnt, bridge, articulation_point;
vector<int>adj[MAXN];
vector<pair<int,int>> result;
int low[MAXN], id[MAXN];


// cạnh (u,v) là cầu khi low[v] == id[v].	tức nghĩa là từ đỉnh v không có đường đi tới tổ tiên của v.
// đỉnh u là trụ khi low[v] >= id[u].

void dfs(int u,int p)		// đồ thị vô hướng thì phải kt đk cha của đỉnh u.
{
	low[u] = id[u] = ++cnt;
	for(int v : adj[u])
	{
		if(v == p)
			continue;
		if(id[v])
			low[u] = min(low[u],id[v]);
		else{
			dfs(v,u);
			low[u] = min(low[u],low[v]);
			
			if(low[v] == id[v])		// tức nghĩa là từ đỉnh v không có đường nào tới cha của u.
			{
				int tmp1 = u, tmp2 = v;
				if(tmp1 > tmp2)	
					swap(tmp1,tmp2);
				result.push_back({tmp1,tmp2});
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
		cin>>v>>e;
		for(int i = 1; i <= v; i++)
		{
			adj[i].clear();
			id[i] = 0;
			low[i] = 0;
		}
		for(int i = 1; i <= e; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		cnt = 0;
		result.clear();
		for(int i = 1; i <= v; i++)
		{
			if(!id[i])
				dfs(i,0);
		}
		
		sort(result.begin(),result.end());
		for(auto it : result)
			cout<<it.first<<" "<<it.second<<" ";
			
		cout<<endl;
	}
	
	
	return 0;
}
