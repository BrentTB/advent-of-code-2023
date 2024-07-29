#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
    string tmp1, tmp2;
    // ll bound1 = 7, bound2 = 27;
    ll bound1 = 200000000000000, bound2 = 400000000000000;
    vector<tuple<ll, ll, ll>> pos;
    vector<tuple<ll, ll, ll>> velocity;
    ll x, y, z;

    while (getline(cin, tmp1))
    {
        istringstream iss1(tmp1);
        getline(iss1, tmp2, '@');

        istringstream iss(tmp2);
        getline(iss, tmp2, ',');
        x = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss, tmp2, ',');
        y = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss, tmp2);
        z = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);

        pos.push_back({x, y, z});

        getline(iss1, tmp2);

        istringstream iss4(tmp2);
        getline(iss4, tmp2, ',');
        x = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss4, tmp2, ',');
        y = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss4, tmp2);
        z = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);

        velocity.push_back({x, y, z});
    }
    vector<pair<ld, ld>> line;
    fo(i, 0, pos.size())
    {
        ld m = 1.0 * get<1>(velocity[i]) / get<0>(velocity[i]);
        ld c = 1.0 * get<1>(pos[i]) - m * get<0>(pos[i]); // c = y-m*x
        line.push_back({m, c});
    }

    int count = 0;
    fo(i, 0, pos.size())
    {
        fo(j, i + 1, pos.size())
        {
            if (line[i].first == line[j].first)
                continue; // parralel lines never meet
            ld xCollide = (line[i].second - line[j].second) / (line[j].first - line[i].first);
            ld yCollide = line[j].first * xCollide + line[j].second;

            if (xCollide >= bound1 && xCollide <= bound2 && yCollide >= bound1 && yCollide <= bound2)                               // they passed in the bounds
                if ((xCollide - get<0>(pos[i])) * get<0>(velocity[i]) > 0 && (xCollide - get<0>(pos[j])) * get<0>(velocity[j]) > 0) // they pass in the future
                    count++;
        }
    }
    cout << count << endl;
}

void p2() // i did not get this working, I ended up eventually using z3 in python
{

    string tmp1, tmp2;
    // ll bound1 = 7, bound2 = 27;
    ll bound1 = 200000000000000, bound2 = 400000000000000;
    vector<tuple<ll, ll, ll>> pos;
    vector<tuple<ll, ll, ll>> velocity;
    ll x, y, z;

    while (getline(cin, tmp1))
    {
        istringstream iss1(tmp1);
        getline(iss1, tmp2, '@');

        istringstream iss(tmp2);
        getline(iss, tmp2, ',');
        x = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss, tmp2, ',');
        y = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss, tmp2);
        z = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);

        pos.push_back({x, y, z});

        getline(iss1, tmp2);

        istringstream iss4(tmp2);
        getline(iss4, tmp2, ',');
        x = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss4, tmp2, ',');
        y = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);
        getline(iss4, tmp2);
        z = stoll(tmp2[0] == ' ' ? tmp2.substr(1) : tmp2);

        velocity.push_back({x, y, z});
    }
    ld time = 0; // ll?

    tuple<ll, ll, ll> posT, velocityT;

    while (true) 
    {


        // find possible solutions



        bool work = true;
        fo(i, 0, pos.size())
        {

            time = (get<0>(pos[i]) - get<0>(posT)) / (get<0>(velocityT) - get<0>(velocity[i]));
            if (get<1>(pos[i]) + get<1>(velocity[i]) * time == get<1>(posT) + get<1>(velocityT) * time)
                if (get<2>(pos[i]) + get<2>(velocity[i]) * time == get<2>(posT) + get<2>(velocityT) * time)
                {
                    continue;
                }

            work=false;
            break;
        }
        if(work) break;
    }
    while (true)
    {
        // find possible solutions

        int countHit = 0;
        bool work = false;
        while (true)
        {

            fo(i, 0, pos.size())
            {
                if (get<0>(pos[i]) + get<0>(velocity[i]) * time == get<0>(posT) + get<0>(velocityT) * time)
                    if (get<1>(pos[i]) + get<1>(velocity[i]) * time == get<1>(posT) + get<1>(velocityT) * time)
                        if (get<2>(pos[i]) + get<2>(velocity[i]) * time == get<2>(posT) + get<2>(velocityT) * time)
                        {
                            countHit++;
                            continue;
                        }

                if (abs(get<0>(pos[i]) + get<0>(velocity[i]) * time - get<0>(posT) + get<0>(velocityT) * time) > abs(get<0>(pos[i]) + get<0>(velocity[i]) * (time - 1) - get<0>(posT) + get<0>(velocityT) * (time - 1)))
                    if (abs(get<1>(pos[i]) + get<1>(velocity[i]) * time - get<1>(posT) + get<1>(velocityT) * time) > abs(get<1>(pos[i]) + get<1>(velocity[i]) * (time - 1) - get<1>(posT) + get<1>(velocityT) * (time - 1)))
                        if (abs(get<2>(pos[i]) + get<2>(velocity[i]) * time - get<2>(posT) + get<2>(velocityT) * time) > abs(get<2>(pos[i]) + get<2>(velocity[i]) * (time - 1) - get<2>(posT) + get<2>(velocityT) * (time - 1)))
                            goto out;
            }

            time++;

            if (countHit == pos.size())
            {
                work = true;
                break;
            }
        }
    out:
        if (work)
            break;
    }

    cout << get<0>(posT) + get<1>(posT) + get<2>(posT) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    p1();
}
