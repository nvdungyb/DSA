#include<bits/stdc++.h>
using namespace std;

int n,k,a[20];

bool checkFinal()
{
	int i = n;
	while(a[i] && i >= 1)
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

bool check()
{
	if(!a[1] || a[n])
		return false;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] == a[i+1] && a[i] == 1)
			return false;
	}
	for(int i = 1; i <= n-3; i++)
	{
		if(a[i] == a[i+1] && a[i+1] == a[i+2] && a[i+2] == a[i+3] && a[i] == 0)
		return false;
	}
	return true;
}

void genNext()
{
	int i = n;
	while(a[i])
	{
		a[i] = 0;
		i--;
	}
	a[i] = 1;
}

void display()
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i])
			cout<<"8";
		else
			cout<<"6";
	}
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 1;
	while(t--)
	{
		cin>>n;
		if(n >= 6)
		{
			for(int i = 1; i <= n; i++)
				a[i] = 0;
			
			while(!checkFinal())
			{
				if(check())
					display();
				genNext();
			}
		}
	}
	
	return 0;
}