#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int i = s.length()-1;
		while(s[i] == '0' && i >= 0)
		{
			s[i] = '1';
			i--;
		}
		if(i >= 0)
			s[i] = '0';
		cout<<s<<endl;
	}
	
	return 0;
}