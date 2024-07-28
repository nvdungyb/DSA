#include<bits/stdc++.h>
using namespace std;

// Số cách ít nhất để lấy phần tử bất kì trong mảng về đầu hoặc cuối mảng để mảng sắp xếp tăng dần.
// Tư tưởng của bài sắp xếp đơn giản này:
// Lưu lại chỉ số của từng phần tử rồi sắp xếp lại mảng
// Tìm dãy con có chỉ số tăng dần dài nhất, k = longest_increasing_index
// ta luôn có số lớn hơn thứ k => chuyển về cuối mảng -> tiếp tục cho tới khi số lớn nhất về cuối mảng.
// Hoặc số nhỏ thứ k -> thứ k-1 -> nhỏ nhất đã về đầu mảng

bool cmp(pair<int,int>a, pair<int,int>b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin>>n;
	pair<int,int> a[n+5];
	
	for(int i = 0; i < n; i++)
	{
		cin>>a[i].first;
		a[i].second = i;
	}
	
	sort(a,a+n,cmp);
	
	int cnt = 1, ans = 1, pre = 0;
	for(int i = 0; i < n; i++)
	{
		if(a[i].second > a[pre].second)
		{
			cnt++;
		}else{
			cnt = 1;
		}
		pre = i;
		ans = max(ans, cnt);
	}
	cout<<n-ans;

	return 0;
}

// Đối với bài tìm số lần lấy từng phần tử trong mảng rồi chèn vào vị trí bất kì trong mảng để mảng được sắp xếp
// Ta chỉ cần tìm dãy con tăng dần lớn nhất trong mảng, lấy số lượng phần tử trong mảng rồi trừ đi số lượng phần tử của dãy con tăng dài nhất.