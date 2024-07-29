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

ll totalHeat(vstr &mirror, tuple<int, int, char> start)
{
    v(v(bool)) heat(mirror.size(), v(bool)(mirror[0].length(), false));

    vector<tuple<int, int, char>> light;
    vector<tuple<int, int, char>> moves;
    light.push_back(start);

    while (light.size() != 0)
    {
        auto on = light.back();
        light.pop_back();

        if (get<2>(on) == 'r')
        {
            get<1>(on)++;
            if (get<1>(on) == mirror[0].length())
                continue;

            switch (mirror[get<0>(on)][get<1>(on)])
            {
            case '/':
                get<2>(on) = 'u';
                break;
            case '\\':
                get<2>(on) = 'd';
                break;
            case '|':
                get<2>(on) = 'u';
                light.push_back({get<0>(on), get<1>(on), 'd'});
                break;
            default:
                break;
            }
        }
        elif (get<2>(on) == 'l')
        {
            get<1>(on)--;
            if (get<1>(on) == -1)
                continue;

            switch (mirror[get<0>(on)][get<1>(on)])
            {
            case '/':
                get<2>(on) = 'd';
                break;
            case '\\':
                get<2>(on) = 'u';
                break;
            case '|':
                get<2>(on) = 'u';
                light.push_back({get<0>(on), get<1>(on), 'd'});
                break;
            default:
                break;
            }
        }
        elif (get<2>(on) == 'u')
        {
            get<0>(on)--;
            if (get<0>(on) == -1)
                continue;

            switch (mirror[get<0>(on)][get<1>(on)])
            {
            case '/':
                get<2>(on) = 'r';
                break;
            case '\\':
                get<2>(on) = 'l';
                break;
            case '-':
                get<2>(on) = 'r';
                light.push_back({get<0>(on), get<1>(on), 'l'});
                break;
            default:
                break;
            }
        }
        elif (get<2>(on) == 'd')
        {
            get<0>(on)++;
            if (get<0>(on) == mirror.size())
                continue;

            switch (mirror[get<0>(on)][get<1>(on)])
            {
            case '/':
                get<2>(on) = 'l';
                break;
            case '\\':
                get<2>(on) = 'r';
                break;
            case '-':
                get<2>(on) = 'r';
                light.push_back({get<0>(on), get<1>(on), 'l'});
                break;
            default:
                break;
            }
        }
        bool done = false;
        foe(i, moves)
        {
            if (i == on)
            {
                done = true;
                break;
            }
        }
        if (done)
            continue;
        if (mirror[get<0>(on)][get<1>(on)] != '.')
            moves.push_back(on);

        light.push_back(on);
        heat[get<0>(on)][get<1>(on)] = true;
    }
    ll total = 0;
    foe(rw, heat)
    {
        foe(i, rw)
        {
            if (i)
                total++;
        }
    }
    return total;
}

void p1()
{
    string x;
    vstr mirror;
    while (cin >> x)
    {
        mirror.push_back(x);
    }
    auto total = totalHeat(mirror, {0, -1, 'r'});
    cout << total << endl;
}

void p2()
{
    string x;
    vstr mirror;
    while (cin >> x)
    {
        mirror.push_back(x);
    }
    ll maxx = 0;

    fo(r, 0, mirror.size())
    {
        maxx = max(maxx, totalHeat(mirror, {r, -1, 'r'}));
        maxx = max(maxx, totalHeat(mirror, {r, mirror[0].length(), 'l'}));
    }
    fo(c, 0, mirror[0].length())
    {
        maxx = max(maxx, totalHeat(mirror, {-1, c, 'd'}));
        maxx = max(maxx, totalHeat(mirror, {mirror.size(), c, 'u'}));
    }

    cout << maxx << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}
