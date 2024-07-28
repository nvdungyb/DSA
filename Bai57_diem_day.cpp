#include<bits/stdc++.h>
using namespace std;

#define mod 123456789

// Mỗi số n có 2^(n-1) cách phân tích thành tổng các số <= n có xét cả thứ tự.
// S(n): số dãy số nguyên dương có tổng các phần tử trong dãy bằng n: 
// S(n) = S(1) + S(2) +... +S(n-2) + S(n-1) = [ S(1) + S(2) +... +S(n-2) ] + S(n-1) = S(n-1) + S(n-1) = 2[S(n-1)] => S(n) = 2[2*S(n-2)]. 
//       Quy luật : với S(n) thì ra được: 2^1 lần S(n-1), 2^2 lần S(n-2), ...., 2^(n-1) lần S(n-(n -1)) = S(1) = 1 ( Với 1 là bài toán con: n = 1 có 1 dãy) => S(n) = 2^(n-1).
 
long long mul(int n)
{
	int k = n;
	long long resul = 1;
	long long ans = 2;
	while(k)
	{
		if(k%2)
		{ 
			resul *= ans;
			resul %= mod;	
		}
		ans *= ans;
		ans %= mod;
		k /= 2;
	}
	return resul;
}

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
		cout<<mul(n-1)<<endl;
	}


	return 0;
}
