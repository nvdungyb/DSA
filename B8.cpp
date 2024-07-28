#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		int ans = INT_MIN;
		vector<int>vt;
		for(int i = n-1; i >= 0; i--)
		{
			if(a[i]>ans)
				vt.push_back(a[i]);
			ans = max(ans,a[i]);
		}
		for(auto it = vt.rbegin();it != vt.rend(); it++)
			cout<<*it<<" ";
		
		cout<<endl;
	}
	
	return 0;
}