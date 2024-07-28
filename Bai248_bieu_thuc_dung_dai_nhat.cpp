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
		s = " "+s; 
		stack<int> st;
		for(int i = 1; i <= n; i++)
		{
			if(s[i] == '(')
				st.push(s[i]);
			else{
				if(!st.empty())
				{
					st.pop();
					kq += 2;
				}
			}
		}
		
		cout<<kq<<endl;
	}


	return 0;
}
