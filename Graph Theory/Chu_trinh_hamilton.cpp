#include<bits/stdc++.h>
using namespace std;


// chu trình hamilton bắt đầu từ đỉnh u duyệt qua tất cả các đỉnh đúng một lần rồi quay lại đỉnh u
// Tìm tất cả các chu trình hamilton.

int v, e, parent[1005];
bool visited[1005];

void display()
{
	for(int i = 1; i <= v; i++)
		cout<<parent[i]<<" ";
	cout<<parent[1]<<endl;
}

void dfs(vector<int>vt[], int u, int k)
{
	for(int i : vt[u])
	{
		if(!visited[i])
		{
			visited[i] = true;
			parent[k] = i;
			if(k < v+1)
				dfs(vt, i, k+1);
				
			visited[i] = false;
		}else{
			if(k == v+1 && i == parent[1])
				display();
		}
	}
}

void hamilton(vector<int> vt[])
{
	for(int i = 1; i <= v; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;
		parent[1] = i;
		dfs(vt,i,2);
	}
	
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
		cin>>v>>e;
		vector<int> vt[v+5];
		int x, y;
		for(int i = 0; i < e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		
		hamilton(vt);
		
	}

	return 0;
}

/*
1
5 7
1 2
1 4
2 3
2 5
3 4
3 5
4 5
*/