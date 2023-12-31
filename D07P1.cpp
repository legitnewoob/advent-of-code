#include<bits/stdc++.h>
using namespace std;
#define int long long

map<char , int> chart = {{'A' , 14} , {'K' , 13} , {'Q' , 12} , {'J' , 11} , {'T' , 10} , {'9' , 9} , {'8' , 8} , {'7' , 7} , {'6' , 6} , {'5' , 5} , {'4' , 4} , {'3' , 3} , {'2' , 2}};


int parse_num(string s , int index = 6 , int number = 0)
{
    while(index < s.size() and s[index] >= '0' and s[index] <= '9')
    {
        number = number * 10 + (s[index] - '0');
        index++;
    }
    return number;
}


int find_kind(string s)
{
    int count_5 = 0 , count_4 = 0 , count_3 = 0 , count_2 = 0;
    map<char , int> map;
    for(auto &i : s) map[i]++;

    for(auto &[x , y] : map)
    {
        if(y == 5) count_5++;
        if(y == 4) count_4++;
        if(y == 3) count_3++;
        if(y == 2) count_2++;
    }

    int value = 0;
   
    if(count_5 == 1) value = 7;
    else if(count_4 == 1) value = 6;
    else if(count_3 == 1 and count_2 == 1) value = 5;
    else if(count_3 == 1 and count_2 == 0) value = 4;
    else if(count_2 == 2 and count_3 == 0) value = 3;
    else if(count_2 == 1 and count_3 == 0) value = 2;
    else value = 1;

    return value;
}


bool cmp(const pair<int, string>& a, const pair<int, string>& b)
{
    if (a.first == b.first) 
    {
        for (int i = 0; i < 5; i++)
        {
            if (b.second[i] != a.second[i])
            {
                return chart[a.second[i]] < chart[b.second[i]];
            }
        }
    }

    return a.first < b.first;
}


void testcase() 
{
    string s;

    // for(auto &[x , y] : chart) cout << x << " " << y << endl;

    map<string , int> bidvalue;
    vector<pair<int , string>> card_deck;


    while(getline(cin , s))
    {
        int number = parse_num(s);
        string temp = s.substr(0 , 5);
        bidvalue[temp] = number;

        int value = find_kind(temp);
        
        card_deck.push_back({value , temp});

    }

    sort(card_deck.begin() , card_deck.end() , cmp);
    

    int rank = 1 , answer = 0;


    for(auto &[x , y] : card_deck)
    {
        // cout << bidvalue[y] << " " << y  << " " << x << endl;
        answer += (rank * bidvalue[y]);
        rank++;
    }


    cout << answer << endl;

}


int32_t main() 
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




/* Queue

#include<bits/stdc++.h>
using namespace std;

const string num = "AKQJT98765432";

int main()
{
    vector<pair<string,int>>a;
    string s;

    while(cin >> s)
    {
        int x; cin >> x;
        a.push_back({s, x});
    }

    sort(a.begin(), a.end(), [&](auto a, auto b)
    {
        string s = a.first, t = b.first;

        map<char,int>S, T;

        for(auto &i : s) S[i]++;
        for(auto &i : t) T[i]++;

        vector<int>ss, tt;

        for(auto &i : S) ss.push_back(i.second);
        for(auto &i : T) tt.push_back(i.second);

        sort(ss.begin(), ss.end(), greater());
        sort(tt.begin(), tt.end(), greater());

        for(int i = 0; i < min(ss.size(), tt.size()); i++)
        {
            if(ss[i] > tt[i]) return false;
            if(ss[i] < tt[i]) return true;
        }

        for(int i = 0; i < s.size(); i++)
        {
            int ii = num.find(s[i]), jj = num.find(t[i]);
            if(ii != jj) return ii > jj;
        }

        return false;
    });

    long long answer = 0;

    for(int i = 0; i < a.size(); i++)
    {
        answer += (i + 1) * a[i].second;
    }

    cout << answer << "\n";
}
*/
