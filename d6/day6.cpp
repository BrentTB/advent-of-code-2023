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
    ll tmp;
    vll time;
    vll distance;

    getline(cin, x);
    istringstream iss1(x.substr(x.find(':') + 1));
    while (iss1 >> tmp)
        time.push_back(tmp);

    getline(cin, x);
    istringstream iss2(x.substr(x.find(':') + 1));
    while (iss2 >> tmp)
        distance.push_back(tmp);

    ll mul = 1;
    for (auto i = 0; i < time.size(); i++)
    {
        for (auto j = 0; j < time[i]; j++)
        {
            if (j * (time[i] - j) > distance[i])
            {
                // cout <<  time[i]-2*j<<endl;
                mul *= 1 + time[i] - 2 * j;
                break;
            }
        }
    }
    cout << mul;
}

void p2()
{

    string x;
    string tmp;
    string timeS = "";
    string distanceS = "";

    getline(cin, x);
    istringstream iss1(x.substr(x.find(':') + 1));
    while (iss1 >> tmp)
        timeS += tmp;

    getline(cin, x);
    istringstream iss2(x.substr(x.find(':') + 1));
    while (iss2 >> tmp)
        distanceS += tmp;

    ll time = stoll(timeS);
    ll distance = stoll(distanceS);

    ll mul = 1;

    for (auto j = 0; j < time; j++)
    {
        if (j * (time - j) > distance)
        {
            mul *= 1 + time - 2 * j;
            break;
        }
    }
    cout << mul;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
