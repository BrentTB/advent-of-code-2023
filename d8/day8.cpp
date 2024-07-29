#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define endl "\n"
#define elif else if
#define fo(i, a, b) for (int i = a; i < (int)b; i++)
#define foe(a, b) for (auto a : b)
#define rfo(i, a, b) for (int i = a - 1; i >= b; i--)
#define v(i) vector<i>
#define vll vector<long long>
#define vint vector<int>
#define vstr vector<string>
#define pairll pair<long long, long long>
#define vpairll vector<pair<long long, long long>>
#define print(x) cout << x << "\n"

template <typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

#define printall(x)         \
    for (auto zz : x)       \
    {                       \
        cout << zz << "\n"; \
    }

#define printallpair(x)            \
    for (auto zz : x)              \
    {                              \
        cout << zz.first << " ";   \
        cout << zz.second << "\n"; \
    }

#define pushall(x, n)                   \
    x.resize(n);                        \
    for (int zz = 0; zz < (int)n; zz++) \
    {                                   \
        cin >> x[zz];                   \
    }

#define pushallpair(x, n)                   \
    x.resize(n);                            \
    for (int zz = 0; zz < (int)n; zz++)     \
    {                                       \
        cin >> x[zz].first >> x[zz].second; \
    }

void p1()
{
    map<string, pair<string, string>> mp;
    string instr, x;
    cin >> instr;
    string on = "AAA", end = "ZZZ";
    while (getline(cin, x))
    {
        if (x.length() == 0)
            continue;
        string st = x.substr(0, 3);
        string right = x.substr(x.find('(') + 1, 3);
        string left = x.substr(x.find(',') + 2, 3);
        mp[st] = {right, left};
    }
    int ind = 0;
    int steps = 0;
    while (on != end)
    {
        if (instr[ind] == 'R')
            on = mp[on].second;
        else
            on = mp[on].first;

        steps++;
        ind = (ind + 1) % instr.length();
    }
    cout << steps << endl;
}

void p2() // VERY inefficient code
{
    map<string, pair<string, string>> mp;
    string instr, x;
    cin >> instr;
    vstr on;
    while (getline(cin, x))
    {
        if (x.length() == 0)
            continue;
        string st = x.substr(0, 3);
        string right = x.substr(x.find('(') + 1, 3);
        string left = x.substr(x.find(',') + 2, 3);
        mp[st] = {right, left};
        if (st[2] == 'A')
            on.push_back(st);
    }
    int ind = 0;
    int steps = 0;
    bool done = false;
    while (!done)
    {
        done = true;
        for (auto &str : on)
        {
            if (instr[ind] == 'R')
                str = mp[str].second;
            else
                str = mp[str].first;

            if (str[2] != 'Z')
                done = false;
        }
        steps++;
        ind = (ind + 1) % instr.length();
    }
    cout << steps << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}

/*

2 -> 3
1 -> 4

ans = 5

2 -> 3
0 -> 4

ans = 8

0 -> 3
0 -> 4

ans = 12

*/