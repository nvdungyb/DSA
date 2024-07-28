#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	string name = "123";
	stack<string> st;
	st.push(name);
	cout<<stoi(st.top());
	

	return 0;
}
