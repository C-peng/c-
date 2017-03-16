bool cmp(const pair<string,int>& a,const pair<string,int>& b)
{     return a.second>b.second;}
class Coder {
    public:    
    string change(string str)
    {       
        string ans=str;        
        for(int i=0;i<str.length();i++)            
            if(str[i]>='A'&&str[i]<='Z')              
                ans[i]=str[i]+32;               
        return ans;        
    }    
    vector<string> findCoder(vector<string> A, int n) 
    {         
        vector<pair<string,int> > array;         
        for(int i=0;i<n;i++)
        {             
            string str=change(A[i]);             
            int length=0;             
            int pos=str.find("coder");             
            while(pos!=-1){                 
                str=str.substr(pos+5);                 
                pos=str.find("coder");                
                length++;             
            }             
            if(length!=0)                 
                array.push_back(make_pair(A[i],length));             
        }        
        stable_sort(array.begin(),array.end(),cmp);        
        vector<string> ans;        
        for(int i=0;i<array.size();i++)
        {             
            ans.push_back(array[i].first);       
        }            
        return ans;    
    }
};
