#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    vector<int> v;
    cout << "Number of vector's element : " << endl;
    int number;
    cin >> number;
    for (int i = 0; i < number; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
