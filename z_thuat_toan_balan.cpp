#include<bits/stdc++.h>
using namespace std;

int precedence(char a)
{
	if(a == '^')
		return 4;
	if(a == '*' || a == '/')
		return 3;
	if(a == '+' || a == '-')
		return 2;
	if(a == '(' || a == ')')
		return 1;
	return 0;
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
		string s;
		cin>>s;
		
		char ans;
		stack<char> st;
		for(int i = 0; i < s.length(); i++)
		{
			ans = s[i];
			if(precedence(ans) == 0)
			{
				cout<<ans;
			}else if(ans == ')')
			{
				while(st.top() != '(')
				{
					cout<<st.top();
					st.pop();
				}
				st.pop();
			}else{
				if(ans != '(' && st.size())
				{
					while(st.size() && precedence(st.top()) >= precedence(ans))
					{
						cout<<st.top();
						st.pop();
					}
				}
				st.push(ans);
			}
		}
		while(!st.empty())
		{
			cout<<st.top();
			st.pop();
		}
		
		cout<<endl;
	}


	return 0;
}
