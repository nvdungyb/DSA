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
		 
		stack<int> st;
		vector<int> result;
		for(int i = n-1; i >= 0; i--)
		{
			while(!st.empty() && a[i] >= st.top())		// Tìm phần tử cuối cùng trong stack mà lớn hơn a[i].
			{
				st.pop();
			}
			if(!st.empty())								// Nếu tồn tại thì push(st.top()).
				result.push_back(st.top());
			else
				result.push_back(-1);					// Nếu ko thì push(-1);			
			
			st.push(a[i]);								// Push(a[i]) vào trong stack.
		}
		 
		for(auto it = result.rbegin(); it != result.rend(); it++)
			cout<<*it<<" ";
		cout<<endl;
	}
	

	return 0;
}
