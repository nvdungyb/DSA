#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int n = s.length();
		int res = 1;
		for(int i = 0; i < n; i++)
		{
			int j = i, v = i;			// th: xâu đối xứng có độ dài lẻ, đối xứng qua phần tử i.
			while(j >= 0 && v < n)
			{
				if(s[j] == s[v])
				{
					res = max(res,v-j+1);
					j--, v++;
				}else
					break;
			}
		}
		
		for(int i = 0; i < n; i++)		// th: xâu đối xứng có độ dài chẵn.
		{
			int j = i, v = i+1;
			while(j >= 0 && v < n)
			{
				if(s[j] == s[v])
				{
					res = max(res, v-j+1);
					j--, v++;
				}else
					break;
			}
		}
		
		cout<<res<<endl;
	}
	

	return 0;
}
