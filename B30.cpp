#include<bits/stdc++.h>
using namespace std;

using ll = long long;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,k;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>k>>s;
		int n = s.length();
		int a[n] = {0};
		for(int i = 0; i < n; i++)
		{
			a[s[i]-'A']++;
		}
		multiset<int>st;
		for(int x:a)
		{
			st.insert(x);
		}
		
		while(k--)
		{
			int x = *st.rbegin();
			x--;
			st.erase(st.begin());
			st.insert(x);
		}
	 	
	 	for(int x:st)
	 		cout<<x<<" ";
	 	
		cout<<endl;
	}
	
	return 0;
}