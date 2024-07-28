#include<bits/stdc++.h>
using namespace std;

int k;

bool binary_search(int a[], int l, int r)
{
	if(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] == k)	
			return true;
		else if(a[mid] < k)
		{
			return binary_search(a,mid+1,r);
		}else{
			return binary_search(a,l,mid-1);
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		if(binary_search(a,0,n-1))
			cout<<"1";
		else
			cout<<"-1";
		
		cout<<endl;
	}
	
	
	return 0;
}