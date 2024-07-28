#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, x, y, z;
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y>>z;
		int dp[n+5];
		dp[1] = x;
		for(int i = 2; i <= n; i++)
		{
			if(i%2 == 0)
				dp[i] = min(dp[i-1]+x, dp[i/2]+z);
			else
				dp[i] = min(min(dp[i-1]+x, dp[(i+1)/2]+z+y), dp[(i-1)/2]+z+x);
		}
		
		cout<<dp[n]<<endl;
	}


	return 0;
}

// i là số kí tự hiện có.
// x là chi phí khi chèn thêm vào 1 kí tự.
// y là chi phí khi loại bỏ đi 1 kí tự.
// z là chi phí khi nhân đôi các kí tự hiện có.
