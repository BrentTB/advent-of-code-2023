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
    string x, tmp, tmp2;
    vector<vector<string>> dest;
    vector<vector<bool>> memory;
    vector<bool> state;
    vector<char> type;
    map<string, int> mp;
    int idx = 0;

    getline(cin, x);
    mp["broadcaster"] = idx++;
    type.push_back('s');
    tmp = x.substr(x.find('>') + 2);

    istringstream iss1(tmp);

    dest.push_back({});
    while (getline(iss1, tmp2, ','))
    {
        if (tmp2[0] == ' ')
            tmp2 = tmp2.substr(1);
        dest[0].push_back(tmp2);
    }

    while (getline(cin, x))
    {
        type.push_back(x[0]);
        dest.push_back({});
        mp[x.substr(1, x.find(' ') - 1)] = idx;
        tmp = x.substr(x.find('>') + 2);
        istringstream iss(tmp);

        while (getline(iss, tmp2, ','))
        {
            if (tmp2[0] == ' ')
                tmp2 = tmp2.substr(1);
            dest[idx].push_back(tmp2);
        }
        idx++;
    }
    state.resize(dest.size());
    memory.resize(dest.size());

    fo(i, 0, type.size())
    {
        // if(type[i]=='%')
        // {
        //     state[i]=0;
        // }
        if (type[i] == '&')
        {
            memory[i].resize(dest.size());
            fo(j, 0, type.size())
            {
                memory[i][j] = true;
                foe(ind, dest[j])
                {
                    if (mp[ind] == i)
                    {
                        memory[i][j] = false;
                        break;
                    }
                }
            }
        }
    }

    // printall2d(memory);
    // return;

    ll low = 0, high = 0;

    fo(i, 0, 1000)
    {
        // cout << i << endl;
        queue<tuple<string, bool, string>> todo; // last stting is who sent it
        low++;
        foe(i, dest[0])
        {
            todo.push({i, 0, "broadcaster"});
            low++;
        }
        while (todo.size() > 0)
        {
            auto on = todo.front();
            todo.pop();
            // cout << get<0>(on) << endl;
            // cout << todo.size() << endl;

            if (type[mp[get<0>(on)]] == '%')
            {
                if (get<1>(on) == 1) // recieved a high pulse
                    continue;
                state[mp[get<0>(on)]] = !state[mp[get<0>(on)]];

                foe(i, dest[mp[get<0>(on)]])
                {
                    // cout << "pushing: " << i << endl;
                    if (mp.count(i) > 0)
                        todo.push({i, state[mp[get<0>(on)]], get<0>(on)});
                    if (state[mp[get<0>(on)]])
                        high++;
                    else
                        low++;
                }
            }
            if (type[mp[get<0>(on)]] == '&')
            {
                memory[mp[get<0>(on)]][mp[get<2>(on)]] = get<1>(on); // updating this element with the one it came from

                bool highB = true; // if true, it sends a lo pulse
                foe(b, memory[mp[get<0>(on)]])
                {
                    if (!b)
                    {
                        highB = false;
                        break;
                    }
                }

                foe(i, dest[mp[get<0>(on)]])
                {
                    if (mp.count(i) > 0)
                        todo.push({i, !highB, get<0>(on)});
                    if (!highB)
                        high++;
                    else
                        low++;
                }
            }
        }
        // cout <<low<<" "<<high<<endl;
    }

    cout << low * high << endl;
}

void p2() // ** This code does not work. The answer was found outside of the program
{

    string x, tmp, tmp2;
    vector<vector<string>> dest;
    vector<vector<bool>> memory;
    vector<bool> state;
    vector<char> type;
    map<string, int> mp;
    int idx = 0;

    getline(cin, x);
    mp["broadcaster"] = idx++;
    type.push_back('s');
    tmp = x.substr(x.find('>') + 2);

    istringstream iss1(tmp);

    dest.push_back({});
    while (getline(iss1, tmp2, ','))
    {
        if (tmp2[0] == ' ')
            tmp2 = tmp2.substr(1);
        dest[0].push_back(tmp2);
    }

    while (getline(cin, x))
    {
        type.push_back(x[0]);
        dest.push_back({});
        mp[x.substr(1, x.find(' ') - 1)] = idx;
        tmp = x.substr(x.find('>') + 2);
        istringstream iss(tmp);

        while (getline(iss, tmp2, ','))
        {
            if (tmp2[0] == ' ')
                tmp2 = tmp2.substr(1);
            dest[idx].push_back(tmp2);
        }
        idx++;
    }
    state.resize(dest.size());
    memory.resize(dest.size());

    fo(i, 0, type.size())
    {
        // if(type[i]=='%')
        // {
        //     state[i]=0;
        // }
        if (type[i] == '&')
        {
            memory[i].resize(dest.size());
            fo(j, 0, type.size())
            {
                memory[i][j] = true;
                foe(ind, dest[j])
                {
                    if (mp[ind] == i)
                    {
                        memory[i][j] = false;
                        break;
                    }
                }
            }
        }
    }

    // printall2d(memory);
    // return;

    ll low = 0, high = 0;
    int count = 0, i = 0;
    vstr loop{"tr", "xm", "dr", "nh"};

    while (true)
    {
        i++;
        count = 0;
        // cout << i << endl;
        queue<tuple<string, bool, string>> todo; // last stting is who sent it
        low++;
        foe(i, dest[0])
        {
            todo.push({i, 0, "broadcaster"});
            low++;
        }
        while (todo.size() > 0)
        {
            auto on = todo.front();
            todo.pop();
            // cout << get<0>(on) << endl;
            // cout << todo.size() << endl;

            if (type[mp[get<0>(on)]] == '%')
            {
                if (get<1>(on) == 1) // recieved a high pulse
                    continue;
                state[mp[get<0>(on)]] = !state[mp[get<0>(on)]];

                foe(i, dest[mp[get<0>(on)]])
                {
                    if (i == "rx")
                        count++;
                    // cout << "pushing: " << i << endl;
                    if (mp.count(i) > 0)
                        todo.push({i, state[mp[get<0>(on)]], get<0>(on)});
                    if (state[mp[get<0>(on)]])
                        high++;
                    else
                        low++;
                }
            }
            bool highB = true; // if true, it sends a low pulse
            if (type[mp[get<0>(on)]] == '&')
            {
                memory[mp[get<0>(on)]][mp[get<2>(on)]] = get<1>(on); // updating this element with the one it came from

                foe(b, memory[mp[get<0>(on)]])
                {
                    if (!b)
                    {
                        highB = false;
                        break;
                    }
                }

                foe(i, dest[mp[get<0>(on)]])
                {
                    if (i == "rx")
                        count++;
                    if (mp.count(i) > 0)
                        todo.push({i, !highB, get<0>(on)});
                    if (!highB)
                        high++;
                    else
                        low++;
                }

                foe(e, loop)
                {
                    if (highB && e == get<0>(on))

                        cout << "round: " << i << " string: " << get<0>(on) << endl;
                }
            }
        }
        // cout <<low<<" "<<high<<endl;
        cout << count << endl;
        if (count == 1)
        {
            cout << i << endl;
            break;
        }
    }

    // cout << low * high << endl;
}
// tr xm dr nh
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // p1();
    p2();
}
