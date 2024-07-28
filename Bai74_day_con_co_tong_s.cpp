#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		int b[40005]={1};					// khởi tạo các tập rỗng luôn là true.
		for(int i = 0; i < n; i++)
		{
			for(int j = k; j >= a[i]; j--)
			{
				if(b[j-a[i]] == 1)
					b[j] = 1;	
			}	
		}	
		if(b[k] == 1)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}


	return 0;
}