#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

// Khai báo một đối tượng hàm so sánh.
struct cmp{
	bool operator ()(long long a, long long b)
	{
		return a > b;
	}
};

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
		priority_queue<long long,vector<long long>,greater<long long>> que; 	// đây là cách khai báo đầy đủ của priority_queue.
		int x;
		for(int i = 0; i < n; i++)								// lưu ý khi sử dụng hàm 
		{
			cin>>x;
			que.push(x);
		}
		
		long long ans = 0;
		while(que.size() >= 2)
		{
			long long x = que.top(); que.pop();
			long long y = que.top(); que.pop();
			long long tam = (x+y)%mod;
			que.push(tam);
			ans += tam;
			ans %= mod;
		}
		cout<<ans<<endl;
	}


	return 0;
}
