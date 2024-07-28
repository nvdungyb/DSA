#include<bits/stdc++.h>
using namespace std;

int n,k,a[20];
bool checkFinal()
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

void genNext()
{
	int i = k;
	while(a[i] == n-k+i)
	{
		i--;
	}
	a[i]++;
	for(int j = i+1; j <= k; j++)
		a[j] = a[j-1]+1;
}

void display()
{
	for(int i = 1; i <= k; i++)
		cout<<a[i];
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
		cin>>n>>k;
		for(int i = 1; i <= k; i++)
			a[i] = i;
			
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