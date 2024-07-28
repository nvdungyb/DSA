#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	int a[n+4];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	
	for(int i = 0; i < n; i++)
	{
		int key = a[i];
		int j = i-1;
		while(j >= 0 && a[j] >= key)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = key;
		
		cout<<"Buoc "<<i<<": ";
		for(int k = 0; k <= i; k++)
			cout<<a[k]<<" ";
		cout<<endl;
	}
 
	
	return 0;
}