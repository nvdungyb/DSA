#include<bits/stdc++.h>
using namespace std;

int n;
string s;

bool check()
{
	int ans = 0;
	for(int i = 0; i < s.length(); i++)
	{
		ans = ans*10 + (s[i]-'0');
		ans %= n;
	}
	if(ans == 0)
		return true;
	return false;
}

void genNext()
{
	int i = s.length()-1;
	while(s[i]=='9' && i >= 0)
	{
		s[i] = '0';
		i--;
	}
	if(i == -1)
		s = "9"+s;
	else
		s[i] = '9';
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
		cin>>n;
		
		s = "9";
		while(!check())
		{
			genNext();
		}	
		cout<<s<<endl;
	}


	return 0;
}

// Sinh kế tiếp, tư tưởng giống với thuật toán sinh xâu nhị phân.
