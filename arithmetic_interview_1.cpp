/*
小Q想要给他的朋友发送一个神秘字符串，但是他发现字符串的过于长了，于是小Q发明了一种压缩算法对字符串中重复的部分进行了压缩，
对于字符串中连续的m个相同字符串S将会压缩为[m | S](m为一个整数且1 <= m <= 100)，例如字符串ABCABCABC将会被压缩为[3 | ABC]，
现在小Q的同学收到了小Q发送过来的字符串，你能帮助他进行解压缩么？
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> a, b;
stack<int> st1, st2;

int main() {
    int n, x[100001];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i];

    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        a.push_back(st1.size());
        b.push_back(st2.size());

        while (!st1.empty() && st1.top() <= x[i]) st1.pop();
        while (!st2.empty() && st2.top() <= x[j]) st2.pop();
        st1.push(x[i]);
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1 << " ";
    return 0;
}
