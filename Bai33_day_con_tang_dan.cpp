#include<bits/stdc++.h>
using namespace std;


int n, a[25], x[25];
set<string> st;

void insert(int k)
{
	string ans = "";
	ans = to_string(a[x[1]]);
	for(int i = 2; i <= k; i++)
	{
		ans = ans + " " + to_string(a[x[i]]);
	}
	
	st.insert(ans);
}

void Try(int i)
{
	for(int j = x[i-1]+1; j <= n; j++)
	{
		x[i] = j;
		if(a[x[i]] > a[x[i-1]])
		{
			if(i > 1)
				insert(i);
			Try(i+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	
	Try(1);
	
	for(string x : st)
		cout<<x<<endl;


	return 0;
}
