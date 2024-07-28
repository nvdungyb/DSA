#include<bits/stdc++.h>
using namespace std;

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
			int x = que.top(); que.pop();
			int y = que.top(); que.pop();
			que.push(x+y);
			ans += (x+y);
		}
		cout<<ans<<endl;
	}


	return 0;
}
