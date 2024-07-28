#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long a[1005][1005];

void pre()
{
	for(int i = 1; i <= 1000; i++)
	{
		a[i][1] = i;				// Khởi tạo giá trị đầu tiên P(i,1) = i.
		for(int j = 2; j <= i; j++)
		{
			a[i][j] = ((a[i][j-1]%mod)*((i-j+1)%mod))%mod;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	
	int t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<a[n][k]<<endl;
	}


	return 0;
}


//int main()
//{
//	int t, n, k;
//	cin>>t;
//	while(t--)
//	{
//		cin>>n>>k;
//		long long ans = n;
//		for(int i = 2; i <= k; i++)
//			ans = ((ans%mod)*(n-i+1)%mod)%mod;
//		cout<<ans<<endl;
//	}
//	
//	
//	return 0;
//}
