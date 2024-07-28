#include<bits/stdc++.h>
using namespace std;


bool check(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/')
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
	cin.ignore();
	while(t--)
	{
		string s;
		stack<char> st;
		getline(cin,s);
		int ok = 0;
		for(int i = 0; i < s.length(); i++)
		{	
			if(s[i] == '(' || check(s[i]))			// Chỉ push vào stack cặp ngoặc nhọn hoặc toán tử.
				st.push(s[i]);
			else if(s[i] == ')')
			{
				5r
				st.pop();
				
				if(cnt == 0){			// Nếu trong hai ngoặc nhọn mà không có toán tử nào thì cặp ngoặc đó thừa.
					ok = 1;
					break;
				}
			}	
		}
		
		if(ok)
			cout<<"Yes";
		else
			cout<<"No";
		
		cout<<endl;
	}
	

	return 0;
}
