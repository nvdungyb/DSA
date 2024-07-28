#include<bits/stdc++.h>
using namespace std;

long long size[200005], result[200005], v;
vector<int> adj[200005];

// cần phải xem xét lại bài này.
void dfs(int u)
{
	for(int i : adj[u])
	{
		dfs(i);
		size[u] += size[i]+1;				// size[u] là số node con mà u quản lý, mà số node con đó ứng với số cạnh nối tới node cha.
		result[u] += result[i];				// result[u] là dinh dưỡng mà node u có chính bằng tổng dinh dưỡng của các node con.	
	}
	
	result[u] += size[u];					
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	t = 1;
	while(t--)
	{
		cin>>v;
		for(int i = 1; i <= v; i++)
		{
			adj[i].clear();
			size[i] = 0;
			result[i] = 1;
		}
		
		for(int i = 2; i <= v; i++)
		{
			int x;
			cin>>x;
			adj[x].push_back(i);	
		}
	 	
	 	dfs(1);
		
		for(int i = 1; i <= v; i++)
		{
			cout<<result[i]<<" ";
		}
		
		cout<<endl;
	}


	return 0;
}
