#include<bits/stdc++.h>
using namespace std;


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
		
		stack<int> st;
		int j = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == 'I')
			{
				while(!st.empty())
				{
					cout<<st.top();
					st.pop();
				}
				if(i == 0)
					cout<<++j;
				if(s[i+1] != 'D')
					cout<<++j;
			}else{
				if(s[i-1] == 'I' || i == 0){
					st.push(++j);
				}
				st.push(++j);
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

// Chỉ kí tự D mới push vào stack, nếu s[i] == 'I' 
//								+ thì push hết số trong stack ra.
//									_nếu i == 0 thì in ra ++j;
//									_nếu s[i+1] == 'I' thì in tiếp ra ++j;
//	Nếu s[i] == 'D' thì push ++j;
//				_nếu  s[i-1] == 'I'  hoặc i == 0 thì push ++j;
//				





