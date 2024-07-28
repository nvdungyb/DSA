#include<bits/stdc++.h>
using namespace std;


// Dường đi Hamilton: đường đi qua tất cả các đỉnh của đồ thị mỗi đỉnh đúng một lần.
// Chu trình hamilton: chu trình bắt đầu tại đỉnh v nào đó qua tất cả các đỉnh của đồ thị đúng một lần sau đó quay trở lại v.

int v, e, ok;
bool visited[100];

bool hamilton(vector<int> vt[],int u, int k)
{
	for(int i : vt[u])
	{
		if(!visited[i])
		{
			visited[i] = true;
			if(k == v)
				return true;
			else if(k < v)
			{
				if(hamilton(vt,i,k+1))
					return true;
			}
					
			visited[i] = false;
		}
	}
	return false;
}
 
bool check(vector<int> vt[])
{
	for(int i = 1; i <= v; i++)
	{
		memset(visited, false, sizeof(visited));
		visited[i] = true;						// đánh dấu đỉnh đầu bắt đầu duyệt, mới đúng tư tưởng dfs.
		if(hamilton(vt,i,2))
			return true;
	}
	
	return false;
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
		vector<int> vt[100];
		int x, y;
		for(int i = 0; i < e; i++)
		{
			cin>>x>>y;
			vt[x].push_back(y);
			vt[y].push_back(x);
		}
		
		if(check(vt))	
			cout<<"1";
		else
			cout<<"0";
		
		cout<<endl;
	}
	

	return 0;
}
