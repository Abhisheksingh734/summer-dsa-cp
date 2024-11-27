#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

void process_cb(map<int, vector<pair<int, int>>> &cb_map, vector<int> &bal, int curr_ts)
{
    while (!cb_map.empty() && cb_map.begin()->first <= curr_ts)
    {
        int cb_time = cb_map.begin()->first;
        for (const auto &cb : cb_map[cb_time])
        {
            int acc_id = cb.first;
            int amt = cb.second;
            bal[acc_id] += amt;
        }
        cb_map.erase(cb_time);
    }
}

vector<int> solution(vector<int> &bal, vector<string> &req)
{
    map<int, vector<pair<int, int>>> cb_map;

    for (int i = 0; i < req.size(); ++i)
    {
        stringstream ss(req[i]);
        string type;
        int ts, acc, amt;

        ss >> type >> ts >> acc >> amt;
        acc--;

        if (acc < 0 || acc >= bal.size())
        {
            return {-(i + 1)};
        }

        process_cb(cb_map, bal, ts);

        if (type == "deposit")
        {
            bal[acc] += amt;
        }
        else if (type == "withdraw")
        {
            if (bal[acc] < amt)
            {
                return {-(i + 1)};
            }
            bal[acc] -= amt;

            int cb_time = ts + 86400;
            cb_map[cb_time].emplace_back(acc, amt * 0.02);
        }
        else
        {
            return {-(i + 1)};
        }
    }

    if (!req.empty())
    {
        stringstream ss(req.back());
        int last_ts;
        ss >> last_ts;
        process_cb(cb_map, bal, last_ts);
    }

    return bal;
}

int main()
{
    vector<int> bal = {100, 200, 300};
    vector<string> req = {
        "deposit 10 1 50",
        "withdraw 20 2 100",
        "withdraw 30 3 150",
    };

    vector<int> res = solution(bal, req);

    for (int b : res)
    {
        cout << b << " ";
    }
    cout << endl;

    return 0;
}
