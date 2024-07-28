#include<bits/stdc++.h>
using namespace std;


#define ll long long

bool check(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/' || a == '^')
		return true;
	return false;
}

ll cal(ll a, ll b, char ans)
{
	if(ans == '+')
		return a+b;
	if(ans == '-')
		return a-b;
	if(ans == '*')
		return a*b;
	if(ans == '/')
		return a/b;
	if(ans == '^')
	{
		ll resul = 1;
		while(b)
		{
			if(b%2)
			{
				resul *= a;
			}
			a *= a;
			b /= 2;
		}
		return resul;
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--)
	{
		string s, resul = "";
		stack<ll> st;
		cin>>s;
		
		for(ll i = 0; i < s.length(); i++)
		{
			char ans = s[i];
			if(check(ans))
			{
				ll num2 = st.top(); st.pop();
				ll num1 = st.top(); st.pop();
				ll resul = cal(num1,num2,ans);
				st.push(resul);
			}else{
				ll tmp = ans-'0';
				st.push(tmp);
			}
		}
		
		cout<<st.top()<<endl;
	}


	return 0;
}

// Bài này đề cho tính biểu thức và coi mỗi toán hạng là một kí tự => biểu thức viết kề nhau.