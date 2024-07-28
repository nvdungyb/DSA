#include<bits/stdc++.h>
using namespace std;

int MIN(string a,string b)
{
	int a_n = a.length()-1;
	int b_n = b.length()-1;
	int i = a_n;
	while(i>=0)
	{
		if(a[i] == '6')
			a[i] = '5';
		i--;
	}
	i = b_n;
	while(i>=0)
	{
		if(b[i]=='6')
			b[i] = '5';
		i--;
	}
	int ans = stol(a) + stol(b);
	return ans;
}

int MAX(string a,string b)
{
	int a_n = a.length()-1;
	int b_n = b.length()-1;
	int i = a_n;
	while(i >= 0)
	{
		if(a[i] == '5')
			a[i] = '6';
		i--;
	}
	i = b_n;
	while(i>=0)
	{
		if(b[i]=='5')
			b[i] = '6';
		i--;
	}
	int ans = stol(a) + stol(b);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string a, b;
	cin>>a>>b;
	int c = MIN(a,b);
	int d = MAX(a,b);
	cout<<c<<" "<<d;
 
	return 0;
}