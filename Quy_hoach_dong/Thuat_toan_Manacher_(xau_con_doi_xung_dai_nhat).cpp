#include <iostream>
#include <string>
#include <vector>
using namespace std;



// Thuật toán Manacher tìm xâu con đối xứng dài nhất.
// Với độ phức tạp O(n).
// Vừa tối ưu được thời gian, vừa tìm được xâu con đối xứng dài nhất.

string longestPalindrome(string s) {
    // Xâu mở rộng
    string expandedStr = "#";
    for (char c : s) {
        expandedStr += c;
        expandedStr += '#';
    }

    int n = expandedStr.length();
    vector<int> lps(n, 0); 			// Mảng LPS
    int center = 0; 				// Tâm xâu con đối xứng hiện tại
    int right = 0; 					// Vị trí phải nhất của xâu con đối xứng hiện tại

    for (int i = 0; i < n; i++) {
        // Xác định vị trí đối xứng của kí tự hiện tại
        int mirror = 2 * center - i;

        // Cập nhật giá trị LPS tại vị trí hiện tại
        if (i < right)
            lps[i] = min(right - i, lps[mirror]);

        // Mở rộng xâu con đối xứng
        int leftIndex = i - (lps[i] + 1);
        int rightIndex = i + (lps[i] + 1);
        while (leftIndex >= 0 && rightIndex < n && expandedStr[leftIndex] == expandedStr[rightIndex]) {
            lps[i]++;
            leftIndex--;
            rightIndex++;
        }

        // Cập nhật tâm và vị trí phải nhất mới
        if (i + lps[i] > right) {
            center = i;
            right = i + lps[i];
        }
    }

    // Tìm độ dài xâu con đối xứng dài nhất
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 0; i < n; i++) {
        if (lps[i] > maxLen) {
            maxLen = lps[i];
            centerIndex = i;
        }
    }

    // Trích xuất xâu con đối xứng dài nhất
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string longestPal = longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << longestPal << endl;

    return 0;
}
