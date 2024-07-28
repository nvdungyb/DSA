#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// => bài này mà còn không nghĩ ra, mình kém đi rồi sao?

int k;
  
ll soluttion(ll a[], int n)
{
	sort(a,a+n);
	ll cnt = 0;
	for(int i = 0; i < n; i++)
	{
		ll x = k - a[i];
		ll y = lower_bound(a+i+1, a+n, x) - a;	
		ll z = upper_bound(a+i+1, a+n, x) - a;
		cnt += z-y;
	}	
	
	return cnt;
}

// Độ phức tạp của upper_bound() hoặc lower_bound() là log(n) => độ phức tạp của thuật toán là O(nlogn).

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll a[n+5];
		for(int i = 0; i < n; i++)	
			cin>>a[i];
		
		cout<<soluttion(a,n);
		cout<<endl;
	}
	
	
	return 0;
}