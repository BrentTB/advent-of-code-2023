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

// bool valid(string &str, vint &dmg)
// {
//     int index = 0;
//     int length = 0;
//     str += '.';
//     foe(ch, str)
//     {
//         if (ch == '.' && length != 0)
//         {
//             // cout << "e"<<endl;
//             if (length != dmg[index])
//             {
//                 // cout << "a"<<endl;
//                 return false;
//             }
//             length = 0;
//             index++;
//         }
//         elif (ch == '#')
//         {
//             // cout << "d"<<endl;
//             length++;
//         }
//     }
//     if (length != 0)
//     {
//         if (length != dmg[index])
//         {
//             // cout << "b"<<endl;
//             return false;
//         }
//         length = 0;
//         index++;
//     }
//     // cout << index<<endl;
//     if (index != dmg.size())
//     {
//         // cout << "c"<<endl;
//         return false;
//     }

//     return true;
// }

// tuple<bool, int, int> valid2(string &str, vint &dmg, int idx, int posS) // works, index on, where to start the string
// {
//     int index = idx;
//     int length = 0;
//     int pos = posS;
//     str += '.';
//     fo(i, posS, str.length())
//     {
//         auto ch = str[i];
//         if (ch == '?')
//         {
//             return {length <= dmg[index], index, pos};
//         }
//         if (ch == '.' && length != 0)
//         {
//             if (index == dmg.size() || length != dmg[index])
//             {
//                 return {false, 0, 0};
//             }
//             length = 0;
//             index++;
//             pos = i;
//         }
//         elif (ch == '#')
//         {
//             length++;
//         }
//     }
//     if (length != 0)
//     {
//         if (length != dmg[index])
//         {
//             return {false, 0, 0};
//         }
//         length = 0;
//         index++;
//         pos = str.length();
//     }
//     if (index != dmg.size())
//     {
//         return {false, 0, 0};
//     }

//     return {true, index, pos};
// }

// ll recur(string str, vint &dmg, int idx, int posS)
// {
//     auto res = valid2(str, dmg, idx, posS);
//     if (!get<0>(res))
//         return 0;
//     ll sum = 0;
//     int index = str.find('?');
//     if (index >= 0)
//     {
//         str[index] = '.';
//         sum += recur(str, dmg, get<1>(res), get<2>(res));

//         str[index] = '#';
//         sum += recur(str, dmg, get<1>(res), get<2>(res));
//     }
//     else
//     {
//         return 1;
//     }
//     return sum;
// }

ll recur2(string &str, vint &dmg, int dmgIdx, int pos, int length, map<tuple<int, int, int>, ll> &dp)
{
    ll sum = 0;
    tuple<int, int, int> info = {dmgIdx, pos, length};
    auto fnd = dp.find(info);
    if (fnd != dp.end())
    {
        return dp[info];
    }

    if (pos == str.length() && dmgIdx == dmg.size())
        return 1;

    elif (str[pos] == '.' && length != 0)
    {
        if (dmg[dmgIdx] != length)
            return 0;
        else
            return recur2(str, dmg, dmgIdx + 1, pos + 1, 0, dp);
    }
    elif (str[pos] == '.' && length == 0)
    {
        return recur2(str, dmg, dmgIdx, pos + 1, 0, dp);
    }
    elif (str[pos] == '#' && dmgIdx >= dmg.size()) return 0;
    elif (str[pos] == '#' && length + 1 > dmg[dmgIdx])
    {
        return 0;
    }
    elif (str[pos] == '#')
    {
        return recur2(str, dmg, dmgIdx, pos + 1, length + 1, dp);
    }

    elif (str[pos] == '?' && dmgIdx >= dmg.size())
    {
        return recur2(str, dmg, dmgIdx, pos + 1, 0, dp);
    }
    elif (str[pos] == '?' && length != 0 && length != dmg[dmgIdx])
    {
        return recur2(str, dmg, dmgIdx, pos + 1, length + 1, dp);
    }
    elif (str[pos] == '?' && length == dmg[dmgIdx])
    {
        return recur2(str, dmg, dmgIdx + 1, pos + 1, 0, dp);
    }
    elif (str[pos] == '?')
    {
        sum += recur2(str, dmg, dmgIdx, pos + 1, 0, dp);
        sum += recur2(str, dmg, dmgIdx, pos + 1, 1, dp);
    }

    dp[info] = sum;
    return sum;
}

void p1()
{
    string x;
    string row;
    ll sum = 0;
    while (cin >> row)
    {
        vint damaged;
        cin >> x;
        istringstream iss(x);

        while (getline(iss, x, ','))
        {
            damaged.push_back(stoi(x));
        }

        row += ".";
        map<tuple<int, int, int>, ll> dp;
        sum += recur2(row, damaged, 0, 0, 0, dp);
    }
    cout << sum << endl;
}

void p2()
{

    string x;
    string row, rw;
    ll sum = 0;
    while (cin >> row)
    {
        vint damaged, dmg;
        cin >> x;
        istringstream iss(x);

        while (getline(iss, x, ','))
        {
            damaged.push_back(stoi(x));
        }
        fo(i, 0, 5)
        {
            foe(j, damaged)
                dmg.push_back(j);
        }
        rw = row + "?" + row + "?" + row + "?" + row + "?" + row;

        rw += ".";
        map<tuple<int, int, int>, ll> dp;
        sum += recur2(rw, dmg, 0, 0, 0, dp);
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
