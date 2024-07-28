#include <iostream>
#include <vector>
using namespace std;

// Đổi chỗ hai viên bi
void swap_balls(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Sắp xếp các viên bi theo thứ tự xanh - trắng - đỏ
int sort_balls(vector<int>& balls) {
    int num_balls = balls.size();
    int num_swaps = 0;
    int next_green = 0, next_white = 0, next_red = num_balls - 1;
    
    while (next_white <= next_red) {
        if (balls[next_white] == 0) { // Nếu là viên bi xanh
            swap_balls(balls[next_white], balls[next_green]);
            next_green++;
            next_white++;
            num_swaps++;
        } else if (balls[next_white] == 1) { // Nếu là viên bi trắng
            next_white++;
        } else { // Nếu là viên bi đỏ
            while (balls[next_red] == 2 && next_red > next_white) {
                next_red--;
            }
            if (balls[next_red] == 0) { // Nếu có một viên bi xanh đứng sai vị trí phía sau
                swap_balls(balls[next_red], balls[next_white]);
                next_green++;
            } else { // Nếu không có viên bi xanh đứng sai vị trí phía sau
                swap_balls(balls[next_red], balls[next_white]);
            }
            next_red--;
            next_white++;
            num_swaps++;
        }
    }
    return num_swaps;
}

int main() {
    vector<int> balls = {1,1,0,2,2,2,1,2,0};
    int num_swaps = sort_balls(balls);
    
    cout << "Sorted balls: ";
    for (int ball : balls) {
        cout << ball << " ";
    }
    cout << endl << "Number of swaps: " << num_swaps << endl;
    return 0;
}
