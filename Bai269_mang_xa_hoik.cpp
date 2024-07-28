#include<bits/stdc++.h>
using namespace std;


int v, e, sum;
int parent[100005], size[100005];

void make_set(int v)
{
	for(int i = 1; i <= v; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int u)
{
	if(u != parent[u])
		parent[u] = find(parent[u]);
	
	return parent[u];
}

void Union(int u, int v)
{
	int a = find(u);
	int b = find(v);
	
	if(a != b)
	{
		if(size[a] < size[b])
			swap(a,b);
			
		parent[b] = a;
		size[a] += size[b];
		sum = max(sum,size[a]);
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
		make_set(v);
		sum = 0;
		
		while(e--)
		{
			int x,y;
			cin>>x>>y;
			Union(x,y);
		}
		
		if(sum == v)
			cout<<"YES";
		else
			cout<<"NO";
		
		cout<<endl;
	}


	return 0;
}

// với số đỉnh lên tới 10^5 thì sử dụng disjoin set nhanh hơn rất nhiều so với dfs.
// Tốc độ O(M). với M là số thao tác, khi M đủ lớn.

