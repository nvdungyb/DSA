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
		
		for(int i = 0; i < n-1; i++)
		{
			int min = i;
			for(int j = i+1; j < n; j++)
			{
				if(a[j] < a[min] )
				{
					min = j;
				}
			}
			
			if(a[min] != a[i])
				swap(a[i],a[min]);
			
			for(int k = 0; k < n; k++)
				vt[i+1].push_back(a[k]);
		}
		for(int i = n-1; i >= 1; i--)
		{
			cout<<"Buoc "<<i<<": ";
			for(int j = 0; j < n; j++)
				cout<<vt[i][j]<<" ";
			cout<<endl;
		}
	}
	 
	
	return 0;
}