#include<bits/stdc++.h>
using namespace std;

 
void Plus(string a, string b, int k)
{
	int n = a.length(), m = b.length();
	if(n > m)
	{
		for(int i = 1; i <= n-m; i++)
			b = "0"+b;
	}else{
		for(int i = 1; i <= m-n; i++)
			a = "0"+a;
	}
	
	int tmp = 0, ans;
	for(int i = a.length()-1; i >= 0; i--)
	{
		ans = (b[i]-'0') + (a[i]-'0') + tmp;
		tmp = ans/k;
		a[i] = ans%k + '0';
	}
	if(tmp > 0)
		a = to_string(tmp)+a;
		
	cout<<a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, k;
	cin>>t;
	while(t--)
	{
		string a, b;
		cin>>k>>a>>b;
		Plus(a,b,k);
		
		cout<<endl;
	}


	return 0;
}
