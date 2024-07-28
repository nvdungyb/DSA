#include<bits/stdc++.h>
using namespace std;


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
		string s, ans;
		getline(cin,s);
		stringstream ss(s);
		
		stack<string> st;
		while(ss >> ans)
		{
			st.push(ans);
		}
		
		while(!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
		cout<<endl;
	}


	return 0;
}
