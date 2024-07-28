#include<bits/stdc++.h>
using namespace std;

string s, ss;

void genNext()
{
	int i = ss.length()-1;
	while(ss[i] == '1' && i >= 0)
	{
		ss[i]='0';
		i--;
	}
	if(i == -1)
		ss = "1"+ss;
	else{
		ss[i] = '1';
	}
}

bool check()
{
	int n = s.length();
	int length = ss.length();
	if(length > n)
		return true;
	else if(n == length){
		if(ss > s)
			return true;
		else	
			return false;
	}
	return false;
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
		cin>>s;
		ss = "1";
		int cnt = 0;
		while(!check())
		{
			cnt++;
			genNext();
		}
		cout<<cnt<<endl;
	}


	return 0;
}

// Giang hồ còn đồn đại rằng có cách khác nhanh và hiệu quả hơn, bằng cách sử dụng hàng đợi.

