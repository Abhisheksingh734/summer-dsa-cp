#include <bits/stdc++.h>
using namespace std;

void dfs(string source, unordered_map<string, vector<string>> &map, vector<string> &res)
{
    vector<string> &st = map[source];

    while (!st.empty())
    {
        string back = st.back();

        st.pop_back();
        dfs(back, map, res);
    }

    res.push_back(source);
}

vector<string> findItinerary(vector<vector<string>> tickets)
{
    unordered_map<string, vector<string>> map;

    for (auto t : tickets)
    {
        map[t[0]].push_back(t[1]);
    }
    vector<string> res;

    dfs("JFK", map, res);
    reverse(res.begin(), res.end()); // Reverse to get correct order

    return res;
}

int main()
{
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};

    vector<string> itinerary = findItinerary(tickets);

    for (string airport : itinerary)
    {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}