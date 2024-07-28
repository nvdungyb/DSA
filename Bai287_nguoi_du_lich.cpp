#include<bits/stdc++.h>
using namespace std;

int a[20][20], parent[20], fopt, n, Min, sum;
bool visited[20];

void Try(int i)
{
	for(int j = 2; j <= n; j++)
	{
		if(!visited[j])
		{
			sum += a[parent[i-1]][j];
			parent[i] = j;
			visited[j] = true;
			
			if(i == n-1)
			{
				if(sum + a[parent[i]][1] < fopt)
					fopt = sum+a[parent[i]][1];
			}else if(sum+Min*(n-i+1) < fopt)
				Try(i+1);
			
			sum -= a[parent[i-1]][j];
			visited[j] = false;
		}
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
		cin>>n;
		Min = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cin>>a[i][j];
				Min = min(Min, a[i][j]);
			}
		}
		
		fopt = INT_MAX, sum = 0;
		memset(visited, false, sizeof(visited));
		visited[1] = true;
		parent[0] = 1;
		
		Try(1);
		
		cout<<fopt<<endl;
	}


	return 0;
}
