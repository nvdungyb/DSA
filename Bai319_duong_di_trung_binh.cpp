#include<bits/stdc++.h>
using namespace std;


#define MAX 1000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n , m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int a[n+5][n+5];
		
		// Khởi tạo chi phí cho mảng a[].
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i == j)
					a[i][j] = 0;
				else
					a[i][j] = MAX;
			}
		}
		
		for(int i = 1; i <= m; i++)
		{
			int x,y;
			cin>>x>>y;
			a[x][y] = 1;
		}
		
		// Thuật toán Floyd.
		for(int k = 1; k <= n; k++)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					if(a[i][j] > a[i][k]+a[k][j])
						a[i][j] = a[i][k]+a[k][j];
				}
			}
		}
		
		int sum = 0, cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(a[i][j] != 0 && a[i][j] != MAX)
				{
					sum += a[i][j];
					cnt++;
				}
			}
		}
		
		cout<<fixed<<setprecision(2)<<(double)sum/cnt<<endl;
	}
	
	
	return 0;
}
 