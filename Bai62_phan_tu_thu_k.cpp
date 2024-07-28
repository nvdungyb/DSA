#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, m, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		int a[n+5], b[m+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < m; i++)
			cin>>b[i];
		
		int i = 0, j = 0, ans = 0;
		while(i < n && j < m)
		{
			ans++;
			if(a[i] <= b[j])
			{
				if(ans == k)
				{
					cout<<a[i];
					break;
				}
				i++;
			}else{
				if(ans == k)
				{
					cout<<b[j];
					break;
				}
				j++;
			}
		}
		
		while(i < n && ans < k)
		{
			ans++;
			if(ans == k)	
				cout<<a[i];
			i++;
		}
		
		while(j < m && ans < k)
		{
			ans++;
			if(ans == k)
				cout<<b[j];
			j++;
		}
		
		cout<<endl;
	}
 
	
	return 0;
}