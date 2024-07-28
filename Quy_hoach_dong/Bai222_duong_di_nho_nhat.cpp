#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int a[n+5][m+5];
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
				cin>>a[i][j];	
		}		
		
		long long b[n+5][m+5];
		memset(b, 0, sizeof(b));				// Phải khởi tạo mảng giá trị chi phí.
		
		for(int i = 1; i <= n; i++)				// b[i][j]: là giá trị nhỏ nhất từ ô (1,1) tới ô (i,j).
			b[i][0] = INT_MAX;					// Khởi tạo tất cả cột hàng 0 và cột 0 ở hàng thành INT_MAX, mục đích loại giá trị các ô không dùng tới.
		for(int j = 1; j <= m; j++)
			b[0][j] = INT_MAX;					// Trong đó b[0][0] = 0;	// ô cơ sở, bài toán mới được áp dụng.
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				b[i][j] = min(min(b[i-1][j],b[i-1][j-1]),b[i][j-1])+a[i][j];
			}
		}
	 
		cout<<b[n][m]<<endl;
	}


	return 0;
}
