#include<bits/stdc++.h>
using namespace std;

int n, a[15];

bool checkFinal()
{
	int i = n-1;
	while(a[i] > a[i+1] && i >= 1)
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
	while(a[i] > a[i+1])
	{
		i--;
	}
	int j = n;
	while(a[i] > a[j])
	{
		j--;
	}
	swap(a[i],a[j]);
	int l = i+1, r = n;
	while(l < r)
	{
		swap(a[l],a[r]);
		l++,r--;
	}
}

void display()
{
	for(int i = 1; i <= n; i++)
		cout<<a[i]<<" ";
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
		for(int i = 1; i <= n; i++)
			cin>>a[i];
		
		sort(a+1,a+n+1);
		
		while(!checkFinal())
		{
			display();
			genNext();
		}
		display();
	}
	
	return 0;
}