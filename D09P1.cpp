#include<bits/stdc++.h>
using namespace std;

int parse_num(string s , int &index , int number = 0)
{
    bool neg = false;
    if(s[index] == '-') {index++; neg = true;}
    while(index < s.size() and s[index] >= '0' and s[index] <= '9')
    {
        number = number * 10 + (s[index] - '0');
        index++;
    }
    if(neg) return -1 * number;
    return number;
}


int extrapol(vector<int> v)
{
    vector<vector<int>> decks;
    decks.push_back(v);

    while(true)
    {
        vector<int> temp;

        for(int i = 0 ; i < decks.back().size() - 1; i++)
        {
            temp.push_back(decks.back()[i + 1] - decks.back()[i]);
        }

        decks.push_back(temp);

        if(temp.back() == 0 and temp.front() == 0) break;
    }

    decks.back().push_back(0);

    int len = decks.size() - 2;

    for( ; len >= 0 ; len--)
    {
        int this_size = decks[len].size() , that_size = decks[len + 1].size();
        decks[len].push_back(decks[len][this_size - 1] + decks[len + 1][that_size - 1]);
    }


    return decks[0].back();
}

void testcase() 
{
    string s; int answer = 0;

    while(getline(cin , s))
    {
        vector<int> v;

        int index = 0;

        while(index < s.size())
        {
            int num = parse_num(s , index);
            v.push_back(num);
            index++;
        }
        // reverse(v.begin() , v.end());
        // for(auto &i : v) cout << i << " "; cout << endl;
        answer += extrapol(v);
    }   

    cout << answer << endl;
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
