#include<iostream>
#include<vector>
using namespace std;

//先写输入
//再写寻找最大值操作
//再写更新操作
int findmax(int* a, int j, int k){
    
    int max = a[j-1];
    
    
    for(int i = j;i < k ;i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    
    return max;
}

void update(int* a,int j, int k){
    a[j-1] = k;
}



int main(){
     
    int n,m;
    cin>>n;
    cin>>m;
    int* a = new int[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    
    char* c = new char[m];
    int* score = new int[2*m];
    for(int i = 0;i < m;i++){
        cin>>c[i];
        cin>>score[i * 2];
        cin>>score[i * 2 + 1];
    }
    
    int k;
    vector<int> v;
    for(int i = 0;i < m;i++){
        if(c[i] == 'Q'){
          
          k = findmax(a, min(score[i * 2], score[i * 2 + 1]), max(score[i * 2], score[i * 2 + 1])) ;  
          v.push_back(k);
        }
        if(c[i] == 'U'){
            update(a,score[i * 2], score[i * 2 + 1]);
        }
    }
    
    
    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<endl;
    }
    
    
    
    return 0;
}
