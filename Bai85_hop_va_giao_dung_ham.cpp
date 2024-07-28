#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t,n,m;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		int a[n], b[m];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		for(int i = 0; i < m; i++)
			cin>>b[i];
		
		sort(a,a+n);
		sort(b,b+m);
		
		vector<int>vt1(n+m);
		vector<int>vt2(n+m);
		vector<int>::iterator it;
		it = set_union(a, a+n, b, b+m, vt1.begin());
		vt1.resize(it-vt1.begin());
		
		for(auto x:vt1)
			cout<<x<<" ";
		
		cout<<endl;
		
		it = set_intersection(a, a+n, b, b+m, vt2.begin());	
		vt2.resize(it-vt2.begin());
		for(auto x:vt2)
			cout<<x<<" ";
		
		cout<<endl;
	}
	
	return 0;
}