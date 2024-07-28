#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	int a[n+5];
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	
	long long sum = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > 0)
			sum += a[i]*2;
	}
	cout<<sum;
	

	return 0;
}
