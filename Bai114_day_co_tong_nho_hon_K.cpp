#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, K;
	cin>>t;
	while(t--)
	{
		cin>>n>>K;
		long long a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		
		long long cnt = 0;
		for(int i = 0; i < n; i++)
		{
			int j = i+1, k = n-1;
			while(j < k)
			{
				if(a[i]+a[j]+a[k] < K)
				{
					cnt += (k-j);
					j++;
				}else{
					k--;
				}
			}
		}
		cout<<cnt<<endl;	
	}
	
	
	return 0;
}