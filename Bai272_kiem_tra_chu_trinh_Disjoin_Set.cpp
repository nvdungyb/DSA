#include<bits/stdc++.h>
using namespace std;


void make_set(int parent[],int size[], int v)
{
	for(int i = 1; i <= v; i++)
	{
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int parent[],int u)
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
		
		int parent[v+5];
		int size[v+5];
		make_set(parent,size,v);
		
		int a, b;
		int ok = 0;
		for(int i = 1; i <= e; i++)
		{
			cin>>a>>b;
			if(!ok)
			{
				int x = find(parent,a);			// Tìm đại diện cho tập chứa phần tử a.
				int y = find(parent,b);			//	   đại diện cho tập chứa phần tử b.
				if(x != y)
				{
					if(size[x] < size[y])		
						swap(x,y);
					parent[y] = x;				// gán đại diện của tập nhỏ hơn là đại diện của tập lớn hơn. 
					size[x] += size[y];			// Tăng lượng phần tử của tập sau khi gộp.		
				}else{
					ok = 1;
				}
			}
		}
		
		if(ok)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}


	return 0;
}
