#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 1,n;
	while(t--)
	{
		cin>>n;
		int a[n+2][n+2];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cin>>a[i][j];
		}
		
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				if(a[i][j])
					cout<<j+1<<" ";
			cout<<endl;
		}
	}
	
	return 0;
}