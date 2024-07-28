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
		s = " "+s;
		ss = " "+ss;
		
		int dp[n+5][m+5];
		for(int i = 0; i <= n; i++)
			dp[i][0] = i;
		for(int j = 0; j <= m; j++)
			dp[0][j] = j;
			
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(s[i] == ss[j])
					dp[i][j] = dp[i-1][j-1];
				else
					dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
			}
		}
		
		cout<<dp[n][m]; 
		cout<<endl;
	}


	return 0;
}

// Đây là bài toán đếm khoảng cách Levenshtein.
// Còn gọi là khoảng cách chỉnh sửa.
// Số bước ít nhất thực hiện phép Insert, delete, replace để xâu s1 trở thành xâu s2.
// dp[i-1][j] + 1: đại diện cho phép xóa.
// dp[i][j-1] + 1: đại diện cho phép thêm.
// dp[i-1][j-1] + 1: đại diện cho phép thay đổi.

// đầu tiên khởi tạo mảng lưu khoảng cách levenshtein của i ký tự đầu tiên của s1 và j kí tự đầu tiên của s2.
// phép distance = min(insertion, seletions, subtitutions), nghĩa là phép nào cho khoảng cách nhỏ nhất thì lấy.

