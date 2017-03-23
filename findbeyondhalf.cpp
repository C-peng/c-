class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        sort(gifts.begin(),gifts.end());
        int mid = gifts[n / 2];  
        int num = 0;  
        for (int i = 0; i < n; i++) {  
            if (gifts[i] == mid) {  
                num++;  
            }  
        }  
        return num > n / 2 ? mid : 0;
        
    }
};
