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
		int a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		sort(a,a+n);
		int min1 = a[0];
		int j = 0;
		while(a[j] == min1 && j < n)
		{
			j++;
		}
		if(j == n)
			cout<<"-1";
		else
			cout<<min1<<" "<<a[j];
			
		cout<<endl;	
	}
 
	
	return 0;
}