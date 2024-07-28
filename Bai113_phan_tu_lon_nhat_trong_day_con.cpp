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
		
		multiset<int>st;
		for(int i = 0; i < k; i++)
			st.insert(a[i]);
		
		cout<<*st.rbegin()<<" ";
		for(int i = k; i < n; i++)
		{
			auto it = st.find(a[i-k]);
			if(it != st.end())
				st.erase(it);
			st.insert(a[i]);
			cout<<*st.rbegin()<<" ";
		}
		cout<<endl;
	}
 
	
	return 0;
}