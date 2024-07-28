#include<bits/stdc++.h>
using namespace std;


bool check(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
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
		for(int i = 0; i < s.length(); i++)
		{
			char ans = s[i];
			if(check(ans))
			{
				string tmp1 = st.top(); st.pop();
				string tmp2 = st.top(); st.pop();
				tmp = string(1,ans);
				resul = "("+tmp2+tmp+tmp1+")";
				st.push(resul);
			}else{
				tmp = string(1, ans);
				st.push(tmp);
			}
		}
		
		cout<<resul<<endl;
	}


	return 0;
}
