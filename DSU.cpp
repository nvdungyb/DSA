#include<bits/stdc++.h>
using namespace std;


int ans, n, m, parent[100001], num[100001];

void init()
{
	for(int i = 1; i <= n; i++)
	{
		parent[i] = i;
		num[i] = 1;
	}
}

int Find(int u)
{
	if(u != parent[u])
	{
		parent[u] = Find(parent[u]);
	}
	
	return parent[u];
}

void Union(int u, int v)
{
	int a = Find(u), b = Find(v);
	if(a == b)
		return;
	if(num[a] < num[b])	
		swap(a,b);
	
	parent[b] = a;
	num[a] += num[b];
	ans = max(ans,num[a]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,u,v;
	cin>>t;
	while(t--)
	{
		ans = 0;
		cin>>n>>m;
		init();
		while(m--)
		{
			cin>>u>>v;
			Union(u,v);
		}
		
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i == parent[i])
				cnt++;
		}
		
		cout<<cnt<<endl;
	}
	

	return 0;
}
