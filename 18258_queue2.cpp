#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main(void)
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n, data;
    string order;

    queue<int> q;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> order;

        if (order == "push")
        {
            cin >> data;
            q.push(data);
        }
        else if (order == "pop")
        {
            if (!q.empty()) 
            { 
                cout << q.front() << '\n'; 
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if (order == "size")
        {
            cout << q.size() << '\n';
        }
        else if (order == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (order == "front")
        {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (order == "back")
        {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}

