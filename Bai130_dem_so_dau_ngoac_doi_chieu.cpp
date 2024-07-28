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
		stack<char> st;
		int resul = 0;
		cin>>s;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == ')')
			{
				if(!st.empty()){
					st.pop();
				}else{
					st.push('(');
					resul++;
				}
			}else{
				st.push(s[i]);
			}
		}
		
		resul+=(st.size()/2);
	
		cout<<resul<<endl;
	}
	

	return 0;
}
