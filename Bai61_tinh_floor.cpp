#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long a[n+5];
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
		}
		
		long long ans = INT_MIN;
		int index = -1;
		for(int i = 0; i < n; i++)
		{
			if(a[i] <= k && a[i] > ans)
			{
				ans = a[i];
				index = i+1;
			}
		}
		cout<<index;
			
		cout<<endl;
	}
 
	
	return 0;
}