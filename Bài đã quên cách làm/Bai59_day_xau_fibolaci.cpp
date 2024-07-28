#include<bits/stdc++.h>
using namespace std;

long long fib[94];

char find(int n,long long k)
{
	if(n == 1)
		return 'A';
	if(n == 2)
		return 'B';
	if(k <= fib[n-2])
		return find(n-2,k);
	else
		return find(n-1,k-fib[n-2]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i < 93; i++)
	{
		fib[i] = fib[i-1]+fib[i-2];
	}
	int t, n; 
	long long k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		cout<<find(n,k)<<endl;
	}
	
	
	return 0;
}