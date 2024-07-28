#include<bits/stdc++.h>
using namespace std;


bool check(char s)
{
	if(s >= 'a' && s <= 'z')
		return true;
	if(s == '[' || s == ']')
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
		string s;
		cin>>s;
		stack<char> st;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == ']')
			{
				string ss = "";
				while(!st.empty() && st.top() != '[')
				{
					ss = st.top()+ss;
					st.pop();
				}
				st.pop();										// loại bỏ dấu [.
				
				int loop = 0, ans = 0;							
				while(!st.empty() && !check(st.top()))			// kiểm tra xem trước dấu '[' có phải là số hay không.
				{
					ans = (st.top()-'0')*pow(10,loop) + ans;	// Thực hiện lấy số nguyên n trước dấu '['.
					loop++;
					st.pop();
				}
				
				if(ans == 0)								   // tức nghĩa là trước dấu [] không có số.
					ans = 1;								   // thì lặp lại 1 lần xâu trong dấu [].
				string tmp = "";
				while(ans)										
				{
					tmp = tmp+ss;
					ans--;
				}
				
				for(int j = 0; j < tmp.length(); j++){
					st.push(tmp[j]);
				}
								
			}else{
				st.push(s[i]);
			}
		}
		
		string result = "";
		while(!st.empty())
		{
			result = st.top()+result;
			st.pop();
		}
		cout<<result<<endl;
	}


	return 0;
}
