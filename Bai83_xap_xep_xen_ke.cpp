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
		
		sort(a,a+n);
		
		int l = 0, r = n-1;
		while(l < r)
		{
			cout<<a[r]<<" "<<a[l]<<" ";
			r--,l++;
		}
		if(l == r)
			cout<<a[l];
		cout<<endl;
	}
	
 
	return 0;
}