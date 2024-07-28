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
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				if(a[i]+a[j] == k)
					cnt++;
			}
		}
		cout<<cnt;
		
		cout<<endl;	
	}
 
	
	return 0;
}