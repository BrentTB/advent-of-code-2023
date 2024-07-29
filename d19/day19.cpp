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

    map<string, int> mp;
    map<char, int> mp2;
    mp2['x'] = 0;
    mp2['m'] = 1;
    mp2['a'] = 2;
    mp2['s'] = 3;
    int idx = 0;
    string x, tmp;

    vector<vstr> workf;
    vector<tuple<int, int, int, int>> xmas;

    bool workflow = true;
    while (getline(cin, x))
    {
        if (x.length() == 0)
        {
            workflow = false;
            continue;
        }
        if (workflow)
        {
            mp[x.substr(0, x.find('{'))] = idx++;
            // cout << x.substr(x.find('{') + 1,x.length()-1-x.find('{') -1)<<endl;

            istringstream iss(x.substr(x.find('{') + 1, x.length() - 1 - x.find('{') - 1));
            vstr temp;
            while (getline(iss, tmp, ','))
                temp.push_back(tmp);
            workf.push_back(temp);
        }
        else
        {
            istringstream iss(x.substr(1, x.length() - 2));
            vint xm;
            while (getline(iss, tmp, ','))
            {
                xm.push_back(stoi(tmp.substr(2)));
            }
            xmas.push_back({xm[0], xm[1], xm[2], xm[3]});
        }
    }
    ll sum = 0;
    string on;
    int idxx;
    foe(val, xmas)
    {
        on = "in";
        idxx = 0;
        // cout << "start"<<endl;

        while (true)
        {

            string rule = workf[mp[on]][idxx];
            // cout << rule << endl;

            if (on == "A")
            {
                // cout <<"accept"<<endl;
                sum += get<0>(val) + get<1>(val) + get<2>(val) + get<3>(val);
                break;
            }
            elif (on == "R")
            {
                // cout << "reject"<<endl;
                break;
            }
            elif (rule.find(':') == -1)
            {
                on = rule;
                idxx = 0;
                continue;
            }
            bool bigger;
            int vall = 0;
            switch (mp2[rule[0]])
            {
            case 0:
                vall = get<0>(val);
                break;
            case 1:
                vall = get<1>(val);
                break;
            case 2:
                vall = get<2>(val);
                break;
            case 3:
                vall = get<3>(val);
                break;
            }
            if (vall > stoi(rule.substr(2, rule.find(':') - 2)))
                bigger = true;
            else
                bigger = false;

            if ((rule[1] == '>' && bigger) || (rule[1] == '<' && !bigger))
            {
                idxx = 0;
                on = rule.substr(rule.find(':') + 1);
            }
            else
            {
                idxx++;
            }
        }
    }
    cout << sum << endl;
}

ll recur(map<string, int> &mp, map<char, int> &mp2, vector<vstr> &workf, string on, int idxx, vector<pair<ll, ll>> possible)
{

    string rule = workf[mp[on]][idxx];

    if (on == "A")
        return (possible[0].first - possible[0].second - 1) * (possible[1].first - possible[1].second - 1) * (possible[2].first - possible[2].second - 1) * (possible[3].first - possible[3].second - 1);
    elif (on == "R") return 0;
    elif (rule.find(':') == -1) return recur(mp, mp2, workf, rule, 0, possible);

    if (rule[1] == '>')
    {
        auto tmp = possible;
        tmp[mp2[rule[0]]].second = min(stoll(rule.substr(2, rule.find(':') - 2)), tmp[mp2[rule[0]]].second);
        ll tmp1 = 0;
        if (tmp[mp2[rule[0]]].second < tmp[mp2[rule[0]]].first)
            tmp1 = 0;
        else
            tmp1 = recur(mp, mp2, workf, on, idxx + 1, tmp);

        tmp = possible;
        tmp[mp2[rule[0]]].first = max(stoll(rule.substr(2, rule.find(':') - 2)) + 1, tmp[mp2[rule[0]]].first);
        idxx = 0;
        on = rule.substr(rule.find(':') + 1);
        if (tmp[mp2[rule[0]]].second < tmp[mp2[rule[0]]].first)
            return tmp1;
        else
            return tmp1 + recur(mp, mp2, workf, on, 0, tmp);
    }
    else
    {
        auto tmp = possible;
        tmp[mp2[rule[0]]].first = max(stoll(rule.substr(2, rule.find(':') - 2)), tmp[mp2[rule[0]]].first);
        ll tmp1 = 0;
        if (tmp[mp2[rule[0]]].second < tmp[mp2[rule[0]]].first)
            tmp1 = 0;
        else
            tmp1 = recur(mp, mp2, workf, on, idxx + 1, tmp);

        tmp = possible;
        tmp[mp2[rule[0]]].second = min(stoll(rule.substr(2, rule.find(':') - 2)) - 1, tmp[mp2[rule[0]]].second);
        idxx = 0;
        on = rule.substr(rule.find(':') + 1);
        if (tmp[mp2[rule[0]]].second < tmp[mp2[rule[0]]].first)
            return tmp1;
        else
            return tmp1 + recur(mp, mp2, workf, on, 0, tmp);
    }
}

void p2()
{

    map<string, int> mp;
    map<char, int> mp2;
    mp2['x'] = 0;
    mp2['m'] = 1;
    mp2['a'] = 2;
    mp2['s'] = 3;
    int idx = 0;
    string x, tmp;

    vector<vstr> workf;
    vector<tuple<int, int, int, int>> xmas;

    bool workflow = true;
    while (getline(cin, x))
    {
        if (x.length() == 0)
        {
            workflow = false;
            continue;
        }
        if (workflow)
        {
            mp[x.substr(0, x.find('{'))] = idx++;

            istringstream iss(x.substr(x.find('{') + 1, x.length() - 1 - x.find('{') - 1));
            vstr temp;
            while (getline(iss, tmp, ','))
                temp.push_back(tmp);
            workf.push_back(temp);
        }
        else
        {
            istringstream iss(x.substr(1, x.length() - 2));
            vint xm;
            while (getline(iss, tmp, ','))
            {
                xm.push_back(stoi(tmp.substr(2)));
            }
            xmas.push_back({xm[0], xm[1], xm[2], xm[3]});
        }
    }

    string on = "in";
    int idxx = 0;
    vector<pair<ll, ll>> possible;
    possible.push_back({1, 4000}); // x
    possible.push_back({1, 4000}); // m
    possible.push_back({1, 4000}); // a
    possible.push_back({1, 4000}); // s

    cout << recur(mp, mp2, workf, on, idxx, possible) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
    // p2();
}
