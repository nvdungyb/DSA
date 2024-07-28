#include<bits/stdc++.h>
using namespace std;


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
		
		int a[n+5], ans = 1;
		for(int i = 0; i < n; i++)
		{
			int l = i, r = i;
			while(s[l] == s[r] && l >= 0 && r < n)
			{
				ans = max(ans,r-l+1);
				l--, r++;
			}
		}
		
		for(int i = 0; i < n; i++)
		{
			int l = i, r = i+1;
			while(s[l] == s[r] && l >= 0 && r < n)
			{
				ans = max(ans,r-l+1);
				r++, l--;
			}
		}
		
		cout<<ans<<endl;
	}


	return 0;
}
