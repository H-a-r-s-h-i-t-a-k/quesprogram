// According to the solutions I've seen here, this is probably the simplest possible solution, hope it helps someone :)

#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    string s;
    queue<string>qu;
    map<string, string>mp;
    string cur = "", lst = "";
    while(cin >> s){
        if(qu.size() >= q)
            qu.pop();
        qu.push(s);
        if(s[0] == '<'){
            if(s[1] == '/'){
                while(!cur.empty() && cur.back() != '.'){
                    cur.pop_back();
                }
                if(!cur.empty())
                    cur.pop_back();
            }
            else{
                s.erase(0, 1);
                if(s.back() == '>') 
                   s.pop_back();
                if(!cur.empty())
                    cur += "." + s;
                else
                    cur += s;
            }
        }
        else if(s[0] == '='){
            cin >> s;
            s.erase(0, 1);
            while(s.back() == '"' || s.back() == '>'){
                s.pop_back();
            }
            string q = cur + '~' + lst;
            mp[q] = s;
            // cout << q << ' ' << mp[q] << endl;  
        }
        lst = s;
    }
    while(!qu.empty()){
        if(mp.find(qu.front()) == mp.end())
            cout << "Not Found!\n";
        else 
            cout << mp[qu.front()] << endl;
        qu.pop();
    }
    return 0;
}

select city, char_length(city) from station where city like "a%" order by CHAR_LENGTH(city) asc limit 1; select city, char_length(city) from station order by CHAR_LENGTH(city) desc limit 1;
elect distinct city from station where city like '[aeiou]%';
SELECT
    DISTINCT CITY
FROM
    STATION
WHERE
    SUBSTR(UPPER(CITY),1,1) IN ('A','E','I','O','U');