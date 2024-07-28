#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// n là số lương thực cố thể mua trong 1 ngày
	// m là số lương thực sử dụng trong 1 ngày
	// s là số ngày cần phải sống sót, có thể mua hàng từ thứ 2 -> 7
	int t, n , m, s;
	cin>>t;
	while(t--)
	{
		cin>>n>>s>>m;
		if(n*(s-s/7) < s*m)	// nếu mà lương thực mua trong các ngày có thể mua mà nhỏ hơn lượng cần để tồn tại thì sẽ die.
		{
			cout<<"-1";
		}else{
			for(int i = 1; i <= s-s/7; i++)		// in ra số ngày ít nhất cần phải mua lương thực để tồn tại.
			{
				if(n*i >= s*m)
				{
					cout<<i;
					break;
				}
			}
		}
		
		cout<<endl;
	}


	return 0;
}
