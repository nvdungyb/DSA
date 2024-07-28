#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		
		int n = s.length(), kq = 0; 
		stack<int> st;
		st.push(-1);
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '(')
				st.push(i);
			else{
				st.pop();
				if(!st.empty()){
					int j = st.top();
					kq = max(kq, i-j);
				}else{
					st.push(i);
				}
			}
		}
		
		cout<<kq<<endl;
	}


	return 0;
}
