#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string s;
		cin>>s;
		
		map<char,int>mp;
		int n = s.length();
		for(int i = 0; i < n; i++)
			mp[s[i]]++;
		
		int ans = 0;
		for(auto x:mp)
			ans = max(ans, x.second);
		
		if(ans <= (n+1)/2)
			cout<<"1";
		else
			cout<<"-1";
	
		cout<<endl;
	}


	return 0;
}
