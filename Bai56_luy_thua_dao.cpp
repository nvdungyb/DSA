#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

// Dùng cách dequi này vẫn đảm bảo nhất đối với số n lớn.
// Có thể áp dụng tương tự khi lũy thừa ma trận.

long long luyThua(long long n,long long k)
{
	if(k == 0)
		return 1;
	if(k == 1)
		return n%mod;
	
	long long ans = luyThua(n,k/2);
	ans = ans*ans%mod;
	if(k%2)
		ans = ans*n%mod;
		
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long k = 0, tmp = n;
		while(tmp)
		{
			int ans = tmp%10;
			k = k*10 + ans;
			tmp /= 10;
		}
		cout<< luyThua(n,k)<<endl;
	}
 
	
	return 0;
}