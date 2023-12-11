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
    

    while(getline(cin , s))
    {
        int n = s.size() , index = 0 , my_answer = 0;
        map<int , int> map;

        while(index < n and (s[index] < '0' or s[index] > '9')) index++;

        parse_num(s , index);

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
                    if(my_answer) my_answer *= 2;
                    else my_answer++;
                }
            }
        }

        answer += my_answer;
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
