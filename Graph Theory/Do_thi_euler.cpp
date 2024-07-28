#include<bits/stdc++.h>
using namespace std;


// Đồ thị euler
// Chu trình đơn trong đồ thị G đi qua mỗi cạnh của đồ thị đúng một lần được gọi là chu trình euler.
// Đường đi trong G đi qua mỗi cạnh của nó đúng một lần, gọi là đường đi euler.
// Đồ thị có đường đi euler gọi là nửa euler.

// Cách tìm đồ thị euler
// Đối với đồ thị vô hướng: khi đồ thị đó liên thông và mọi đỉnh của đồ thị đều có bậc chẵn.
// Đối với đồ thị có hướng: khi tất cả các đỉnh đều có bán bậc ra bằng với bán bậc vào => đồ thị có hướng liên thông mạnh.

// Cách tìm đường đi euler.
// Đồ thị vô hướng liên thông là đồ thị nửa euler khi và chỉ khi đồ thị có 0 hoặc 2 đỉnh bậc lẻ. Đường đi euler xuất phát từ một đỉnh bậc lẻ và kết thúc tại đỉnh bậc lẻ còn lại.
// Đồ thị có hướng liên thông yếu là đồ thị nửa euler khi và chỉ khi tồn tại hai đỉnh u,v thỏa: deg+(u) - deg-(u) = deg-(v) - deg+(v) = 1. các đỉnh còn lại đều có bán bậc ra bằng với bán bậc vào. Đồ thị bắt đầu tại đỉnh u là kết thúc tại đỉnh v.

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	




	return 0;
}
