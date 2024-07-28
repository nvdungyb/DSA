#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, x;
	string s;
	deque<int> dq;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s == "PUSHBACK"){
			cin>>x;
			dq.push_back(x);
		}else if(s == "PUSHFRONT"){
			cin>>x;
			dq.push_front(x);
		}else if(s == "PRINTFRONT"){
			if(!dq.empty())
				cout<<dq.front();
			else
				cout<<"NONE";
			cout<<endl;
		}else if(s == "POPFRONT"){
			if(!dq.empty())
				dq.pop_front();
		}else if(s == "PRINTBACK"){
			if(!dq.empty())
				cout<<dq.back();
			else
				cout<<"NONE";
			cout<<endl;
		}else if(s == "POPBACK")
			if(!dq.empty())
				dq.pop_back();
	}


	return 0;
}
