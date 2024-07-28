#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

 	int t, n, k;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n>>k;
 		int a[n+5];
 		for(int i = 0; i < n; i++)
 			cin>>a[i];
 		
 		int sum1  = 0, sum2 = 0;
 		sort(a,a+n);
 		int ans = max(k,n-k);
 		for(int i = 0; i < n-ans; i++)
 			sum1+=a[i];
 		for(int i = n-ans; i < n; i++)
 			sum2+=a[i];
 		
 		cout<<sum2-sum1;
 		 
		cout<<endl;		
	}
	
	return 0;
}