#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, v;
	cin>>t;
	while(t--)
	{
		cin>>n>>v;
		pair<int,int> a[n+5];
		int dp[n+5][v+5];
		
		for(int i = 1; i <= n; i++)
			cin>>a[i].first;
		for(int i = 1; i <= n; i++)
			cin>>a[i].second;
			
		memset(dp, 0, sizeof(dp));
		
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= v; j++)
			{
				dp[i][j] = dp[i-1][j];
				if(a[i].first <= j)
					dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].first]+a[i].second);
			}
		}
		
		cout<<dp[n][v]<<endl;			
	}


	return 0;
}
/*
_dp theo trạng thái.
_Tư tưởng thế này: tại (i,j) đại diện giá trị lớn nhất của túi khi ta cho đồ vật 1->i và trọng lượng tối đa là j.
_dp[i][j]: là giá trị lớn nhất của cái túi khi lựa chọn các đồ vật từ 1->i và có trọng lượng là j.
_Tại mỗi bước,hd1: nếu không chọn đồ vật i vào túi có trọng lượng j;
	dp[i][j] = dp[i-1][j];
_nếu chọn vào túi,hd2: khi j >= a[i].first;
	dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].first]+a[i].second);

=>hd1 phải thực hiện trước hd2.
*/

