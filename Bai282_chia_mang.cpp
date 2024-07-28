#include<bits/stdc++.h>
using namespace std;

// Bài này là copy trong phần comment code.

int ok, k, n, used[30], a[30], s;

void Try(int pos, int sum, int cnt) {
	if (ok)
		return;
	if (cnt == k) {
		ok = 1;
		return;
	}
	for (int j = pos; j <= n; j++) {
		if (!used[j] && sum + a[j] <= s) {
			used[j] = 1;
			if (sum + a[j] == s) {
				Try(1, 0, cnt + 1);
			}else{
				Try(j + 1, sum + a[j], cnt);
			}
			used[j] = 0;
		}
	}
}

int main() 
{
	int t;
	cin >> t; 
	while (t--)
	{ 
		memset(used, 0, sizeof(used)); 
		s = 0; 
		ok = 0; 
		cin >> n >> k; 
		for (int i = 1; i <= n; i++) 
		{
			cin >> a[i]; 
			s += a[i]; 
		}
		if (s % k == 0) {
			s /= k; 
			Try(1,0, 0);
			cout << ok << endl; 
		}
		else 
			cout << 0 << endl; 
		
	}
	
	return 0;
}