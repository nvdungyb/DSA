#include<bits/stdc++.h>
using namespace std;


//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	
//	string s;
//	int n, t;
//	stack<int> st;
//	vector<int> vt;
//	while(cin>>s)
//	{
//		if(s == "push")
//		{
//			cin>>n;
//			st.push(n);
//		}else if(s == "show"){
//			
//			if(st.empty()){
//				cout<<"empty";
//			}else{
//				while(!st.empty()){
//					int k = st.top();st.pop();
//					vt.push_back(k);
//				}
//				for(auto x = vt.rbegin(); x != vt.rend(); x++)
//				{
//					cout<<*x<<" ";
//					st.push(*x);
//				}
//			}
//			cout<<endl;
//			vt.clear();
//		}else if(s == "pop"){
//			st.pop();
//		}
//	}
//
//
//	return 0;
//}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	int n, t;
	vector<int> vt;
	while(cin>>s)
	{
		if(s == "push")
		{
			cin>>n;
			vt.push_back(n);
		}else if(s == "show"){
			
			if(vt.empty()){
				cout<<"empty";
			}else{
				
				for(auto x = vt.begin(); x != vt.end(); x++)
				{
					cout<<*x<<" ";
				}
			}
			cout<<endl;
		}else if(s == "pop"){
			vt.pop_back();
		}
	}


	return 0;
}
