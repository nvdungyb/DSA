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
		int a[n+5];
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			sum += a[i];
		}
		
		if(sum%2 != 0)
			cout<<"NO";
		else{
			int k = sum/2;
			int dp[10001];
			for(int i = 0; i < n; i++)		// Đây là công thức quy hoạch động của bài này.
			{
				dp[a[i]] = 1;
				for(int j = k; j >= a[i]; j--)
				{
					if(dp[j-a[i]] == 1)		// xét từ k tới a[i] xem có giá trị nào + a[i] bằng với phần tử trước của mảng ko?
						dp[j] = 1;
				}							// Hay nói cách khác là xét tất cả các giá trị mà a[i] có thể đạt được khi cộng với tất cả các phần tử khác.
			}	
			if(dp[k] == 1)
				cout<<"YES";
			else
				cout<<"NO";
		}
		cout<<endl;
	}
 
	
	return 0;
}