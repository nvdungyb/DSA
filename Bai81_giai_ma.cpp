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
		
		if(s[0] == '0')
		{
			cout<<"0"<<endl;
			continue;
		}
		
		int n = s.length();
		int dp[50];
		dp[0] = 1, dp[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			dp[i] = 0;
			if(s[i-1] > '0')
				dp[i] = dp[i-1];
			if(s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7')
				dp[i] += dp[i-2];
		}
		cout<<dp[n]<<endl;
	}


	return 0;
}

// nắm được tư tưởng của công thức này là rất có ích nhé, tiêu biểu của công thức truy hồi.

/*
	gọi dp[i] là số cách mã hóa đến kí tự thứ i.
	_nếu s[i] == '0' => dp[i] = dp[i-1].
	s[i-1]s[i]
	+nếu s[i-1] == '1' thì s[i] luôn gép được và số cách là dp[i-1].
	+nếu s[i-1] == !1  thì s[i-1] chỉ có thể bằng 2 mới ghép vơi s[i] với s[i] < '7'.

	chỉ số của mảng bắt đầu từ 1 mà của xâu bắt đầu từ 0 => lùi chỉ số của xâu đi 1 đv.
*/
