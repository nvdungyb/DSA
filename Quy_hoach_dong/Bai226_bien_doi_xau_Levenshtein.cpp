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

