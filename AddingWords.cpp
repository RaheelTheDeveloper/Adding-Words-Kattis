#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Addingwords {

   public:
        map<string,int> mp;
        map<string,int>::iterator i;
        
      void def(string key, int val){
            if (mp.count(key)){     //update if the key exists
               mp[key] = val;
            }
            else{
               mp.insert(make_pair(key, val));
            }         
         }
         
      string calc(string k){
         istringstream iss(k);
         char op ='+';
         string token;
         int ans=0;
         while(iss>>token){
              if(mp.find(token)!=mp.end()){     //   cout <<"token here is:"<< token <<endl;
                  if(op=='+')
                     ans+=mp[token];
                  else
                     ans-=mp[token];
              }
              else return k + " " + "unknown";
              iss>>op;
           }
           
         string s1;
         
         for (i = mp.begin(); i !=mp.end(); i++) {
            if (i->second==ans) {
                s1= i->first;
               return k + " " + s1;
            }
         }
         return k + " " + "unknown";
      }
   };

int main() {
    
   Addingwords Awords;
   string command;

   while(cin >> command){
      if(command == "calc") {
         string key;
         getchar();
         getline(cin,key);
         cout << Awords.calc(key)<< endl;
      } 
      else if(command == "def") {
         string key;
         int value;
         cin >> key >> value;
         Awords.def(key,value);
      }
     else if(command == "clear") {
         Awords.mp.clear();
      }
      
   }
   return 0;
}
