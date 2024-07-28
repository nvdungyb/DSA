#include<bits/stdc++.h>
using namespace std;


bool checkFinal(int a[],int n, int k)
{
	int i = k;
	while(a[i] == n-k+i)
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

void next(int a[],int n, int k)
{
	if(checkFinal(a,n,k))
	{
		for(int i = 1; i <= k; i++)
			cout<<i<<" ";
	}else{
		int i = k;
		while(a[i] == n-k+i)
		{
			i--;
		}
		a[i]++;
		for(int j = i+1; j <= k; j++)
			a[j] = a[j-1]+1;
		
		for(int i = 1; i <= k; i++)
			cout<<a[i]<<" ";
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n+5];
		for(int i = 1; i <= k; i++)
			cin>>a[i];
		
		next(a,n,k);
		cout<<endl;
	}
	
	
	return 0;
}