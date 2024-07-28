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
	
	int n, t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n+4];
		vector<int>vt[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n-i-1; j++)
			{
				if(a[j] >= a[j+1])
					swap(a[j],a[j+1]);
			}
			cnt++;
			for(int k = 0; k < n; k++)
			{
				vt[i].push_back(a[k]);
			}
				
			if(check(a,n))
				break;
		}
		
		for(int i = cnt-1; i >=0; i--)
		{
			cout<<"Buoc "<<i+1<<": ";
			for(int j = 0; j < n; j++)
				cout<<vt[i][j]<<" ";
			cout<<endl;
		}
	}
	 
	
	return 0;
}