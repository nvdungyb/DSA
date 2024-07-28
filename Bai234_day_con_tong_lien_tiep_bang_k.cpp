#include<bits/stdc++.h>
using namespace std;


int main()	
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	long long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long a[n+5];
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		long long sum = 0;
		int l = 1, j = 1, ok = 0;
		while(sum < k && l <= n)
		{
			sum += a[l];
			l++;
			 
			while(sum > k)
			{
				sum -= a[j];
				j++;
			}
			
			if(sum == k){
				ok = 1;
				break;
			}
		}
	
		if(ok)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
	

	return 0;
}
