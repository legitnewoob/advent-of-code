#include<bits/stdc++.h>
using namespace std;



int parse_num(string s , int &i , int number = 0)
{
    while(i < s.size() and s[i] >= '0' and s[i] <= '9')
    {
        number = number * 10 + (s[i] - '0');
        i++;
    }

    return number;
}

void testcase() 
{
    string s;
    int answer = 0 , count = 0;
    map<int , int> card_count;
    

    while(getline(cin , s))
    {
        int n = s.size() , index = 0 , my_answer = 0;
        map<int , int> map;

        while(index < n and (s[index] < '0' or s[index] > '9')) index++;

        int card_no = parse_num(s , index);

        card_count[card_no]++;

        while(index < n and (s[index] < '0' or s[index] > '9')) index++;

  
        for( ; s[index] != '|' ; index++)
        {
            if(s[index] >= '0' and s[index] <= '9')
            {
                int number = parse_num(s , index);

                map[number]++;
            }
        }


        for( ; index < n ; index++)
        {
            if(s[index] >= '0' and s[index] <= '9')
            {
                int number = parse_num(s , index);
                if(map[number] != 0)
                {
                    my_answer++;
                }
            }
        }

        for(int i = card_no + 1 ; i <= 202 and i <= card_no + my_answer ; i++)
        {
            card_count[i] += card_count[card_no];
        }
    }

    for(auto &[x , y] : card_count) answer += y;

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



/*

Better sol by queue sirs

#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    #ifndef ONLINE_JUDGE
            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
        #endif



    vector<int>answer(1e5, 1); string s; cin >> s; int lines = 0;

    while(cin >> s)
    {
        lines++; int same = 0;

        set<string>set;

        while(cin >> s)
        {
            if(s == "|") break;
            else set.insert(s);
        }

        while(cin >> s)
        {
            if(s == "Card") break;
            else same += set.count(s);
        }

        for(int i = lines; i < lines + same; i++) answer[i] += answer[lines - 1];
    }

    cout << accumulate(answer.begin(), answer.begin() + lines, 0ll) << "\n";
}
*/
