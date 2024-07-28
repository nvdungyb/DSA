#include<bits/stdc++.h>
using namespace std;


int binary_search(int a[],int l,int r)
{
	if(l <= r)
	{
		int mid = (l+r)/2;
		if(a[mid] == 0)
		{
			int ans = binary_search(a,mid+1,r);
			if(ans)
				return ans;
			else
				return mid+1;
		}else{
			int ans = binary_search(a,l,mid-1);
			if(ans)
				return ans;
		}
	}
	return 0;
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
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		cout<<binary_search(a,0,n-1);
		cout<<endl;
	}
 
	
	return 0;
}