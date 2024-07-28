#include<bits/stdc++.h>
using namespace std;

// Tìm cây khung nhỏ nhất.
/*
_ đồ thị có n đỉnh thì cây khung của nó có đúng n-1 cạnh.
_ Tổng trọng số của các cạnh của cây nhỏ nhất thì đó là cây khung nhỏ nhất. (minimum spanning tree).

*/

struct edge{
	int dau, cuoi, trongso;
};

bool cmp(edge a, edge b)
{
	return a.trongso < b.trongso;
}

void make_set(int parent[], int size[], int v)
{
	for(int i = 1; i <= v; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int parent[], int u)
{
	if(u == parent[u])
		return u;
	return parent[u] = find(parent,parent[u]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, v, e;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		
		edge a[e+5];
		for(int i = 0; i < e; i++)
		{
			cin>>a[i].dau>>a[i].cuoi>>a[i].trongso;
		}
		
		// B1: sort các cặp cạnh có trọng số giảm dần.
		sort(a,a+e,cmp);
		
		// B2: khởi tạo các tập rời rạc, đại diện và kích cỡ.
		int parent[v+5], size[v+5];
		make_set(parent,size,v);
		
		// B3: thuật toán kruskal.
		int tree_edge = 0, resul = 0;
		for(int i = 0; i < e; i++)
		{
			if(tree_edge < v-1)
			{
				int x = find(parent,a[i].dau);
				int y = find(parent,a[i].cuoi);
				
				if(x != y)
				{
					if(size[x] < size[y])
						swap(x,y);
					parent[y] = x;
					size[x] += size[y];	
					tree_edge++;					// nếu yêu cầu in ra các cạnh của cây khung thì dùng vector.
					resul += a[i].trongso;
				}	
			}else{
				break;
			}
		}
		
		cout<<resul<<endl;
	}


	return 0;
}

// Dữ liệu vào phải đảm bảo rằng đồ thị liên thông.