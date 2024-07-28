#include<bits/stdc++.h>
using namespace std;

// prefix to infix conversion.

bool check(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '^')
		return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		string s, resul="", tmp;
		stack<string> st;
		cin>>s;
		for(int i = s.length()-1; i >= 0; i--)
		{
			char ans = s[i];
			if(check(ans))
			{
				string tmp1 = st.top(); st.pop();
				string tmp2 = st.top(); st.pop();
				tmp = string(1,ans);		
				resul = "("+tmp1+tmp+tmp2+")";
				st.push(resul);
			}else{
				tmp = string(1,ans);
				st.push(tmp);
			}	
		}
		
		cout<<resul<<endl;
	}
	

	return 0;
}
