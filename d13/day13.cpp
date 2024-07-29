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

int numDiff(string n1, string n2)
{
    int count = 0;
    fo(i, 0, n1.length())
    {
        if (n1[i] != n2[i])
            count++;
    }

    return count;
}

tuple<bool, ll> getScore1(vstr &arr) // true for vertical
{
    bool work = false;
    fo(i, 0, arr.size() - 1)
    {
        if (arr[i] == arr[i + 1])
        {
            work = true;
            fo(j, 0, arr.size())
            {
                if (i - j >= 0 && i + j + 1 < arr.size())
                {
                    if (arr[i - j] != arr[i + j + 1])
                    {
                        work = false;
                        break;
                    }
                }
                else
                    break;
            }
            if (work)
            {
                return {true, i + 1};
            }
        }
    }
    return {false, -1};
}

tuple<bool, ll> getScore2(vstr &arr) // true for vertical
{
    bool work = false;
    int totalMiss;
    fo(i, 0, arr.size() - 1)
    {
        totalMiss = 0;
        if (arr[i] == arr[i + 1])
        {
            work = true;
            fo(j, 0, arr.size())
            {
                if (i - j >= 0 && i + j + 1 < arr.size())
                {
                    if (arr[i - j] != arr[i + j + 1])
                    {
                        totalMiss += numDiff(arr[i - j], arr[i + j + 1]);
                        if (totalMiss > 1)
                        {
                            work = false;
                            break;
                        }
                    }
                }
                else
                    break;
            }
            if (work && totalMiss == 1)
            {
                return {true, i + 1};
            }
        }
        if (numDiff(arr[i], arr[i + 1]) == 1)
        {
            work = true;
            totalMiss = 1;
            fo(j, 1, arr.size())
            {
                if (i - j >= 0 && i + j + 1 < arr.size())
                {
                    if (arr[i - j] != arr[i + j + 1])
                    {
                        work = false;
                        break;
                    }
                }
                else
                    break;
            }
            if (work && totalMiss == 1)
            {
                return {true, i + 1};
            }
        }
    }
    return {false, -1};
}

void p1()
{
    ll horizontal = 0;
    ll vertical = 0;
    vstr arr;

    string x;
    while (getline(cin, x))
    {
        if (x.length() == 0)
        {
            auto val = getScore1(arr);
            if (!get<0>(val))
            {
                vstr newT(arr[0].length(), "");
                fo(i, 0, arr[0].length())
                {
                    fo(j, 0, arr.size())
                    {
                        newT[i].push_back(arr[j][i]);
                    }
                }
                val = getScore1(newT);
                horizontal += get<1>(val);
            }
            else
            {
                vertical += get<1>(val);
            }
            arr.clear();
        }
        else
        {
            arr.push_back(x);
        }
    }

    auto val = getScore1(arr);
    if (!get<0>(val))
    {
        vstr newT(arr[0].length(), "");
        fo(i, 0, arr[0].length())
        {
            fo(j, 0, arr.size())
            {
                newT[i].push_back(arr[j][i]);
            }
        }
        val = getScore1(newT);
        horizontal += get<1>(val);
    }
    else
    {
        vertical += get<1>(val);
    }
    arr.clear();

    cout << (100 * vertical + horizontal) << endl;
}
void p2()

{
    ll horizontal = 0;
    ll vertical = 0;
    vstr arr;

    string x;
    // while (cin >> x)
    while (getline(cin, x))
    {
        if (x.length() == 0)
        {
            auto val = getScore2(arr);
            if (!get<0>(val))
            {
                vstr newT(arr[0].length(), "");
                fo(i, 0, arr[0].length())
                {
                    fo(j, 0, arr.size())
                    {
                        newT[i].push_back(arr[j][i]);
                    }
                }
                val = getScore2(newT);
                horizontal += get<1>(val);
            }
            else
            {
                vertical += get<1>(val);
            }
            arr.clear();
        }
        else
        {
            arr.push_back(x);
        }
    }

    auto val = getScore2(arr);
    if (!get<0>(val))
    {
        vstr newT(arr[0].length(), "");
        fo(i, 0, arr[0].length())
        {
            fo(j, 0, arr.size())
            {
                newT[i].push_back(arr[j][i]);
            }
        }
        val = getScore2(newT);
        horizontal += get<1>(val);
    }
    else
    {
        vertical += get<1>(val);
    }
    arr.clear();

    cout << (100 * vertical + horizontal) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}
