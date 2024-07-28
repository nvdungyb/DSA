#include<bits/stdc++.h>
using namespace std;


using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		ll a[n+5], b[m+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
			
		for(int i = 0; i < m; i++)
			cin>>b[i];
		
		sort(a,a+n);
		sort(b,b+m);
		
		int l = 0, r = 0;
		while(l < n && r < m)
		{
			if(a[l] < b[r])
			{
				cout<<a[l]<<" ";
				l++;
			}else{
				cout<<b[r]<<" ";
				r++;
			}
		}
		if(l == n)
			for(int i = r; i < m; i++)
				cout<<b[i]<<" ";
		else if(r == m)
			for(int i = l; i < n; i++)
				cout<<a[i]<<" ";
		
		cout<<endl;	
	}
 
	
	return 0;
}