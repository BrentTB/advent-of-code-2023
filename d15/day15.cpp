#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
// #define endl "\n"
#define elif else if
#define fo(i, a, b) for (int i = a; i < (int)b; i++)
#define foe(a, b) for (auto a : b)
#define rfo(i, b, a) for (int i = a - 1; i >= b; i--)
#define v(i) vector<i>
#define vll vector<long long>
#define vint vector<int>
#define vstr vector<string>
#define pairll pair<long long, long long>
#define pairint pair<int, int>
#define vpairll vector<pair<long long, long long>>
#define vpairint vector<pair<int, int>>
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

#define printall2d(x)         \
    for (auto zz : x)         \
    {                         \
        for (auto qq : zz)    \
        {                     \
            cout << qq << ""; \
        }                     \
        cout << "\n";         \
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

ll hashA(string str)
{
    ll sum = 0;
    foe(ch, str)
    {
        sum += ch;
        sum *= 17;
        sum %= 256;
    }
    return sum;
}
void p1()
{
    string x;
    ll sum = 0;
    while (getline(cin, x, ','))
    {
        sum += hashA(x);
    }
    cout << sum << endl;
}

void p2()
{
    string x, tmp;
    ll sum = 0;

    vector<vector<pair<string, int>>> mp(256);

    while (getline(cin, x, ','))
    {
        int box = 0;
        if (x.find('=') != -1)
        {
            tmp = x.substr(0, x.find('='));
            box = hashA(tmp);
            bool found = false;
            fo(i, 0, mp[box].size())
            {
                if (mp[box][i].first == tmp)
                {
                    found = true;
                    mp[box][i].second = stoi(x.substr(x.find('=') + 1));
                    break;
                }
            }
            if (!found)
                mp[box].push_back({tmp, stoi(x.substr(x.find('=') + 1))});
        }
        else
        {
            tmp = x.substr(0, x.find('-'));
            box = hashA(tmp);
            fo(i, 0, mp[box].size())
            {
                if (mp[box][i].first == tmp)
                {
                    mp[box].erase(mp[box].begin() + i);
                    break;
                }
            }
        }
    }
    fo(i, 0, mp.size())
    {
        fo(j, 0, mp[i].size())
        {
            sum += (i + 1) * (j + 1) * mp[i][j].second;
        }
    }

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
