#include<bits/stdc++.h>
using namespace std;


void solve(long long tu, long long mau)
{
	long long x = 0;
	while(1)
	{
		if(mau%tu == 0)
		{
			cout<<"1/"<<mau/tu<<endl;
			return;
		}
		x = mau/tu + 1;				// tìm phân số 1/x lớn nhất sao cho nhỏ hơn phân số ban đầu.
		cout<<"1/"<<x<<" + ";
		tu = x*tu - mau;			// cập nhật lại phân số ban đầu.
		mau *= x;
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
		long long tu, mau;
		cin>>tu>>mau;
		solve(tu,mau);
		
	}

	return 0;
}

/*
Thuật toán trên được gọi là "Phân số Egypt" (Egyptian Fraction), đây là một thuật toán đơn giản để chia một phân số dương thành tổng các phân số dương rút gọn với tử số bằng 1 và mẫu số là số nguyên dương.
Ý tưởng của thuật toán là mỗi lần tìm một phân số thỏa mãn điều kiện trên và cộng nó vào kết quả.
Đầu tiên, ta kiểm tra nếu phân số đang xét đã được rút gọn, tức là tử số và mẫu số không có ước chung, thì ta in nó ra và kết thúc thuật toán.
Nếu không, ta tìm số nguyên dương lớn nhất x sao cho 1/x < mau/tu, sau đó in ra phân số 1/x và cộng nó vào kết quả.
Tiếp theo, ta cập nhật tử số và mẫu số mới bằng cách thay thế phân số ban đầu bằng phân số mới tính được từ phép cộng phân số và rút gọn phân số đó.
Lặp lại quá trình trên cho đến khi phân số ban đầu được rút gọn.
*/

/*
Mục tiêu của thuật toán là tìm các phân số đơn vị (có tử số là 1) sao cho tổng của chúng bằng phân số ban đầu. 
Để làm được điều này, thuật toán sử dụng một kỹ thuật gọi là “phương pháp Greedy” (tạm dịch: phương pháp tham lam). 
Phương pháp này có nghĩa là chọn lựa giải pháp tốt nhất có thể tại mỗi bước.
Ở mỗi bước, thuật toán sẽ tìm x nhỏ nhất sao cho 1/x <= a/b. Điều này đảm bảo rằng 1/x là một trong những phân số đơn vị lớn nhất có thể để cộng vào a/b. 
Sau đó, thuật toán sẽ trừ đi 1/x khỏi a/b và tiếp tục quá trình với phân số mới. Quá trình này sẽ kết thúc khi a = 0, tức là không còn dư số nào.
*/

