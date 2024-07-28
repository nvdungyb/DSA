#include<bits/stdc++.h>
using namespace std;

bool check(int a[], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		if(a[i] > a[i+1])
			return false;
	}
	return true;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	int a[n+5];
	for(int i = 0; i < n; i++)
		cin>>a[i];
		
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-i-1; j++)
		{
		 	if(a[j] > a[j+1])
		 		swap(a[j],a[j+1]);
		}
	
		cout<<"Buoc "<<i+1<<": ";
		for(int k = 0; k < n; k++)
			cout<<a[k]<<" ";
		
		if(check(a,n))
			break;
			
		cout<<endl;	
	}	
 
	
	return 0;
}