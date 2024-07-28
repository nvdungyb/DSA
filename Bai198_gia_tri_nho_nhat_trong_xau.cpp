#include<bits/stdc++.h>
using namespace std;

int k;

struct val{
	char key;
	int num;
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
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>k;
		string s;
		cin>>s;
		
		map<char,int> mp;
		for(int i = 0; i < s.length(); i++)
			mp[s[i]]++;
		
		priority_queue<val> que;
		
		for(auto x:mp)
		{
			que.push(val{x.first,x.second});
		}
		
		while(k--)
		{
			val tam = que.top(); que.pop();
			tam.num--;
			que.push(tam);
		}
		
		long long sum = 0;
		while(!que.empty())
		{
			val ans = que.top(); que.pop();
			sum += (ans.num*ans.num);
		}
		
		cout<<sum<<endl;
	}


	return 0;
}
