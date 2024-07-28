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

bool check(int a[],int n)
{
	int l = 1, r = n;
	while(l <= r)
	{
		if(a[l] == a[r])
		{
			l++, r--;
		}else{
			return false;
		}
	}
	return true;
}

void display(int a[],int n)
{
	for(int i = 1; i <= n; i++)
		cout<<a[i]<<" ";
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

void sinh(int n)
{
	int a[n+5];
	for(int i = 1; i <= n; i++)
		a[i] = 0;
	
	while(!checkFinal(a,n))	
	{
		if(check(a,n))
			display(a,n);
		genNext(a,n);
	}
	display(a,n);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	sinh(n);

	
	return 0;
}