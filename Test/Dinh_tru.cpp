#include<bits/stdc++.h>
using namespace std;

// Tìm cầu, khớp nối bằng thuật toán tarjan.
// Thuật toán này có rất nhiều ứng dụng trong lý thuyết đồ thị, cần phải nắm vững.
// bridge, articultation_point.

// id[u] : là định danh của u, là giá trị được gán khi thực hiện dfs. Đó là giá trị của node trên cây dfs, được gán bằng cnt.
// low[u]: là giá trị định danh nhỏ nhất của node mà u có thể đi tới.

#define MAXN 10005
int v, e, cnt;
vector<int>adj[MAXN];
int low[MAXN], id[MAXN];
set<int> st;

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	int node = (p != 0);						// Đỉnh gốc có thể là đỉnh trụ  <=>  node >= 2. là số các đỉnh có cha là gốc và không liên thông với nhau.
	
	for(int v : adj[u])
	{
		if(v == p) continue;					// Chỉ xét đỉnh u không phải là cha của v.
		
		if(id[v]) low[u] = min(low[u],id[v]);	// Tồn tại đường đi từ u tới v. => tạo thành một chu trình.
		else{
			dfs(v,u);
			low[u] = min(low[u],low[v]);		// tồn tại đường đi từ v tới z thì cũng tồn tại đường đi từ u tới z.
		 
			if(low[v] >= id[u])	node++;			// nếu định danh của u nhỏ hơn hoặc bằng giá trị định danh của v, tức nghĩa là không tồn tại đường đi nào của v tới đỉnh có định danh nhỏ hơn u.
		}										
	}
	if(node >= 2)							
		st.insert(u);
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
			low[i] = 0;
			id[i] = 0;
		}
		st.clear();
		
		for(int i = 1; i <= e; i++)
		{
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		
		for(int i = 1; i <= v; i++)
		{
			if(!id[i])
				dfs(i,0);
		}
		for(int i : st)
			cout<<i<<" ";
		
		cout<<endl;
	}
	
	
	return 0;
}


// BT2: tìm đỉnh u của đồ thị sao cho khi loại u thì đồ thị bị chia thành nhiều thành phần liên thông nhất.
/*
	thực hiện thuật toán tarjan xác định đỉnh trụ của đồ thị.
	thực hiện dfs các đỉnh trụ, xác định số tp liên thông lớn nhất.

*/
