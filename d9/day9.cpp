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
#define vvll vector<vector<long long>>
#define vint vector<int>
#define vstr vector<string>
#define pairll pair<long long, long long>
#define vpairll vector<pair<long long, long long>>
#define print(x) cout << x << "\n"

template <typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T>
T lcm(T a, T b) { return a * b / gcd(a, b); }

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

ll next(vll &line)
{
    vll newRow(line.size() - 1);
    bool allZ = true;

    fo(i, 0, line.size() - 1)
    {
        newRow[i] = line[i + 1] - line[i];
        if (line[i + 1] - line[i] != 0)
            allZ = false;
    }
    if (allZ)
    {
        return line[0];
    }
    return line[line.size() - 1] + next(newRow);
}

void p1()
{
    vvll history;
    ll tmp;

    string x;
    while (getline(cin, x))
    {
        history.push_back({});
        istringstream iss(x);
        while (iss >> tmp)
        {
            history[history.size() - 1].push_back(tmp);
        }
    }
    ll sum = 0;
    for (auto line : history)
    {
        sum += next(line);
        // cout << next(line)<<endl;
    }
    cout << sum << endl;
}

ll prev(vll &line)
{
    vll newRow(line.size() - 1);
    bool allZ = true;

    fo(i, 0, line.size() - 1)
    {
        newRow[i] = line[i + 1] - line[i];
        if (line[i + 1] - line[i] != 0)
            allZ = false;
    }
    if (allZ)
    {
        return line[0];
    }
    return line[0] - prev(newRow);
}

void p2()
{
    vvll history;
    ll tmp;

    string x;
    while (getline(cin, x))
    {
        history.push_back({});
        istringstream iss(x);
        while (iss >> tmp)
        {
            history[history.size() - 1].push_back(tmp);
        }
    }
    ll sum = 0;
    for (auto line : history)
    {
        sum += prev(line);
    }
    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}
