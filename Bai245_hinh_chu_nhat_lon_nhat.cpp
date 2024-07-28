#include<bits/stdc++.h>
using namespace std;


long long find(long long a[], int n)
{
	int l[n], 										// Mảng l[], với l[i] lưu chữ index của cột đầu tiên bên trái có độ cao lớn hơn hoặc bằng cột a[i].
		r[n];										// Mảng r[], với r[i] lưu chữ index của cột đầu tiên bên phải có độ cao lớn hơn hoặc bằng cột a[i].
	stack<int> st;
	for(int i = 0; i < n; i++)
	{
		while(!st.empty() && a[st.top()] >= a[i])
		{
			st.pop();
		}
		
		if(!st.empty()){
			l[i] = st.top()+1;
		}else{
			l[i] = 0;
		}
		
		st.push(i);
	}
	
	while(!st.empty()){
		st.pop();
	}
	
	for(int i = n-1; i >= 0; i--)
	{
		while(!st.empty() && a[st.top()] >= a[i])
		{
			st.pop();
		}
		
		if(!st.empty()){
			r[i] = st.top()-1;
		}else{
			r[i] = n-1;
		}
		
		st.push(i);
	}
	
	long long ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = max(ans,a[i]*(r[i]-l[i]+1));
	}
 
	return ans;
}

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
		long long a[n+5];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		
		long long result = find(a, n);
		
		cout<<result<<endl;
	}


	return 0;
}
