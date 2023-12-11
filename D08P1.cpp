#include<bits/stdc++.h>
using namespace std;

void testcase() 
{

    string rule; cin >> rule;
    // cout << rule << endl;

    map<string , vector<string>> map;

    string s;
    while(cin >> s)
    {
        string a , b; cin >> a >> b;
        map[s].push_back(a);
        map[s].push_back(b);
    }

    


    int count = 0 , index = 0; string curr = "AAA";

    while(curr != "ZZZ")
    {
        int new_idx = -1;
        if(rule[index] == 'L') new_idx = 0;
        else new_idx = 1;
        curr = map[curr][new_idx]; 
        count++;
        index = (index + 1) % (rule.size());
    }

    cout << count << endl;
}


int main() 
{

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif

    int tc = 1;
    //cin >> tc;
    while(tc--) testcase();

    return 0;
}
