#include <iostream>
#include <chrono> 
using namespace std;

static int cnt = 0;

int ack(int m, int n) {
    cnt++;
    if (m == 0) {
        return n + 1;
    }
    else if (m > 0 && n == 0) {
        return ack(m - 1, 1);
    }
    else if (m > 0 && n > 0) {
        return ack(m - 1, ack(m, n - 1));
    }
    return -1;
}

int main() {
    int m, n;
    cout << "請輸入兩個非負整數 m 和 n: ";
    cin >> m >> n;

    auto start = chrono::high_resolution_clock::now();

    int result = ack(m, n);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start; 

    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;
    cout << "函數執行的次數: " << cnt << endl;
    cout << "執行時間: " << duration.count() << " 秒" << endl;

    return 0;
}
