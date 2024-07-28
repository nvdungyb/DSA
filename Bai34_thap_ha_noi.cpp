#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void chuyen(char a, char b)
{
	cout<<cnt++ << ":  " <<a<<" -> "<<b<<endl;
}

void thapHaNoi(int n, char a, char b, char c)	// mục tiêu là di chuyển n đĩa từ cột thứ 1 -> cột thứ 3.	
{
	if(n == 1)		
		chuyen(a,c);	
	else{
		thapHaNoi(n-1,a,c,b);	// di chuyển n-1 đĩa từ cột a-> cột b lấy cột c làm trung gian.		
		chuyen(a,c);			// di chuyển đĩa lớn nhất từ cột a -> cột c.
		thapHaNoi(n-1,b,a,c);	// di chuyển n-1 đĩa từ cột b -> cột c lấy cột a làm trung gian.
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	thapHaNoi(n,'A','B','C');


	return 0;
}
