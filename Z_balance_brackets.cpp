#include<bits/stdc++.h>
using namespace std;


int bracket(char a)
{
	if(a == '{')
		return 1;
	if(a == '(')
		return 2;
	if(a == '[')
		return 3;
	if(a == '}')
		return -1;
	if(a == ')')
		return -2;
	if(a == ']')
		return -3;
		
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin>>s;
	stack<char> st;
	int ok = 0;
	for(int i = 0; i < s.length(); i++)
	{
		char ans = s[i];
		if(bracket(ans) > 0)
		{
			st.push(ans);
		}else{
			if(st.size())
			{
				char top = st.top();
				if(bracket(top) + bracket(ans) == 0)
					st.pop();
				else{
					ok = 1;
					break;
				}
			}else{
				ok = 1;
				break;
			}
		}
	}
	
	if(ok)
		cout<<"Not Balance";
		
	if(st.size())
	{
		cout<<"Not Balance";
	}else{
		cout<<"Balance";
	}
		

	return 0;
}
