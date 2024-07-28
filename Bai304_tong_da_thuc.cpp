#include<bits/stdc++.h>
using namespace std;


int b[10005], max_idx;

bool check(char s)
{
	if(s == '*' || s == '^' || s == 'x' || s == '+')
		return true;
	return false;
}

void change(string s)
{
	string ss = "";
	int n = s.length();
	for(int i = 0; i < n; i++)
	{
		if(check(s[i]))
			ss += " ";
		else
			ss += s[i];
	}
	
	stringstream ans(ss);
	int cnt = 0, value, idx;
	while(ans >> s)
	{
		cnt++;
		if(cnt%2 == 1)
			value = stoi(s);
		else{
			idx = stoi(s);
			max_idx = max(max_idx,idx);
			b[idx] += value;
		}
	}
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
		string s, ss;
		getline(cin,s);
		getline(cin,ss);
		memset(b, 0, sizeof(b));
		change(s);
		change(ss);
		
		cout<<b[max_idx]<<"*x^"<<max_idx;
		for(int i = max_idx-1; i >= 0; i--)
		{
			if(b[i])
				cout<<" + "<<b[i]<<"*x^"<<i;
		}
		
		cout<<endl;
	}


	return 0;
}
