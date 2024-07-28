#include<bits/stdc++.h>
using namespace std;

 
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
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
			
		int sum = 0, ans = 0;
		for(int i = 0; i < n; i++)
		{
			sum+=a[i];
			ans = max(sum,ans);
			if(sum < 0)
				sum = 0;
		}
		cout<<ans<<endl;
	}
 
	
	return 0;
}