#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();
		for(int i = 0; i < n; i++)
		{
			int l = i;
			while(s[l] == s[i] && l<n)
			{
				l++;
			}
			cout<<s[i]<<l-i;
			i = l-1;
		}
		cout<<endl;
	}
	
	
	return 0;
}