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
		s = " "+s;
		
		int a[n+5][n+5];			// ma trận lưu kết quả, a[i][j] ứng với xâu bắt đầu từ i đến j.
		memset(a, 0, sizeof(a));	
		for(int i = 1; i <= n; i++)	// xâu con có độ dài là 1 là xâu đối xứng, đây là cơ sở của công thức qhd này.
			a[i][i] = 1;
		
		int ans = 1;
		for(int len = 2; len <= n; len++)	// len thể hiện độ dài của xâu đối xứng.
		{
			for(int i = 1; i <= n-len+1; i++)	// vị trí bắt đầu của xâu đối xứng.
			{		
				int j = i+len-1;				// vị trí kết thúc của xâu đối xứng.
				if(len == 2 && s[i] == s[j])	// th xâu đối xứng có độ dài bằng 2.
					a[i][j] = 1;
				else if(s[i] == s[j] && a[i+1][j-1])
					a[i][j] = 1;
				
				if(a[i][j])
					ans = max(ans, len);
			}
		}
		
		cout<<ans<<endl;
	}
	

	return 0;
}

// Giang hồ đồn đại còn cách hay hơn cả quy hoạch động trạng thái.
