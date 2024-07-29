#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define endl "\n"
#define elif else if
#define fo(i, a, b) for (int i = a; i < (int)b; i++)
#define foe(a, b) for (auto a : b)
#define rfo(i, b, a) for (int i = a - 1; i >= b; i--)
#define v(i) vector<i>
#define vll vector<long long>
#define vint vector<int>
#define vstr vector<string>
#define pairll pair<long long, long long>
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

void p1()
{
    string x;
    vstr field;
    vpairint galaxy; // find all of these and shortest distance betweeen them
    while (cin >> x)
    {
        field.push_back(x);
    }

    fo(i, 0, field.size())
    {
        fo(j, 0, field[0].length())
        {
            if (field[i][j] == '#')
            {
                galaxy.push_back({i, j});
            }
        }
    }

    bool hasGalaxy;
    rfo(i, 0, field.size()) // all rows
    {
        hasGalaxy = false;
        fo(j, 0, field[0].length())
        {
            if (field[i][j] == '#')
            {
                hasGalaxy = true;
                break;
            }
        }
        if (!hasGalaxy)
        {
            foe(&e, galaxy)
            {
                if (e.first > i)
                    e.first++;
            }
        }
    }
    rfo(j, 0, field[0].length())
    {
        hasGalaxy = false;
        fo(i, 0, field.size())
        {
            if (field[i][j] == '#')
            {
                hasGalaxy = true;
                break;
            }
        }
        if (!hasGalaxy)
        {
            foe(&e, galaxy)
            {
                if (e.second > j)
                    e.second++;
            }
        }
    }

    ll sum = 0;
    fo(i, 0, galaxy.size())
    {
        fo(j, i + 1, galaxy.size())
        {
            sum += abs(galaxy[i].first - galaxy[j].first) + abs(galaxy[i].second - galaxy[j].second);
        }
    }
    cout << sum << endl;
}

void p2()
{

    string x;
    vstr field;
    vpairint galaxy;
    while (cin >> x)
    {
        field.push_back(x);
    }

    fo(i, 0, field.size())
    {
        fo(j, 0, field[0].length())
        {
            if (field[i][j] == '#')
            {
                galaxy.push_back({i, j});
            }
        }
    }

    bool hasGalaxy;
    rfo(i, 0, field.size()) // all rows
    {
        hasGalaxy = false;
        fo(j, 0, field[0].length())
        {
            if (field[i][j] == '#')
            {
                hasGalaxy = true;
                break;
            }
        }
        if (!hasGalaxy)
        {
            foe(&e, galaxy)
            {
                if (e.first > i)
                    e.first += 1000000 - 1;
            }
        }
    }
    rfo(j, 0, field[0].length())
    {
        hasGalaxy = false;
        fo(i, 0, field.size())
        {
            if (field[i][j] == '#')
            {
                hasGalaxy = true;
                break;
            }
        }
        if (!hasGalaxy)
        {
            foe(&e, galaxy)
            {
                if (e.second > j)
                    e.second += 1000000 - 1;
            }
        }
    }

    ll sum = 0;
    fo(i, 0, galaxy.size())
    {
        fo(j, i + 1, galaxy.size())
        {
            sum += abs(galaxy[i].first - galaxy[j].first) + abs(galaxy[i].second - galaxy[j].second);
        }
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
