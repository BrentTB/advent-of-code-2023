#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define endl "\n"
#define elif else if
#define fo(i, a, b) for (int i = a; i < (int)b; i++)
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

    map<string, int> mp;
    mp["red"] = 12;
    mp["green"] = 13;
    mp["blue"] = 14;
    // 12 r 13 g 14 b

    string x;
    v(string) all;

    while (getline(cin, x))
    {
        auto cl = x.find(':');
        x = x.substr(cl + 1, x.length() - cl - 1);
        for (auto &i : x)
        {
            if (i == ',' || i == ';')
                i = ' ';
        }

        all.push_back(x);
    }

    int sum = 0;

    for (auto i = 0; i < all.size(); i++)
    {

        istringstream iss(all[i]);
        int num;
        string type;
        bool possible = true;

        while (iss >> num)
        {
            iss >> type;
            if (num > mp[type])
                possible = false;
        }

        if (possible)
        {
            sum += i + 1;
        }
        iss.clear();
    }
    cout << sum << endl;
}

void p2()
{
    string x;
    v(string) all;

    while (getline(cin, x))
    {
        auto cl = x.find(':');
        x = x.substr(cl + 1, x.length() - cl - 1);
        for (auto &i : x)
        {
            if (i == ',' || i == ';')
                i = ' ';
        }

        all.push_back(x);
    }

    int sum = 0;

    for (auto i = 0; i < all.size(); i++)
    {
        istringstream iss(all[i]);

        int mul = 1;
        int r = 0, g = 0, b = 0;

        int num;
        string type;
        bool add = true;
        while (iss >> num)
        {
            iss >> type;
            if (type == "red")
            {
                r = num > r ? num : r;
            }
            else if (type == "green")
            {
                g = num > g ? num : g;
            }
            else
            {
                b = num > b ? num : b;
            }
        }
        // if (add)
        // {
        sum += r * g * b;
        // }
        iss.clear();
        // }
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
