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

void genNext()
{
	int i = n;
	while(a[i])
	{
		a[i] = 0;
		i--;
	}
	a[i]++;
}

void display()
{
	for(int i = 1; i <= n; i++)
	{
		if(a[i])
			cout<<"B";
		else
			cout<<"A";
	}
	cout<<" ";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1; i <= n; i++)
			a[i] = 0;
		
		while(!checkFinal())
		{
			display();
			genNext();
		}
		display();
		cout<<endl;
	}
	
	return 0;
}