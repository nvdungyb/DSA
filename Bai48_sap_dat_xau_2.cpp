#include<bits/stdc++.h>
using namespace std;

int d;

struct val{
	char k;
	int value;
};

bool operator < (val a, val b)
{
	return a.value < b.value;
}

bool check(priority_queue<val>que, bool visited[], string s)
{
	int n = s.length();
	while(!que.empty())
	{
		val x = que.top(); que.pop(); 
		for(int i = 0; i < n; i++)
		{
			int ans = 0;
			if(!visited[i])
			{
				while(i < n)
				{
					x.value--;
					visited[i] = true;
					i = i+d;
					if(x.value == 0)
					{
						ans = 1;
						break;
					}
				}
				if(i >= n && x.value > 0)
				{
					return false;
				}
			}
			if(ans)
				break;
		}
	}
	return true;
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
		string s;
		cin>>d;
		cin.ignore();
		cin>>s;
		int n = s.length();
		bool visited[n];
		memset(visited, false, sizeof(false));
		
		
		map<char,int>mp;
		for(int i = 0; i < n; i++)
			mp[s[i]]++;
		
		priority_queue<val> que;
		for(auto x:mp)
		{
			que.push(val{x.first,x.second});
		}
		
		if(check(que, visited, s))
			cout<<"1";
		else
			cout<<"-1";
		
		cout<<endl;
	}


	return 0;
}
