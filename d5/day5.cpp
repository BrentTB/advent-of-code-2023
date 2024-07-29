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

    string x;
    vll seeds;
    ll tmp1, tmp2, tmp3;

    // getline(cin, x);
    // cout << x << endl;
    // getline(cin, x);
    // cout << x << endl;
    // getline(cin, x);
    // cout << x << endl;
    // cout << "YO" << endl;

    vector<vector<tuple<ll, ll, ll>>> relation(7); // source, destination, length
    getline(cin, x);
    // cout << x << endl;
    // cout << x.substr(x.find(':') + 2, x.length() - x.find(':') -2) << endl;
    istringstream issT(x.substr(x.find(':') + 2));
    while (issT >> tmp1)
        seeds.push_back(tmp1);

    // for (auto x : seeds)
    // {
    //     cout << x << endl;
    // }
    issT.clear();
    int idx = -1;
    while (getline(cin, x))
    {
        if (isnumber(x[0]))
        {
            istringstream iss(x);
            iss >> tmp1 >> tmp2 >> tmp3;
            relation[idx].push_back({tmp2, tmp1, tmp3});
            iss.clear();
        }
        elif (isalpha(x[0]))
        {
            idx++;
        }
    }

    ll lowDest = INT32_MAX;

    for (auto val : seeds)
    {
        for (auto i = 0; i < 7; i++) // the level in relations
        {
            for (auto x : relation[i])
            {
                if (val >= get<0>(x) && val < get<0>(x) + get<2>(x))
                {
                    val = get<1>(x) + val - get<0>(x);
                    break;
                }
            }
        }
        lowDest = min(lowDest, val);
    }

    cout << lowDest;
    // cout << get<0>(relation[1][0]) << " " << get<1>(relation[1][0]) << " " << get<2>(relation[1][0]) << endl;
}

void p2()
{

    string x;
    vll seeds;
    seeds.reserve(2000000000);
    ll tmp1, tmp2, tmp3;

    vector<vector<tuple<ll, ll, ll>>> relation(7); // source, destination, length
    getline(cin, x);
    istringstream issT(x.substr(x.find(':') + 2));
    while (issT >> tmp1)
    {
        issT >> tmp2;
        for (ll i = tmp1; i < tmp1 + tmp2; i++)
            seeds.push_back(i);
    }

    issT.clear();
    int idx = -1;
    while (getline(cin, x))
    {
        if (isnumber(x[0]))
        {
            istringstream iss(x);
            iss >> tmp1 >> tmp2 >> tmp3;
            relation[idx].push_back({tmp2, tmp1, tmp3});
            iss.clear();
        }
        elif (isalpha(x[0]))
        {
            idx++;
        }
    }

    ll lowDest = INT32_MAX;
    int numDone = 0;

    for (auto val : seeds)
    {
        for (auto i = 0; i < 7; i++) // the level in relations
        {
            for (auto x : relation[i])
            {
                if (val >= get<0>(x) && val < get<0>(x) + get<2>(x))
                {
                    val = get<1>(x) + val - get<0>(x);
                    break;
                }
            }
        }
        lowDest = min(lowDest, val);
        numDone++;
    }

    cout << lowDest;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}
