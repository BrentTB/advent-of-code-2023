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

void p1()
{
    char ch;
    int intt;
    string str;
    vector<pair<char, int>> instr;
    vstr colour;
    while (cin >> ch)
    {
        cin >> intt;
        cin >> str;
        instr.push_back({ch, intt});
        colour.push_back(str.substr(1, str.length() - 2));
    }

    vector<vector<bool>> mp(1000, vector<bool>(1000, false));
    int x = 500, y = 500;
    foe(in, instr)
    {
        // cout << x << " " << y << endl;
        switch (in.first)
        {
        case 'U':
            fo(i, 0, in.second)
            {
                x--;
                mp[x][y] = true;
            }
            break;
        case 'D':
            fo(i, 0, in.second)
            {
                x++;
                mp[x][y] = true;
            }
            break;
        case 'L':
            fo(i, 0, in.second)
            {
                y--;
                mp[x][y] = true;
            }
            break;
        case 'R':
            fo(i, 0, in.second)
            {
                y++;
                mp[x][y] = true;
            }
            break;
        }
    }
    vpairint todo;
    todo.push_back({501, 501});

    while (todo.size() > 0)
    {
        auto on = todo.back();
        todo.pop_back();
        mp[on.first][on.second] = true;
        if (!mp[on.first + 1][on.second])
            todo.push_back({on.first + 1, on.second});
        if (!mp[on.first - 1][on.second])
            todo.push_back({on.first - 1, on.second});
        if (!mp[on.first][on.second + 1])
            todo.push_back({on.first, on.second + 1});
        if (!mp[on.first][on.second - 1])
            todo.push_back({on.first, on.second - 1});
    }

    ll count = 0;
    foe(rw, mp)
    {
        foe(col, rw)
        {
            if (col)
                count++;
        }
    }

    // printall2d(mp);
    cout << count << endl;
}

void p2() // this uses the shoelace formula to calculate the area of the polygon [I did not know this, I had to look it up]
{
    char ch;
    int intt;
    string str;
    vector<pair<char, ll>> instr;
    vstr colour;
    map<int, char> mapp;
    mapp[0] = 'R';
    mapp[1] = 'D';
    mapp[2] = 'L';
    mapp[3] = 'U';

    map<char, int> mapp2;
    mapp2['0'] = 0;
    mapp2['1'] = 1;
    mapp2['2'] = 2;
    mapp2['3'] = 3;
    mapp2['4'] = 4;
    mapp2['5'] = 5;
    mapp2['6'] = 6;
    mapp2['7'] = 7;
    mapp2['8'] = 8;
    mapp2['9'] = 9;
    mapp2['a'] = 10;
    mapp2['b'] = 11;
    mapp2['c'] = 12;
    mapp2['d'] = 13;
    mapp2['e'] = 14;
    mapp2['f'] = 15;

    while (cin >> ch)
    {
        cin >> intt;
        cin >> str;

        str = str.substr(2, str.length() - 3);

        ll tmpVal = 0;
        fo(i, 0, str.length() - 1)
        {
            tmpVal += mapp2[str[i]] * pow(16, str.length() - 2 - i);
        }

        instr.push_back({mapp[str[str.length() - 1] - '0'], tmpVal});
    }

    ll x = 0, y = 0;

    vector<pair<pair<ll, ll>, pair<ll, ll>>> rect; // p1 = start, p2 = size up/down

    pair<char, ll> on = {0, 0};
    pair<pair<ll, ll>, pair<ll, ll>> recton;
    ll area = 0;
    foe(in, instr)
    {
        x = on.first;
        y = on.second;
        switch (in.first)
        {
        case 'U':
            x -= in.second;
            break;
        case 'D':
            x += in.second;
            break;
        case 'L':
            y -= in.second;
            break;
        case 'R':
            y += in.second;
            break;
        }
        area += (x - on.first) * (y + on.second) + in.second;
        on = {x, y};
    }
    area /= 2;
    area++;

    cout << area << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
