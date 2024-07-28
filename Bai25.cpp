#include<bits/stdc++.h>
using namespace std;

int n;
int a[15];

void display(int i)
{
	cout<<"[";
	for(int j = i; j < n; j++)
		cout<<a[j]<<" ";
	cout<<a[n]<<"] ";
}

void Try(int i)
{
	if(i < n){
		for(int j = n; j >= i; j--)
			a[j] += a[j-1];
		Try(i+1);
	}
	
	if(i < n){
		for(int j = i; j <= n; j++)
			a[j] -= a[j-1];
	}
	display(i);
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
			cin>>a[i];
		
		Try(1);	
		cout<<endl;
	}


	return 0;
}
