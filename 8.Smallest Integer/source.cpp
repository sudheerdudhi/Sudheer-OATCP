#include <bits/stdc++.h>
using namespace std;
int main()
{
    // below in freopen both line of code is changable acordangly input
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
    string num;
    int k;
    cin >> num >> k;
    // corner case
    if (num.size() == k)
    {
        cout << "0\n";
        return 0;
    }
    stack<char> q;
    q.push(num[0]);
    for (int i = 1; i < num.length(); i++)
    {
        while (!q.empty() && q.top() > num[i] && k != 0)
        {
            q.pop();
            k--;
        }
        q.push(num[i]);
    }
    stack<char> q1;
    while (!q.empty())
    {
        while (k != 0)
        {
            q.pop();
            k--;
        }
        q1.push(q.top());
        q.pop();
    }
    while (q1.size() != 1 && q1.top() == '0')
    {
        q1.pop();
    }
    string ans = "";
    while (!q1.empty())
    {
        ans.push_back(q1.top());
        q1.pop();
    }
    cout << ans << "\n";
    return 0;
}