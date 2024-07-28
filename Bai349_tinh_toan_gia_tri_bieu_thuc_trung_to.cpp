#include<bits/stdc++.h>
using namespace std;


bool check(char s)
{
	if(s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')')
		return true;
	return false;
}

int precedence(string s)
{
	if(s == "*" || s == "/")
		return 3;
	else if(s == "+" || s == "-")
		return 2;
	else if(s == "(" || s == ")")
		return 1;
	return 0;
}

long long math(long long a, long long b, string s)
{
	if(s == "+")
		return a+b;
	else if(s == "-")
		return a-b;
	else if(s == "*")
		return a*b;
	else 
		return a/b;
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
		string s, ss ="";
		cin>>s;
		int n = s.length();
		s = " " + s;		
		for(int i = 1; i <= n; i++)
		{
			if(!check(s[i])){
				ss += s[i];
			}else{
				ss = ss+" "+s[i]+" ";
			}
		}
// Mục đích tạo dấu cách xung quanh toán tử, khi đưa vào stringstream thì nó tự động đưa ra đầy đủ toán hạng.

// Phép biến đổi từ trung tố sang hậu tố.		
		stringstream ans(ss);
		string result = "";
		stack<string> st;
		while(ans >> s)
		{
			if(precedence(s) == 0)
			{
				result = result + " " + s; 
			}else if(s == ")"){
				while(st.top() != "("){
					result = result + " " + st.top();
					st.pop();
				}
				st.pop();
			}else{
				if(s != "(")
				{
					while(st.size() && precedence(s) <= precedence(st.top()))
					{
						result = result + " " + st.top();
						st.pop();
					}
				}
				st.push(s);
			}
		}
		
		while(st.size())
		{
			result = result + " "+st.top();
			st.pop();
		}
		
// Tính toán biểu thức hậu tố.
		stringstream ans2(result);
		long long sum = 0;
		stack<long long> st2;
		while(ans2 >> s)
		{
			if(precedence(s) == 0)
			{
				st2.push(stoi(s));
			}else{
				long long tmp2 = st2.top(); st2.pop();
				long long tmp1 = st2.top(); st2.pop();
				long long tmp = math(tmp1,tmp2,s);
				st2.push(tmp);
			}
		}
		
		cout<<st2.top()<<endl;
	}


	return 0;
}
