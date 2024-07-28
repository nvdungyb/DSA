#include<bits/stdc++.h>
using namespace std;

int count(int a[], int n)
{
	int l = 1, r = n;
	int ans = 0;
	while(l < r)
	{
		int mid = (l+r)/2;
		if(a[mid] == 0)
		{
			ans = mid;
			l++;
		}else{
			if(a[mid] == 1)
			{
				r = mid;
			}else{
				ans = mid;
				l = mid;
			}
		}
	}
	return ans;
}

int main()
{
	int t;
 
	cin>>t;
	while(t--)
	{
	 	int n;
	 	cin>>n;
	 	int a[n+1];
	 	for(int i = 1; i <= n; i++)
	 		cin>>a[i];
	 	
	 	cout<<count(a,n)<<endl;
	}
	
	
	return 0;
}