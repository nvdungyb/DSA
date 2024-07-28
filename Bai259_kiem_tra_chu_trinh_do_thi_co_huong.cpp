#include<bits/stdc++.h>
using namespace std;

// Trong đồ thị có hướng có 3 trạng thái đỉnh v
// color[v] = 0; ứng với đỉnh chưa được thăm.
// color[v] = 1; ứng với đỉnh đang được thăm.
// color[v] = 2; ứng với đỉnh đã thăm xong.

// chu trình trong đồ thị có hướng xảy ra chỉ khi đỉnh đang xét có một cạnh tới đỉnh đang xét khác.

int parent[1005], s, t;
int color[1005]; 

bool dfs(vector<int>vt[], int u)
{
	color[u] = 1;
	for(auto x:vt[u])
	{
		if(!color[x])
		{
			parent[x] = u;
			if(dfs(vt,x))
				return true;
		}else{
			if(color[x] == 1)
				return true;
		}
	}
	color[u] = 2;
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, t;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		vector<int> vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
		}	
		
		memset(parent, 0, sizeof(parent));
		memset(color, 0, sizeof(color));
		
		int ok = 0;
		for(int i = 1; i <= v; i++)
		{
			if(!color[i])
			{
				if(dfs(vt,i))
				{
					ok = 1;
					cout<<"YES";
					break;
				}
			}
		}
		if(!ok)
			cout<<"NO";
		
		cout<<endl;
	}
	
	
	return 0;
}