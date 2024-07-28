#include<bits/stdc++.h>
using namespace std;
 
bool visited[1005];

void dfs(vector<int>vt[],int u)
{
	visited[u] = true;
	for(int x:vt[u])
	{
		if(!visited[x])
			dfs(vt,x);
	}
}

int count(vector<int>vt[],int v)
{
	int cnt = 0;
	for(int i = 1; i <= v; i++)
	{
		if(!visited[i])	
		{
			cnt++;
			dfs(vt,i);
		}
	}
	return cnt;
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
		vector<int>vt[v+5];
		int x, y;
		for(int i = 1; i <= e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}	
		
		memset(visited, false, sizeof(visited));
		
		int tpLienThong = count(vt,v);
		 
		for(int i = 1; i <= v; i++)
		{
			memset(visited, false, sizeof(visited));
			int check = 0;
			visited[i] = true;
			if(i == 1)
			{
				check = count(vt,v);
			}else{
				check = count(vt,v);
			}
			if(check != tpLienThong)
				cout<<i<<" ";
		}
		cout<<endl;
	}

	
	return 0;
}