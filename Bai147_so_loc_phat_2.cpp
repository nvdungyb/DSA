#include<bits/stdc++.h>
using namespace std;

int k;

void display(int a[])
{
	for(int i = 1; i <= k; i++)
	{
		if(a[i])
			cout<<"8";
		else
			cout<<"6";
	}
	cout<<" ";
}

void Try(int a[],int i)
{
	for(int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if(i == k)
			display(a);
		else
			Try(a,i+1);	
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
	
		for(int i =  1; i <= n; i++)
		{
			memset(a, 0, sizeof(a));
			k = i;
			Try(a,1);
		}
		cout<<endl;
	}


	return 0;
}
