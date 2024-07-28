#include<bits/stdc++.h>
using namespace std;

bool check(string s)
{
	int n = s.length();
	for(int i = 0; i < n; i++)
	{
		if(s[i] != '0' && s[i] != '1' && s[i] != '2')
			return false;
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
		cin>>s;
		if(check(s))
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	
	return 0;
}