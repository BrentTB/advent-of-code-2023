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

#define printall2d(x)          \
    for (auto zz : x)          \
    {                          \
        for (auto qq : zz)     \
        {                      \
            cout << qq << " "; \
        }                      \
        cout << "\n";          \
    }

void p1()
{
    string tmp1, tmp, tmp2;
    vector<tuple<int, int, int>> sandst;
    vector<tuple<int, int, int>> sanden;
    int x, y, z;
    // while (cin >> x)
    while (getline(cin, tmp1))
    {
        istringstream iss1(tmp1);
        getline(iss1, tmp2, '~');

        istringstream iss(tmp2);
        getline(iss, tmp, ',');
        x = stoi(tmp);
        getline(iss, tmp, ',');
        y = stoi(tmp);
        getline(iss, tmp);
        z = stoi(tmp);

        sandst.push_back({x, y, z});

        getline(iss1, tmp2, '~');

        istringstream iss4(tmp2);
        getline(iss4, tmp, ',');
        x = stoi(tmp);
        getline(iss4, tmp, ',');
        y = stoi(tmp);
        getline(iss4, tmp);
        z = stoi(tmp);

        sanden.push_back({x, y, z});
    }

    vector<vector<int>> on;
    on.resize(sanden.size());

    bool moving = true;
    while (moving)
    {
        moving = false;
        int high;

        fo(i, 0, sandst.size())
        {
            high = 0;
            fo(j, 0, sandst.size())
            {
                if (i == j)
                    continue;

                if ((get<0>(sandst[i]) > get<0>(sanden[j]) || get<0>(sanden[i]) < get<0>(sandst[j])) || (get<1>(sandst[i]) > get<1>(sanden[j]) || get<1>(sanden[i]) < get<1>(sandst[j])))
                    continue;

                if (get<2>(sandst[i]) > get<2>(sanden[j]))
                {
                    if (high > get<2>(sanden[j]))
                        continue;
                    if (high < get<2>(sanden[j]))
                    {
                        on[i].clear();
                        high = get<2>(sanden[j]);
                    }
                    on[i].push_back(j);
                }
            }

            if (high + 1 != get<2>(sandst[i]))
            {
                int dif = get<2>(sandst[i]) - (high + 1);
                get<2>(sanden[i]) -= dif;
                get<2>(sandst[i]) -= dif;
                moving = true;
            }
        }
    }

    vector<bool> can(sandst.size(), true);
    foe(i, on)
    {
        if (i.size() == 1)
            can[i[0]] = false;
    }
    int count = 0;
    foe(b, can)
    {
        if (b)
            count++;
    }
    cout << count << endl;
}

void p2()
{
    string tmp1, tmp, tmp2;
    vector<tuple<int, int, int>> sandst;
    vector<tuple<int, int, int>> sanden;
    int x, y, z;
    // while (cin >> x)
    while (getline(cin, tmp1))
    {
        istringstream iss1(tmp1);
        getline(iss1, tmp2, '~');

        istringstream iss(tmp2);
        getline(iss, tmp, ',');
        x = stoi(tmp);
        getline(iss, tmp, ',');
        y = stoi(tmp);
        getline(iss, tmp);
        z = stoi(tmp);

        sandst.push_back({x, y, z});

        getline(iss1, tmp2, '~');

        istringstream iss4(tmp2);
        getline(iss4, tmp, ',');
        x = stoi(tmp);
        getline(iss4, tmp, ',');
        y = stoi(tmp);
        getline(iss4, tmp);
        z = stoi(tmp);

        sanden.push_back({x, y, z});
    }

    vector<vector<int>> on;
    on.resize(sanden.size());

    bool moving = true;
    while (moving)
    {
        moving = false;
        int high;

        fo(i, 0, sandst.size())
        {
            high = 0;
            fo(j, 0, sandst.size())
            {
                if (i == j)
                    continue;

                if ((get<0>(sandst[i]) > get<0>(sanden[j]) || get<0>(sanden[i]) < get<0>(sandst[j])) || (get<1>(sandst[i]) > get<1>(sanden[j]) || get<1>(sanden[i]) < get<1>(sandst[j])))
                    continue;

                if (get<2>(sandst[i]) > get<2>(sanden[j]))
                {
                    if (high > get<2>(sanden[j]))
                        continue;
                    if (high < get<2>(sanden[j]))
                    {
                        on[i].clear();
                        high = get<2>(sanden[j]);
                    }
                    on[i].push_back(j);
                }
            }

            if (high + 1 != get<2>(sandst[i]))
            {
                int dif = get<2>(sandst[i]) - (high + 1);
                get<2>(sanden[i]) -= dif;
                get<2>(sandst[i]) -= dif;
                moving = true;
            }
        }
    }
    vector<bool> can(sandst.size(), true);
    foe(i, on)
    {
        if (i.size() == 1)
            can[i[0]] = false;
    }

    ll total = 0;

    fo(i, 0, sandst.size())
    {
        if (can[i])
            continue;
        set<int> fall;
        fall.insert(i);
        int prev = 0;
        while (fall.size() != prev)
        {
            prev = fall.size();
            fo(j, 0, sandst.size())
            {
                if (j == i || on[j].size() == 0)
                    continue;
                bool willFall = true;
                auto brick = on[j];
                foe(el, brick)
                {
                    if (fall.find(el) == fall.end())
                    {
                        willFall = false;
                    }
                }
                if (willFall)
                {
                    fall.insert(j);
                }
            }
        }
        total += fall.size() - 1;
        fall.clear();
    }
    cout << total << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}
