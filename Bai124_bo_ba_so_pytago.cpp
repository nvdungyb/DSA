#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int lower_bound(ll a[],int l,int r, ll x)
{
	if(l <= r)
	{
		ll mid = (l+r)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid] > x)
			return lower_bound(a,l,mid-1,x);
		else
			return lower_bound(a,mid+1,r,x);
	}
	return 0;
}

bool check(ll a[],int n)
{
	for(ll i = 0; i < n; i++)
	{
		for(ll j = i+1; j < n; j++)
		{
			long long tam = a[i]*a[i] + a[j]*a[j];
			long long ans = sqrt(tam);
			if(ans*ans == tam)
			{
				ll k = lower_bound(a,j+1,n-1,ans);
				if(k)
					return true;
			}
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
		cin>>n;
		ll a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		if(check(a,n))
			cout<<"YES";
		else
			cout<<"NO";
		
		cout<<endl;
	}
 
	
	return 0;
}