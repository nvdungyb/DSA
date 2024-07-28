#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

 	int t, n;
 	cin>>t;
 	while(t--)
 	{
 		cin>>n;
 		int a[n+5], b[n+5];
 		for(int i = 0; i < n; i++)
 		{
 			cin>>a[i];
 			b[i] = a[i];
		}
		
		sort(b,b+n);
		
		int check = 0;
		for(int i = 0; i < n; i++)
		{
			if(a[i] != b[i] && a[n-i-1] != b[i])
			{
			    check = 1;
			    break;
			}
		}
		if(!check)
		    cout<<"Yes";
		else    
		    cout<<"No";
 		 
		cout<<endl;		
	}
	
	return 0;
}