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
    cout << "�п�J���X�������ƶq: ";
    cin >> numElements;

    vector<char> charSet;
    cout << "�п�J " << numElements << " �Ӧr��:\n";

    for (int i = 0; i < numElements; ++i) {
        char element;
        cout << "�� " << (i + 1) << " �Ӧr��: ";
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
    cout << "�`�@ " << res.size() << " �ص��G�C" << endl;

    return 0;
}
