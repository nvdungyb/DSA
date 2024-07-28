#include<bits/stdc++.h>
using namespace std;

int a[105], dp[105][105] = {0}, n, k;

// Function count number of increasing subsequences of size k
// đếm số dãy con tăng dần có độ dài là k.
int count()
{
	int cnt = 0;
	// count of increasing subsequences of size 1 ending at each a[i].
	// mỗi phần tử có độ dài trong dãy con là 1.
	for(int i = 0; i < n; i++)
		dp[1][i] = 1;
	
	// Building up the matrix dp[][], l stand for the size of increasing subsequences of size (l).
	// l đại diện cho dãy con tăng dần độ dài l.
	for(int l = 2; l <= k; l++)
	{
		// for each increasing subsequence of size 'l' ending with element a[i].
		for(int i = 0; i < n; i++)
		{
			// count of increasing subsequences of size 'l' ending with element a[i].
			// đếm số dãy con tăng dần độ dài l ết thúc tại phần tử thứ i.
			dp[l][i] = 0;
			for(int j = 0; j < i; j++)
			{
				if(a[i] > a[j])
					dp[l][i] += dp[l-1][j];
			}
		}
	}
	
	for(int i = k-1; i < n; i++)	// i = 0; still correct
		cnt += dp[k][i];
 
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 1;
	while(t--)
	{
		cin>>n>>k;
		for(int i = 0; i < n; i++)
			cin>>a[i];
			
		cout<<count()<<endl;	
	}
	 
	return 0;
}

// Đây là bài toán quy hoạch động trạng thái.