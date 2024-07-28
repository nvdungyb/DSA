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
			
		pair<int,int> b[n+5];					// lưu giá trị bên phải nhỏ hơn gần nhất trong mảng a[], nếu ko tồn tại thì là -1.
		stack<int> st;		

// Tìm phần tử nhỏ hơn, gần nhất, bên phải.		
		for(int i = n-1; i >= 0; i--)
		{
			while(!st.empty() && a[i] <= st.top())
			{
				st.pop();
			}
			if(!st.empty())						// Nếu tồn tại phần tử nhỏ hơn a[i].
				b[i] = {a[i],st.top()};			// Lưu giá trị mảng a[] vào first.
			else								// Lưu phần tử nhỏ hơn, gần nhất, bên phải vào second.
				b[i] = {a[i],-1};
			
			st.push(a[i]);
		}
		while(!st.empty())						// Tái sử dụng stack.
		{
			st.pop();
		}
		
// tìm phần tử lớn hơn gần nhất bên phải.
		vector<int> result;
		for(int i = n-1; i >= 0; i--)
		{
			while(!st.empty() && b[i].first >= b[st.top()].first)
			{
				st.pop();		
			}
			if(!st.empty())
				result.push_back(b[st.top()].second);
			else
				result.push_back(-1);
			
			st.push(i);
		}
		
		for(auto it = result.rbegin(); it != result.rend(); it++)
			cout<<*it<<" ";
		
		cout<<endl;
	}
	

	return 0;
}
