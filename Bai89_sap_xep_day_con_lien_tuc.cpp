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
		int a[n+5], b[n+5];
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			b[i] = a[i];
 		}
		sort(b,b+n);
		int l = 0, r = n-1;
		
		while(a[l] == b[l])
		{
			l++;
		}
		
		while(a[r] == b[r])
		{
			r--;
		}
		cout<<l+1<<" "<<r+1;
		
		cout<<endl;	
	}
 
	
	return 0;
}