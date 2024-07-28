#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();
		s = "*"+s;						// đưa về cùng chỉ số.
		long long a[n+5][n+5];					
		for(int i = 1; i <= n; i++)
		{
			a[i][i-1] = 0;				// khởi tạo.
			for(int j = i; j <= n; j++)
			{
				a[i][j] = a[i][j-1]*10+(s[j]-'0');
			}
		}
		
		long long sum = 0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j <= n; j++)
				sum += a[i][j];
		}
		
		cout<<sum<<endl;
	}


	return 0;
}

/*
_Mảng a[i][j]: lưu số tạo bởi xâu con bắt đầu từ vị trí i và kết thúc tại vị trí j.

*/
