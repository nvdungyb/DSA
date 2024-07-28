#include<bits/stdc++.h>
using namespace std;

long long a[1000005];

void pre()
{
	for(long long i = 1; i <= 1000000; i++)
	{
		a[i] = i*i*i;
	}
}

long long find(string s)
{
	int length = s.length();
	long long ans = stol(s);			// Hàm chuyển từ string sang long long.
	int i = 1;
	while(a[i] <= ans)					// tìm số phập phân lớn nhất nhỏ hơn hoặc bằng s.
	{
		i++;
	}
	i--;
	while(i >= 1)
	{
		long long tmp = a[i];			
		int check = length;				// lưu vết.
		while(tmp >= 1)
		{
			int du = tmp%10;
			int ok = 0;
			for(int j = check-1; j >= 0; j--)
			{
				if(s[j] == char(du+'0'))
				{
					ok = 1;
					check = j;
					break;
				}
			}
			if(!ok)
				break;
			
			tmp /= 10;
		}
		if(tmp == 0)	
			return a[i];
		i--;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	pre();
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		
		cout<<find(s)<<endl;
		
	}


	return 0;
}

// Tìm số khối lập phương lớn nhất khi loại bỏ kí tự trong xâu s.(thứ tự các kí tự là ổn định)
// Tư tưởng là tạo một mảng các số lập phương a[i] = i*i*i; (nhớ kiểu dữ liệu của i là long long).

/*
+ tìm giá trị lớn nhất của a[i] mà không vượt quá giá trị của xâu s.
+ tìm phần tử cuối cùng của a[i] có tồn tại trong s hay không
	_nếu tồn tại thì lưu vết tại vị trí đó, phần tử cuối tiếp theo tìm từ vị trí 0-> vị trí đã lưu vết  (vì thứ tự các chữ số lập phương trong s là giữ nguyên)
	_Tức là chữ số nào trong a[i] đứng sau thì trong s cũng phải đứng sau.
+ Nếu mọi phần tử trong a[i] đều được tìm và đúng thứ tự trong s thì trả về a[i].
+ nếu không tồn tại giảm i, kiểm tra số lập phương nhỏ hơn. nếu i == 0 thì trả về -1.

*/
