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

bool hasS(v(string) & all, int r, int c)
{
    for (auto i = r - 1; i <= r + 1; i++)
    {
        if (i < 0 || i >= all.size())
            continue;
        for (auto j = c - 1; j <= c + 1; j++)
        {
            if (j < 0 || j >= all[i].length())
                continue;
            if (!isnumber(all[i][j]) && all[i][j] != '.')
            {
                return true;
            }
        }
    }
    return false;
}

tuple<bool, int, int> isG(v(string) & all, int r, int c)
{
    for (auto i = r - 1; i <= r + 1; i++)
    {
        if (i < 0 || i >= all.size())
            continue;
        for (auto j = c - 1; j <= c + 1; j++)
        {
            if (j < 0 || j >= all[i].length())
                continue;
            if (all[i][j] == '*')
            {
                return {true, i, j};
            }
        }
    }
    return {false, 0, 0};
}

void p1()
{

    string x;
    v(string) all;

    while (cin >> x)
        all.push_back(x);

    bool wasDigit = false;
    bool hasSymbol = false;
    ll sum = 0;
    ll tmp;
    for (auto i = 0; i < all.size(); i++)
    {
        tmp = 0;
        hasSymbol = false;
        wasDigit = false;
        for (auto j = 0; j < all[i].length(); j++)
        {
            if (isnumber(all[i][j]))
            {
                hasSymbol = hasSymbol ? true : hasS(all, i, j);
                wasDigit = true;
                tmp = tmp * 10 + all[i][j] - '0';
            }
            else
            {
                if (wasDigit)
                {
                    if (hasSymbol)
                    {
                        sum += tmp;
                    }
                    tmp = 0;
                    wasDigit = false;
                    hasSymbol = false;
                }
            }
            if (j == all[i].length() - 1)
            {
                if (hasSymbol)
                {
                    sum += tmp;
                }
                tmp = 0;
                wasDigit = false;
                hasSymbol = false;
            }
        }
    }

    cout << sum << endl;
}
void p2()
{

    string x;
    v(string) all;
    v(v(int)) gearRatio;

    while (cin >> x)
    {
        all.push_back(x);
    }

    gearRatio.resize(all.size());
    for (auto i = 0; i < all.size(); i++)
    {
        gearRatio[i].resize(all[i].length());
    }

    bool wasDigit = false;
    bool isGear = false;
    ll sum = 0;
    ll tmp;
    int row = 0, col = 0;
    for (auto i = 0; i < all.size(); i++)
    {
        tmp = 0;
        isGear = false;
        wasDigit = false;
        for (auto j = 0; j < all[i].length(); j++)
        {
            if (isnumber(all[i][j]))
            {
                auto IG = isG(all, i, j);
                if (get<0>(IG))
                {
                    isGear = true;
                    row = get<1>(IG);
                    col = get<2>(IG);
                }
                wasDigit = true;
                tmp = tmp * 10 + all[i][j] - '0';
            }
            else
            {
                if (wasDigit)
                {
                    if (isGear)
                    {
                        if (gearRatio[row][col] == 0)
                            gearRatio[row][col] = tmp;
                        else
                            sum += gearRatio[row][col] * tmp;
                    }
                    tmp = 0;
                    wasDigit = false;
                    isGear = false;
                }
            }
            if (j == all[i].length() - 1)
            {
                if (isGear)
                {
                    if (gearRatio[row][col] == 0)
                        gearRatio[row][col] = tmp;
                    else
                        sum += gearRatio[row][col] * tmp;
                }
                tmp = 0;
                wasDigit = false;
                isGear = false;
            }
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
