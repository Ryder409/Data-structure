#include <iostream>
#include <stack>
#include <tuple>
#include <chrono>

using namespace std;

class Ackermann {
public:
    static int callCount;

    static int A(int m, int n) {
        callCount++;

        stack<tuple<int, int, int>> s;
        s.push(make_tuple(m, n, 0));
        int result = 0;

        while (!s.empty()) {
            auto curr = s.top();
            s.pop();
            int m_curr = get<0>(curr);
            int n_curr = get<1>(curr);
            int r = get<2>(curr);

            if (r == 1) {
                n_curr = result;
            }

            if (m_curr == 0) {
                result = n_curr + 1;
            }
            else if (n_curr == 0) {
                s.push(make_tuple(m_curr - 1, 1, 0));
            }
            else {
                s.push(make_tuple(m_curr - 1, 0, 1));
                s.push(make_tuple(m_curr, n_curr - 1, 0));
            }
        }

        return result;
    }
};

int Ackermann::callCount = 0;

int main() {
    int m, n; 
    cout << "�п�J�D�t��� m: ";
    cin >> m;
    cout << "�п�J�D�t��� n: ";
    cin >> n;

    auto start = chrono::high_resolution_clock::now();
    int result = Ackermann::A(m, n);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "Ackermann(" << m << ", " << n << ") = " << result << endl;
    cout << "��ư��檺����: " << Ackermann::callCount << endl;
    cout << "����ɶ�: " << elapsed.count() << " ��" << endl;

    return 0;
}
