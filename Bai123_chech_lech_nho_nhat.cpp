#include<bits/stdc++.h>
using namespace std;
 

void radixSort(int a[],int n)
{
	int m = a[0], exp = 1, b[n];
	for(int i = 1; i < n; i++)
		m = max(m,a[i]);
		
	while(m/exp > 0)
	{
		int bucket[10];
		memset(bucket, 0, sizeof(bucket));
		for(int i = 0; i < n; i++)
			bucket[(a[i]/exp)%10]++;
		
		for(int i = 1; i < 10; i++)	
			bucket[i] += bucket[i-1];
		
		for(int i = n-1; i >= 0; i--)
			b[--bucket[(a[i]/exp)%10]] = a[i];
		
		for(int i = 0; i < n; i++)
			a[i] = b[i];
		
		exp *= 10;
	}	
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
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
			
		radixSort(a,n);
		
		int ans = INT_MAX;
		for(int i = 1; i < n; i++)
			ans = min(ans,a[i]-a[i-1]);
			
		cout<<ans <<endl;
	}
 
	
	return 0;
}