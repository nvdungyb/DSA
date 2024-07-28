#include<bits/stdc++.h>
using namespace std;


// Đồ thị có chu trình âm: khi thực hiện thuật toán floyd thì tồn tại đỉnh u mà d[u][u] < 0.
// Ứng dụng của Floyd. 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		int e, v;
		cin>>v>>e;
		int a[v+5][v+5];
		
		// Nhớ đk khởi tạo này, vì chi phí đi từ i đến j nếu i == j thì phải bằng 0.
		for(int i = 1; i <= v; i++)
		{
			for(int j = 1; j <= v; j++)
			{
				if(i == j)
					a[i][j] = 0;
				else
					a[i][j] = 10005;
			}
		}
		
		// Để ý danh sách cạnh, xem nó là đồ thị có hướng hay vô hướng.
		for(int i = 1; i <= e; i++)
		{
			int x, y, c;
			cin>>x>>y>>c;
			a[x][y] = c;
		}	 
	
		// Thuật toán floy: tìm đường đi ngắn nhất giữa hai đỉnh.
		for(int k = 1; k <= v; k++)
		{
			for(int i = 1; i <= v; i++)
			{
				for(int j = 1; j <= v; j++)
				{
					if(a[i][j] > a[i][k]+a[k][j])
						a[i][j] = a[i][k]+a[k][j];
				}
			}
		}
		
		int ok = 0;
		for(int i = 1; i <= v; i++)
		{
			if(a[i][i] < 0)
				ok = 1;
		}
		
		cout<<ok<<endl;
	}
	

	return 0;
}
