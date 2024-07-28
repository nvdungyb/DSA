#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin>>n>>m;
	int a[n+5][n+5];
	
	// Nhớ đk khởi tạo này, vì chi phí đi từ i đến j nếu i == j thì phải bằng 0.
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == j)
				a[i][j] = 0;
			else
				a[i][j] = 10005;			// Khởi tạo INT_MAX ở đây là khi tính tổng bị tràn số đấy nhé.
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		int x, y, c;
		cin>>x>>y>>c;
		a[x][y] = a[y][x] = c;
	}	 

	// Thuật toán floy: tìm đường đi ngắn nhất giữa hai đỉnh.
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
	
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= n; j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	int q, x, y;
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		cout<<a[x][y]<<endl;
	}
	

	return 0;
}
