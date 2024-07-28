#include<bits/stdc++.h>
using namespace std;

int k;
int binary_search(int a[], int l, int r)
{
	if(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] == k)	
			return mid+1;
		else if(a[mid] < k)
		{
			return binary_search(a,mid+1,r);
		}else{
			return binary_search(a,l,mid-1);
		}
	}
	return -1;
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
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			if(i >= 1)
			{
				if(ans <= a[i-1])
					ans = i;
			}		
		}
		
		int resul1 = binary_search(a,0,ans-1);
		int resul2 = binary_search(a,ans,n-1);
		if(resul1 != -1)
			cout<<resul1;
		if(resul2 != -1)
			cout<<resul2;
		
		cout<<endl;
	}
	
	
	return 0;
}