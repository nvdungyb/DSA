#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long count(int a[],int n,int k)
{
	long long f[1005];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for(int i = 1; i <= k; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(a[j] <= i)
			{
				f[i] = (f[i] + f[i-a[j]])%mod;
			} 
		}
	}
	return f[k];
}

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
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		cout<<count(a,n,k)<<endl;
		
	}


	return 0;
}

// f[i] là số cách lấy phần tử trong mảng để có tổng bằng i.