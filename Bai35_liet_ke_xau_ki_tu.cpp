#include<bits/stdc++.h>
using namespace std;

int n, k;
int visited[50];

void display()
{
	for(int i = 1; i <= k; i++)
		cout<<char('A'+visited[i]);
	cout<<endl;
}

void Try(int i)
{
	for(int j = visited[i-1]; j <= n; j++)
	{
		visited[i] = j;
		if(i == k)
			display();
		else if(i < k)
			Try(i+1);	
	}	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	char s;
	cin>>s>>k;
	n = s-'A';
	visited[0] = 0;			// Đánh dấu điểm bắt đầu của trạng thái thứ 1.
	Try(1);


	return 0;
}

// Tư tưởng tương tự bài quay lui sinh tổ hợp.