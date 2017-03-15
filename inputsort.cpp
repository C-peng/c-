#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct errorlog{
    string name;
    int line;
    int count;
};


string getname(string name){
    int nameSize = name.length();  
    int index = -1;  
    for (int i = nameSize - 1; i >= 0; --i)  
    {  
        if (name[i] == '\\') //注意！  
        {  
            index = i;  
            break;  
        }  
    }  
    name = name.substr(index + 1); 
    return name;
}


void process(vector<errorlog>& v,errorlog log){
    bool isrepeat = false;  
    for (int i = 0; i < v.size(); ++i)  
    {  
        if (v[i].name == log.name && v[i].line == log.line)  
        {  
            v[i].count++;  
            isrepeat = true;  
            break;  
        }  
    }  
    if (isrepeat == false)  
    {  
        //if (res.size() < 8)  
        //{  
            v.push_back(log);  
        //}  
          
    }  
}

static bool Compare(const errorlog& a, const errorlog& b)  
{  
    return a.count>b.count;  
} 


int main(){
    
    int line;
    string s;
    errorlog log;
    vector<errorlog> v;
    
    while(cin>>s>>line){
        s = getname(s);
        log.name = s;
        log.line = line;
        log.count = 1;
        process(v,log);
    }
    
    sort(v.begin(), v.end(),Compare);
    for (int i = 0; i < 8; ++i)  
    {  
        int len = v[i].name.length();  
        if (len>16)  
            v[i].name = v[i].name.substr(len - 16);  
        cout << v[i].name << " " << v[i].line << " " << v[i].count << endl;  
    }     
    
    return 0;
}
