#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	int t, n, ok;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ok = 0;
		for(int i = n/7; i >= 0; i--)
		{
			int ans = n-7*i;
			if(ans % 4 == 0)
			{
				for(int j = 1; j <= ans/4; j++)
					cout<<"4";
				for(int j = 1; j <= i; j++)
					cout<<"7";
				ok = 1;
			}
			if(ok)
				break;
		}
		
		if(!ok)
			cout<<"-1";
		cout<<endl;
	}


	return 0;
}
