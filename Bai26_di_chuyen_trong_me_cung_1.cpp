#include<bits/stdc++.h>
using namespace std;

int n, a[15][15];
string s;
set<string>st;

void Try(int x, int y)
{
	if(x == n-1 && y == n-1)
		st.insert(s);
	if(y+1 < n && a[x][y+1])
	{
		s += "R";
		Try(x,y+1);
		s.erase(s.length()-1,1);
	}
	if(x+1 < n && a[x+1][y])
	{
		s += "D";
		Try(x+1,y);
		s.erase(s.length()-1,1);
	}
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
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>a[i][j];
		
		s = "";
		st.clear();
		Try(0,0);
		if(st.size() == 0 || a[0][0] == 0)
			cout<<"-1";
		else
			for(auto x : st)
				cout<<x<<" ";
		cout<<endl;
	}
		
	return 0;
}