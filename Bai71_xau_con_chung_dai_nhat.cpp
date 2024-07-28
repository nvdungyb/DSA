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
		string s, ss;
		cin>>s>>ss;
		int n = s.length();
		int m = ss.length();
		
		// cách đưa chỉ số của xâu trùng với ma trận trạng thái.
		s = " "+s;
		ss = " "+ss;
		
		int a[n+5][m+5];
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(s[i] == ss[j])
					a[i][j] = a[i-1][j-1]+1;
				else
					a[i][j] = max(a[i-1][j], a[i][j-1]);
			}
		}
		cout<<a[n][m]<<endl;
	}
	
	
	return 0;
}

// quy hoạch động trạng thái mảng a[i][j].
// lưu trạng thái độ dài xâu con (có thể không liên tiếp) lớn nhất
// của i kí tự đầu tiên của xâu 1 với j kí tự đầu tiên của xâu 2.

/*
+ a[0][j] = 0, a[i][0] = 0;	 đây là th cơ sở của bài toán này.
+ nếu s[i] == ss[j]		=> a[i][j] = a[i-1][j-1]+1;
+ nếu không: 			=> a[i][j] = max(a[i-1][j], a[i][j-1]).

*/