#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, x;
	string s;
	queue<int> que;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s == "PUSH")
		{
			cin>>x;
			que.push(x);
		}else if(s == "POP"){
			if(!que.empty())
				que.pop();
		}else if(s == "PRINTFRONT"){
			if(!que.empty())
				cout<<que.front();
			else 
				cout<<"NONE";
			cout<<endl;
		}
	}
	

	return 0;
}