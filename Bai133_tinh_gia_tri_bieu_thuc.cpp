#include<bits/stdc++.h>
using namespace std;


bool check(string a)
{
	if(a == "+" || a == "-" || a == "*")
		return true;
	return false;
}

long long cal(long long a, long long b, string ans)
{
	if(ans == "+")
		return a+b;
	if(ans == "-")
		return a-b;
	if(ans == "*")
		return a*b;
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin>>t;
	cin.ignore();
	for(int k = 1; k <= t; k++)
	{
		string s;
		stack<long long> st;
		getline(cin,s);
		stringstream ss(s);
		
		string ans;
		while(ss>>ans)
		{
			if(check(ans))
			{
				long long tmp2 = st.top(); st.pop();
				long long tmp1 = st.top(); st.pop();
				long long resul = cal(tmp1,tmp2,ans);
				st.push(resul);
			}else{
				long long resul = stol(ans);
				st.push(resul);
			}
		}           
		
		cout<<"#"<<k<<" "<<st.top()<<endl;
	}


	return 0;
}

// Bài này các toán hạng có thể lớn và cách nhau bởi dấu ' '.