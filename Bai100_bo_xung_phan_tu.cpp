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
		int a[33000];
		memset(a, 0, sizeof(a));
		int max = INT_MIN, min = INT_MAX, x;
		for(int i = 0; i < n; i++)
		{
			cin>>x;
			a[x]++;
			if(x > max)
				max = x;
			if(x < min)
				min = x;	
		}
		
		int cnt = 0;
		for(int i = min; i <= max; i++)
		{
			if(!a[i])
				cnt++;
		}
		cout<<cnt<<endl;
	}
 
	
	return 0;
}