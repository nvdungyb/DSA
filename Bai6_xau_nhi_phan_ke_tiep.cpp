#include<bits/stdc++.h>
using namespace std;

void next(string s)
{
	int n = s.length()-1;
	while(s[n] == '1' && n >= 0)
	{
		s[n] = '0';
		n--;
	}
	if(n == -1)
	{
		s[n] = 0;
		cout<<s;
	}else{
		s[n] = '1';
		cout<<s;
	}
}

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
		next(s);
		cout<<endl;
	}
	
	
	return 0;
}