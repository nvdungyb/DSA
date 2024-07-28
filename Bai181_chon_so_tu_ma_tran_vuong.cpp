#include<bits/stdc++.h>
using namespace std;

int n, k, a[15][15], parent[15], sum, cnt;
bool visited[15];
vector<int> vt[15];

void insert()
{
	cnt++;
	for(int i = 1; i <= n; i++)
		vt[cnt].push_back(parent[i]);
}

void Try(int i)
{
	for(int j = 1; j <= n; j++)
	{
		if(!visited[j])
		{
			sum += a[i][j];
			parent[i] = j;
			visited[j] = true;
			if(i == n){
				if(sum == k)
					insert();
			}else
				Try(i+1);
				
			sum -= a[i][j];
			visited[j] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cin>>a[i][j];
	}
	
	sum = 0, cnt = 0;
	Try(1);
	
	cout<<cnt<<endl;
	for(int i = 1; i <= cnt; i++)
	{
		for(int x:vt[i])
			cout<<x<<" ";
		cout<<endl;
	}


	return 0;
}
