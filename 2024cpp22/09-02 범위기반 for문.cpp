#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    vector<int> v;
    v.push_back(12);
    v.push_back(20);
    v.push_back(34);
    v.push_back(65);
    v.push_back(87);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    
    return 0;
}
