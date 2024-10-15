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

    for (int idx : v) {
        cout << idx << endl;
    }
    
    return 0;
}
