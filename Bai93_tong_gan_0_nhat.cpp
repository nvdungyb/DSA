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
		
		int ans = INT_MAX, min;
		for(int i = 0; i < n; i++) 
		{
			for(int j = i+1; j < n; j++)
			{
				if(ans > abs(a[i]+a[j]))
				{
					min = a[i]+a[j];
					ans = abs(a[i]+a[j]);
				}
			}
		}
		cout<<min;
		 
		cout<<endl;	
	}
 
	
	return 0;
}