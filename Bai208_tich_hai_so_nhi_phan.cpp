#include<bits/stdc++.h>
using namespace std;

void mul(string a, string b)
{
	long long a_ans = 0, b_ans = 0;
	long long tmp = 1;
	for(int i = a.length()-1; i >= 0; i--)
	{
		if(a[i] == '1')
			a_ans += tmp;
		tmp *= 2;
	}
	tmp = 1;
	for(int i = b.length()-1; i >= 0; i--)
	{
		if(b[i] == '1')
			b_ans += tmp;
		tmp *= 2;
	}
	cout<<a_ans*b_ans;
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
		string a,b;
		cin>>a>>b;
		mul(a,b);
		cout<<endl;
	}


	return 0;
}
