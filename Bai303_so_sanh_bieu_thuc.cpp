#include<bits/stdc++.h>
using namespace std;


bool check(char s)
{
	if(s == '-' || s == '+' || s == '(' || s == ')')
		return true;
	return false;
}

char change(char s)
{
	if(s == '-')
		return '+';
	else
		return '-';
}

string posfix(string ss)
{
	int n = ss.length();
	string s = " "+ss;				// phải làm thế thì dòng 49 mới hoạt động được nhé.
	stack<char> st, tmp;
	string result = "";
	int ok = 0;
	for(int i = 1; i <= n; i++)
	{
		if(check(s[i]))
		{
			if(s[i] == ')')
			{
				while(st.size() && st.top() != '(')			// luôn phải kiểm tra đk stack không rỗng.
				{
					tmp.push(st.top());
					st.pop();
				}
				st.pop();
				if(!st.empty() && st.top() == '-')			// Kĩ thuật này hay đó nhé, nghĩ mãi mới ra, chưa đúng đâu, tham khảo thêm bài biểu thức tương đương.		
					ok--;
				while(tmp.size())							// Mục tiêu là loại bỏ cặp ngoặc nhọn, chỉ giữ lại các toán tử theo thứ tự, th có nhiều cặp ngoặc nhọn vẫn hoạt động tốt.
				{
					st.push(tmp.top());
					tmp.pop();
				}
				
			}else{
				if(s[i] == '('){
					if(s[i-1] == '-')
						ok++;
				}
				if(ok%2 == 1 && s[i] != '('){
					st.push(change(s[i]));
				}else{
					st.push(s[i]);
				}
			}
		}else{
			result += s[i];
		}
	}
	
	while(st.size() > 0)
	{
		result += st.top();
		st.pop();
	}
	
	return result;
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
		string s,ss;
		cin>>s>>ss;
		
		string result1 = posfix(s);
		string result2 = posfix(ss);
		cout<<result1<<endl<<result2<<endl;
		if(result1 == result2)
			cout<<"YES";
		else
			cout<<"NO";
			
		cout<<endl;
	}


	return 0;
}

