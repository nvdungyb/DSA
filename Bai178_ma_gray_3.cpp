#include<bits/stdc++.h>
using namespace std;

// chuyển từ xâu nhị phân sang mã grey;

int a[15];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int n = s.length();
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
				a[i] = 0;
			else
				a[i] = 1;
		}
		
		cout<<a[0];
		for(int i = 1; i < n; i++)
		{
			int ans = a[i]^a[i-1];
			cout<<ans;
		}
		
		cout<<endl;
	}


	return 0;
}
