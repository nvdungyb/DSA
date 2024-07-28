#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int n, t;
	vector<int> vt;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s == "PUSH")
		{
			cin>>n;
			vt.push_back(n);
		}else if(s == "PRINT"){
			
			if(vt.empty()){
				cout<<"NONE";
			}else{
				cout<<*vt.rbegin();
			}
			cout<<endl;
		}else if(s == "POP"){
			if(!vt.empty())
				vt.pop_back();
		}
	}


	return 0;
}
