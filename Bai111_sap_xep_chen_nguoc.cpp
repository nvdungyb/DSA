#include<bits/stdc++.h>
using namespace std;

 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, t = 1;
	while(t--)
	{
		cin>>n;
		int a[n+4];
		vector<int>vt[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		for(int i = 0; i < n; i++)
		{
			int key = a[i];
			int j = i-1;
			while(j >= 0 && a[j] >= key)
			{
				a[j+1] = a[j];
				j--;
			}
			a[j+1] = key;
			
			for(int k = 0; k <= i; k++)
				vt[i].push_back(a[k]);
		}
		for(int i = n-1; i >= 0; i--)
		{
			cout<<"Buoc "<<i<<": ";
			for(int j = 0; j <= i; j++)
				cout<<vt[i][j]<<" ";
			cout<<endl;
		}
	}
	 
	
	return 0;
}