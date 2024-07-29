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

    v(vll) winning;
    v(vll) real;
    ll tmp;

    string x;

    while (getline(cin, x))
    {
        winning.push_back(vll(0));
        real.push_back(vll(0));
        auto cl = x.find(':');
        x = x.substr(cl + 1, x.length() - cl - 1);
        istringstream iss1(x.substr(0, x.find('|') + 2));
        while (iss1 >> tmp)
            winning[winning.size() - 1].push_back(tmp);

        istringstream iss2(x.substr(x.find('|') + 1, x.length()));
        while (iss2 >> tmp)
            real[real.size() - 1].push_back(tmp);
    }

    ll sum = 0;
    for (auto i = 0; i < winning.size(); i++)
    {
        int score = 0;
        for (auto val : real[i])
        {
            for (auto winVal : winning[i])
            {
                if (val == winVal)
                {
                    score = !score ? 1 : score * 2;
                    break;
                }
            }
        }
        sum += score;
    }
    cout << sum << endl;
}

void p2()
{

    v(vll) winning;
    v(vll) real;
    ll tmp;

    string x;

    while (getline(cin, x))
    {
        winning.push_back(vll(0));
        real.push_back(vll(0));
        auto cl = x.find(':');
        x = x.substr(cl + 1, x.length() - cl - 1);
        istringstream iss1(x.substr(0, x.find('|') + 2));
        while (iss1 >> tmp)
            winning[winning.size() - 1].push_back(tmp);

        istringstream iss2(x.substr(x.find('|') + 1, x.length()));
        while (iss2 >> tmp)
            real[real.size() - 1].push_back(tmp);
    }

    int numCards = 0;
    vll todo;

    for (auto i = 0; i < winning.size(); i++)
    {
        todo.push_back(i);
    }

    while (todo.size() != 0)
    {
        numCards++;
        int val = todo.back();
        todo.pop_back();
        int count = 0;
        for (auto i = 0; i < real[val].size(); i++)
        {
            auto realVal = real[val][i];
            for (auto winVal : winning[val])
            {
                if (realVal == winVal)
                {
                    count++;
                    break;
                }
            }
        }
        for (auto i = 0; i < count; i++)
            todo.push_back(val + i + 1);
    }
    cout << numCards << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    p1();
    // p2();
}