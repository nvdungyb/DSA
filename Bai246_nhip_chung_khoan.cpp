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
		
		stack<int> st;					// Lưu chỉ số của mảng a[].
		int b[n+5];
		for(int i = 0; i < n; i++)
		{
			b[i] = 1;
			while(!st.empty() && a[i] >= a[st.top()])
			{
				b[i] += b[st.top()];
				st.pop();
			}
			
			st.push(i);
		}
		
		for(int i = 0; i < n; i++)
			cout<<b[i]<<" ";
			
		cout<<endl;
	}


	return 0;
}
