#include<bits/stdc++.h>
using namespace std;

// Tìm cầu, khớp nối bằng thuật toán tarjan.
// Thuật toán này có rất nhiều ứng dụng trong lý thuyết đồ thị, cần phải nắm vững.
// bridge, articultation_point.

// id[u] : là định danh của u, là giá trị được gán khi thực hiện dfs. Đó là giá trị của node trên cây dfs, được gán bằng cnt.
// low[u]: là giá trị định danh nhỏ nhất của node mà u có thể đi tới.

#define MAXN 10005
int v, e, cnt = 0, bridge = 0, articulation_point = 0;
vector<int>adj[MAXN];
int low[MAXN], id[MAXN];

void dfs(int u, int p)
{
	id[u] = low[u] = ++cnt;
	int node = (p != 0);
	
	for(int v : adj[u])
	{
		if(v == p) continue;					// Chỉ xét đỉnh u không phải là cha của v.
		
		if(id[v]) low[u] = min(low[u],id[v]);	// Tồn tại đường đi từ v tới u. => cung ngược.
		else{									// Cung xuôi.
			dfs(v,u);
			low[u] = min(low[u],low[v]);		// tồn tại đường đi từ v tới z thì cũng tồn tại đường đi từ u tới z.
			if(low[v] == id[v])	bridge++;		// 
			if(low[v] >= id[u])	node++;			// nếu định danh của u nhỏ hơn hoặc bằng giá trị định danh của v, tức nghĩa là không tồn tại đường đi nào của v tới đỉnh có định danh nhỏ hơn u.
		}										// kết hợp đk: đỉnh u không phải là đỉnh gốc. thì đỉnh u là cạnh cầu.
	}
	if(node >= 2)	articulation_point++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>v>>e;
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
	
	cout<<articulation_point<<" "<<bridge<<endl;
	
	
	return 0;
}

// có hình minh họa: http://i433.photobucket.com/albums/qq53/canhtoannguyen/NewBitmapImage.jpg
