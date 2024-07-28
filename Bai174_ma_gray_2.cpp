#include<bits/stdc++.h>
using namespace std;

// chuyển từ mã gray sang xâu nhị phân.

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
			if(s[i]=='0')
				a[i] = 0;
			else
				a[i] = 1;
		}
		
		for(int i = 1; i < n; i++)
		{
			int ans = a[i];
			if(ans == 0)
				a[i] = a[i-1];
			else{
				if(a[i-1] == 0)
					a[i] = 1;
				else
					a[i] = 0;
			}
		}
		
		for(int i = 0; i < n; i++)
			cout<<a[i];
			
		cout<<endl;
	}


	return 0;
}
