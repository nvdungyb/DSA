#include<bits/stdc++.h>
using namespace std;


bool checkFinal(int a[],int n)
{
	int i = n;
	while(a[i] == 1)
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

bool check(int a[],int b[],int n,int k)
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += a[i]*b[i];
	}
	if(ans == k)
		return true;
	return false;
}

void display(int a[],int b[],int n)
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i])
			cout<<b[i]<<" ";
	}
	cout<<endl;
}

void genNext(int a[],int n)
{
	int i = n;
	while(a[i])
	{
		a[i] = 0;
		i--;
	}
	a[i] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	cin>>n>>k;
	int b[n+5],a[n+5];
	for(int i = 1; i <= n; i++)
	{
		cin>>b[i];
		a[i] = 0;
	}
	
	int cnt = 0;
	while(!checkFinal(a,n))
	{
		if(check(a,b,n,k))
		{
			display(a,b,n);
			cnt++;
		}
		genNext(a,n);
	}
	cout<<cnt;
	
	
	return 0;
}