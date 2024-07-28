#include<bits/stdc++.h>
using namespace std;


bool check(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/')
		return true;
	return false;
}

int cal(int a, int b, char ans)
{
	if(ans == '+')
		return a+b;
	if(ans == '-')
		return a-b;
	if(ans == '*')
		return a*b;
	if(ans == '/')
		return a/b;
	if(ans == '^'){
		int resul = 1;
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
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		stack<int> st;
		cin>>s;
		for(int i = s.length()-1; i >= 0; i--)
		{
			char ans = s[i];
			if(check(ans))
			{
				int tmp1 = st.top(); st.pop();
				int tmp2 = st.top(); st.pop();
				int resul = cal(tmp1,tmp2,ans);
				st.push(resul);
			}else{
				int tmp = ans-'0';
				st.push(tmp);
			}
		}
		
		cout<<st.top()<<endl;
	}


	return 0;
}
