#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5], dp1[n+5], dp2[n+5];
		
		for(int i = 0; i < n; i++)
			cin>>a[i];
			
		for(int i = 0; i < n; i++)			// Tìm dãy con tăng dần tới i có tổng lớn nhất.
		{
			dp1[i] = a[i];
			for(int j = 0; j < i; j++)
			{
				if(a[j] < a[i])
					dp1[i] = max(dp1[i], dp1[j]+a[i]);
			}
		}
		
		for(int i = n-1; i >= 0; i--) 		// Tìm dãy con giảm dần tới i có tổng lớn nhất.
		{
			dp2[i] = a[i];
			for(int j = n-1; j > i; j--)
			{
				if(a[j] < a[i])
					dp2[i] = max(dp2[i], dp2[j]+a[i]);
			}
		}
		
		int ans = 1;
		for(int i = 0; i < n; i++)			
		{
			ans = max(ans, dp1[i]+dp2[i]-a[i]);
		}
		
		cout<<ans<<endl;
	}


	return 0;
}
