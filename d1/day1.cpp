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

    vector<string> all;

    string x;
    while (cin >> x)
    {
        all.push_back(x);
    }

    int sum = 0;
    for (auto word : all)
    {
        int current = 0;
        for (auto i = 0; i < word.size(); i++)
        {
            if (isnumber(word[i]))
            {
                current = 10 * ((word[i]) - '0');
                break;
            }
        }

        for (auto i = word.size() - 1; i >= 0; i--)
        {
            if (isnumber(word[i]))
            {
                current += ((word[i]) - '0');
                break;
            }
        }
        sum += current;
    }
    cout << sum << endl;
}

void p2()
{

    map<string, string> mp;
    mp["zero"] = "0";
    mp["one"] = "1";
    mp["two"] = "2";
    mp["three"] = "3";
    mp["four"] = "4";
    mp["five"] = "5";
    mp["six"] = "6";
    mp["seven"] = "7";
    mp["eight"] = "8";
    mp["nine"] = "9";

    vector<string> all;

    string x;
    while (cin >> x)
    {
        all.push_back(x);
    }

    int sum = 0;
    for (auto word : all)
    {
        string tmp = word;

        for (auto i = 0; i < word.size(); i++)
        {
            for (auto j : mp)
            {
                if (word.substr(i, j.first.size()) == j.first)
                {
                    word = word.substr(0, i) + j.second + word.substr(i + j.first.size(), word.length() - j.first.size() - i);
                    break;
                }
            }
        }

        int current = 0;
        for (auto i = 0; i < word.size(); i++)
        {
            if (isnumber(word[i]))
            {
                current = 10 * ((word[i]) - '0');
                break;
            }
        }

        word = tmp;

        for (int i = word.size() - 1; i >= 0; i--)
        {

            for (auto j : mp)
            {
                if (word.substr(i, j.first.size()) == j.first)
                {
                    word = word.substr(0, i) + j.second + word.substr(i + j.first.size(), word.length() - j.first.size() - i);
                    break;
                }
            }
        }
        for (auto i = word.size() - 1; i >= 0; i--)
        {
            if (isnumber(word[i]))
            {
                current += ((word[i]) - '0');
                break;
            }
        }
        sum += current;
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
