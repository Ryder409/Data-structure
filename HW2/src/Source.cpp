#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void powHelper(const vector<char>& S, string& currSet, int idx, vector<string>& res) {
    if (idx == S.size()) {
        res.push_back(currSet);
        return;
    }

    powHelper(S, currSet, idx + 1, res);

    currSet += S[idx];
    powHelper(S, currSet, idx + 1, res);

    currSet.pop_back();
}

vector<string> powerset(const vector<char>& S) {
    vector<string> res;
    string currSet;
    powHelper(S, currSet, 0, res);
    return res;
}

int main() {
    int numElements;
    cout << "請輸入集合的元素數量: ";
    cin >> numElements;

    vector<char> charSet;
    cout << "請輸入 " << numElements << " 個字符:\n";

    for (int i = 0; i < numElements; ++i) {
        char element;
        cout << "第 " << (i + 1) << " 個字符: ";
        cin >> element;
        charSet.push_back(element);
    }

    vector<string> res = powerset(charSet);
    sort(res.begin(), res.end());
    cout << "Set: { ";
    for (char c : charSet) {
        cout << c << " ";
    }
    cout << "}\nPowerset: { ";
    for (const auto& subset : res) {
        cout << "(" << subset << ") ";
    }
    cout << "}\n";
    cout << "總共 " << res.size() << " 種結果。" << endl;

    return 0;
}
