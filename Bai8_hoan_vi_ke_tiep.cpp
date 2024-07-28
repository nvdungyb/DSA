#include<bits/stdc++.h>
using namespace std;

bool checkFinal(int a[],int n)
{
	int i = n-1;
	while(a[i]>a[i+1])
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

void next(int a[],int n)
{
	if(checkFinal(a,n))
	{
		for(int i = 1; i <= n; i++)
			cout<<i<<" ";
	}else{
		int i = n-1;
		while(a[i]>a[i+1])
		{
			i--;
		}
		int j = n;
		while(a[i]>a[j])
		{
			j--;
		}
		swap(a[i],a[j]);
		int l = i+1,r = n;
		while(l<r)
		{
			swap(a[l],a[r]);
			l++,r--;
		}
		
		for(int i = 1; i <= n; i++)
			cout<<a[i]<<" ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		next(a,n);
		cout<<endl;
	}
 
	
	return 0;
}