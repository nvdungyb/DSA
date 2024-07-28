#include<bits/stdc++.h>
using namespace std;

int a[10], ok, cnt;

void genNext()
{
	int i = 8;
	while(a[i] == 1)
	{
		a[i] = 0;
		i--;
	}
	if(i == 0)
		ok = 1;
	else
		a[i] = 1;
}

bool check()
{
	if(a[1] == 0 && a[2] == 0)		// ngày không thể là 00.
		return false;
	if(a[3] == 1 || a[4] == 0)		// tháng chỉ có thể là 02.
		return false;
	if(a[5] == 0)					// năm phải lớn hơn 2000.
		return false;
	 
	return true;
}

void display()
{
	cnt++;
	for(int i = 1; i <= 8; i++)
	{
		if(i == 3 || i == 5)
			cout<<"/";
		if(a[i])
			cout<<"2";
		else
			cout<<"0";
	}
	cout<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(!ok)
	{
		if(check())
		{
			display();
		}
		genNext();
	}
	

	return 0;
}
