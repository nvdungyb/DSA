#include<bits/stdc++.h>
using namespace std;

int n, k;

int binary_search(int a[],int l, int r)
{
	if(l<=r)
	{
		int mid = (l+r)/2;
		if(a[mid] == k)
			return mid+1;
		else if(a[mid] > k)
			return binary_search(a,l,mid-1);
		else 
			return binary_search(a,mid+1,r);	
	}	
	return -1;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i]; 
		
		int ans = binary_search(a,0,n-1);
		if(ans == -1)
			cout<<"NO";
		else
			cout<<ans;
			
		cout<<endl;
	}
 
	
	return 0;
}