#include<bits/stdc++.h>
using namespace std;

int n,a[20];
void init()
{
	for(int i = 1; i <= n; i++)
		a[i] = n-i+1;
}

bool checkFinal()
{
	int i=n-1;
	while(a[i] < a[i+1] && i >= 1)
	{
		i--;
	}
	if(i == 0)
		return true;
	return false;
}

void genNext()
{
	int i = n-1;
	while(a[i] < a[i+1])
	{
		i--;
	}
	int j = n;
	while(a[i] < a[j])
	{
		j--;
	}
	swap(a[i],a[j]);
	int l = i+1,r = n;
	while(l < r)
	{
		swap(a[l],a[r]);
		l++,r--;
	}
}

void display()
{
	for(int i = 1; i <= n; i++)
		cout<<a[i];
	cout<<" ";
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		init();
		display();
		while(!checkFinal())
		{
			genNext();
			display();
		}
		cout<<endl;
	}
	
	return 0;
}