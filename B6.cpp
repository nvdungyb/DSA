#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<int>a(1000000);
		for(int i = 0; i < n; i++)
		{
			int x;
			cin>>x;
			a[x]++;
		}
		for(int i = 1; i <= 1000000; i++)
		{
			if(a[i]%2 == 1)
			{
				cout<<i;
				break;
			}
		}
		cout<<endl;
	}
	
	
	return 0;
}