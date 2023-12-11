#include<bits/stdc++.h>
using namespace std;

void testcase() 
{
    string s; 

    map<char , int> map1;

    for(char c = '0' ; c <= '9' ; c++) 
    {
        map1[c] = c - '0';
    }


    int r = 12 , g = 13 , b = 14 , answer = 0;



    while(getline(cin , s))
    {
        int n = s.size() , i = 0;


        int id = s[5] - '0';

        if(map1.count(s[7])) 
        {
            id = 100;
            i = 10;
        }
        else if(map1.count(s[6]))
        {
            id = (s[5] - '0') * 10 + (s[6] - '0');
            i = 9;
        }
        else
        {
            id = (s[5] - '0');
            i = 8;
        }


        bool possible = true;

        int maxr = 0 , maxg = 0 , maxb = 0;
        

         while(i < n)
        {
           int val = 0;
           if(i + 1 < n and map1.count(s[i + 1]))
           {
               val += 10 * (s[i] - '0');
               val += (s[i + 1] - '0');
               i += 3;
           }
           else
           {
                  val += (s[i] - '0');
                  i += 2;
           }


           string temp = "";

           

           while(i < n)
           {
                  if(s[i] == ',' or s[i] == ';') break;
               temp.push_back(s[i]);
               i++;
           }



           if(temp == "red") maxr = max(maxr , val);
           if(temp == "blue") maxb = max(maxb , val);
           if(temp == "green") maxg = max(maxg , val);

           i += 2;
        }

        // cout << endl;


        answer += (maxg * maxr * maxb);
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
