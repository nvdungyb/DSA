#include<bits/stdc++.h>
using namespace std;

string s;

bool checkFinal()
{
	int i = s.length()-2;
	while(i >= 0 && s[i]>=s[i+1])
	{
		i--;
	}
	if(i == -1)
		return true;
	return false;
}

void genNext()
{
	int n = s.length()-1;
	int i = n-1;
	while(s[i] >= s[i+1])
	{
		i--;	
	}	
	int j = n;
	while(s[i] >= s[j])
	{
		j--;
	}
	swap(s[i],s[j]);
	int l = i+1, r = n;
	while(l<r)
	{
		swap(s[l],s[r]);
		l++, r--;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t,k;
	cin>>t;
	while(t--)
	{
		cin>>k>>s;
		if(checkFinal())
			cout<<k<<" BIGGEST";
		else{
			genNext();
			cout<<k<<" "<<s;
		}
		cout<<endl;
	}

	return 0;
}