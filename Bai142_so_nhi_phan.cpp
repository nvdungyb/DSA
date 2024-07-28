#include<bits/stdc++.h>
using namespace std;

void genNext(string &s)
{
	int n = s.length()-1;
	int i = n;
	while(s[i] == '1')
	{
		s[i] = '0';
		i--;
	}
	if(i >= 1)
		s[i] = '1';
	else
		s = "1"+s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string s ="1";
		for(int i = 1; i <= n; i++)
		{
			cout<<s<<" ";
			genNext(s);
		}
		cout<<endl;
	}


	return 0;
}
