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

bool compare1(string s1, string s2, map<char, int> &mp)
{
    vector<int> num1(15);
    vector<int> num2(15);

    for (auto i = 0; i < s1.length(); i++)
    {
        num1[mp[s1[i]]]++;
        num2[mp[s2[i]]]++;
    }
    double max1 = 0, max2 = 0;
    for (auto i = 0; i < num1.size(); i++)
    {
        max1 = max(max1, num1[i] * 1.0);
        max2 = max(max2, num2[i] * 1.0);
    }

    if (max1 == 3) // for full house
    {
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num1[i] == 2)
            {
                max1 = 3.5;
                break;
            }
        }
    }
    if (max1 == 2) // for two pair
    {
        // cout << "2Pair"<<endl;
        bool on = false;
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num1[i] == 2)
            {
                if (on)
                {
                    max1 = 2.5;
                    break;
                }
                else
                {
                    on = true;
                }
            }
        }
    }
    if (max2 == 3) // for full house
    {
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num2[i] == 2)
            {
                max2 = 3.5;
                break;
            }
        }
    }
    if (max2 == 2) // for two pair
    {
        bool on = false;
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num2[i] == 2)
            {
                if (on)
                {
                    max2 = 2.5;
                    break;
                }
                else
                {
                    on = true;
                }
            }
        }
    }
    if (max1 > max2)
        return true;
    if (max1 < max2)
        return false;
    for (auto i = 0; i < s1.length(); i++)
    {
        if (mp[s1[i]] > mp[s2[i]])
            return true;
        if (mp[s1[i]] < mp[s2[i]])
            return false;
    }
    return true;
}

void p1()
{

    map<char, int> mp;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['T'] = 10;
    mp['J'] = 11;
    mp['Q'] = 12;
    mp['K'] = 13;
    mp['A'] = 14;

    vector<pair<string, int>> vc;

    string tmp;
    int tmp2;
    while (cin >> tmp)
    {
        cin >> tmp2;
        vc.push_back({tmp, tmp2});
    }

    for (auto i = 0; i < vc.size(); i++)
    {
        for (auto j = i + 1; j < vc.size(); j++)
        {
            if (compare1(vc[i].first, vc[j].first, mp))
            {
                pair<string, int> tm = vc[i];
                vc[i] = vc[j];
                vc[j] = tm;
            }
        }
    }

    ll total = 0;
    for (auto i = 0; i < vc.size(); i++)
    {
        total += (i + 1) * vc[i].second;
        // cout << vc[i].first << endl;
    }
    cout << total << endl;
}

bool compare2(string s1, string s2, map<char, int> &mp)
{
    vector<int> num1(15);
    vector<int> num2(15);

    int j1 = 0, j2 = 0;

    for (auto i = 0; i < s1.length(); i++)
    {
        if (s1[i] != 'J')
            num1[mp[s1[i]]]++;
        else
            j1++;

        if (s2[i] != 'J')
            num2[mp[s2[i]]]++;
        else
            j2++;
    }
    double max1 = 0, max2 = 0;
    for (auto i = 0; i < num1.size(); i++)
    {
        max1 = max(max1, num1[i] * 1.0);
        max2 = max(max2, num2[i] * 1.0);
    }
    for (auto i = 0; i < num1.size(); i++)
    {
        if (num1[i] == (int)max1)
        {
            num1[i] += j1;
            max1 += j1;
        }
        if (num2[i] == (int)max2)
        {
            num2[i] += j2;
            max2 += j2;
        }
    }

    if (max1 == 3) // for full house
    {
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num1[i] == 2)
            {
                max1 = 3.5;
                break;
            }
        }
    }
    if (max1 == 2) // for two pair
    {
        // cout << "2Pair"<<endl;
        bool on = false;
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num1[i] == 2)
            {
                if (on)
                {
                    max1 = 2.5;
                    break;
                }
                else
                {
                    on = true;
                }
            }
        }
    }
    if (max2 == 3) // for full house
    {
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num2[i] == 2)
            {
                max2 = 3.5;
                break;
            }
        }
    }
    if (max2 == 2) // for two pair
    {
        bool on = false;
        for (auto i = 0; i < num1.size(); i++)
        {
            if (num2[i] == 2)
            {
                if (on)
                {
                    max2 = 2.5;
                    break;
                }
                else
                {
                    on = true;
                }
            }
        }
    }
    if (max1 > max2)
        return true;
    if (max1 < max2)
        return false;
    for (auto i = 0; i < s1.length(); i++)
    {
        if (mp[s1[i]] > mp[s2[i]])
            return true;
        if (mp[s1[i]] < mp[s2[i]])
            return false;
    }
    return true;
}

void p2()
{

    map<char, int> mp;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['T'] = 10;
    mp['J'] = 1;
    mp['Q'] = 12;
    mp['K'] = 13;
    mp['A'] = 14;

    vector<pair<string, int>> vc;

    string tmp;
    int tmp2;
    while (cin >> tmp)
    {
        cin >> tmp2;
        vc.push_back({tmp, tmp2});
    }

    for (auto i = 0; i < vc.size(); i++)
    {
        for (auto j = i + 1; j < vc.size(); j++)
        {
            if (compare2(vc[i].first, vc[j].first, mp))
            {
                pair<string, int> tm = vc[i];
                vc[i] = vc[j];
                vc[j] = tm;
            }
        }
    }

    ll total = 0;
    for (auto i = 0; i < vc.size(); i++)
    {
        total += (i + 1) * vc[i].second;
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
