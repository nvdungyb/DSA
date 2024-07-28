#include<bits/stdc++.h>
using namespace std;

struct val{
	char ans;
	long long num;
};

bool operator < (val a, val b)
{
	return a.num < b.num;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, k;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>k>>s;
		
		map<char, long long>mp;
		mp.clear();
		for(int i = 0; i < s.length(); i++)
		{
			mp[s[i]]++;
		}
		
		priority_queue<val>que;
		for(auto x:mp)
		{
			que.push(val{x.first,x.second});
		}
		
		while(!que.empty() && k > 0)
		{
			val x = que.top();
			que.pop();
			x.num--, k--;
			if(x.num > 0)
				que.push(x);
		}
		
		long long sum = 0;
		while(!que.empty())
		{
			val x = que.top(); 
			que.pop();
			sum += (x.num*x.num);
		}
		
		cout<<sum<<endl;
	}


	return 0;
}

// Lưu ý rằng xâu có thể có độ dài tới 10^6 => phải để kiểu dữ liệu kiểu long long với phép nhân.
/*
int main()
{
 
	int t, k;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>k>>s;
		
		map<int,long long>mp;
		for(int i = 0; i < s.length(); i++)
		{
			mp[(s[i]-'A')]++;
		}
		
		priority_queue<long long>que;
		for(auto x:mp)
		{
			que.push(x.second);
		}
		
		while(!que.empty() && k)
		{
			long long x = que.top(); que.pop();
			x--, k--;
			que.push(x);
		}
		
		long long sum = 0;
		while(!que.empty())
		{
			long long x = que.top(); que.pop();
			sum += (x*x);
		}
		
		cout<<sum<<endl;
	}

	return 0;
}
*/
