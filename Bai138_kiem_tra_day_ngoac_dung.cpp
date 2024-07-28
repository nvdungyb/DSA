#include<bits/stdc++.h>
using namespace std;


int precedence(char s)
{
	if(s == '[')
		return 3;
	if(s == ']')
		return -3;
	if(s == '(')
		return 2;
	if(s == ')')
		return -2;
	if(s == '{')
		return 1;
	if(s == '}')
		return -1;
		
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n;
	cin>>t;
	while(t--)
	{
	 	string s;
	 	cin>>s;
	 	stack<char> st;
	 	int ok = 0;
	 	for(int i = 0; i < s.length(); i++)
	 	{
	 		if(precedence(s[i]) > 0)
	 			st.push(s[i]);
	 		else{																	// TH: là dấu đóng.
	 			if(!st.empty() && precedence(st.top()) + precedence(s[i]) == 0)
				 	st.pop();
				else{
					ok = 1;
					break;
				}	
			}
		}
	 
		if(ok || st.size())
			cout<<"NO";
		else{
			cout<<"YES";
		}
		
	 	cout<<endl;
	}


	return 0;
}

// biểu thức ngoặc đúng là biểu thức khi mà gặp dấu đóng thì dấu đầu tiên trong stack là dấu mở tương ứng.
// và khi kết thúc trong stack không còn dấu ngoặc mở nào.