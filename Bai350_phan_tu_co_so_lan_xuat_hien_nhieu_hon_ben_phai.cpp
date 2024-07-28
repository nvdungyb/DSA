#include<bits/stdc++.h>
using namespace std;


// Phần tử gần nhất bên phải, có số lần xuất hiện lớn hơn nó.
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
		multiset<int> mst;
		for(int i = 0; i < n; i++)
		{
			cin>>a[i];
			mst.insert(a[i]);
		}
		
		pair<int,int> b[n+5];
		for(int i = 0; i < n; i++)
		{
			int ans = mst.count(a[i]);
			b[i] = {ans,a[i]};
		}
		
		stack<pair<int,int>> st;
		vector<int> result;
		for(int i = n-1; i >= 0; i--)
		{
			while(!st.empty() && b[i].first >= st.top().first)
			{
				st.pop();
			}
			
			if(!st.empty())
				result.push_back(st.top().second);
			else
				result.push_back(-1);
			
			st.push(b[i]);
		}
		
		for(auto it = result.rbegin(); it != result.rend(); it++)
			cout<<*it<<" ";
		
		cout<<endl;
	}
	

	return 0;
}
