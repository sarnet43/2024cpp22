#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    vector<string> v = { "롯데관광", "동화면세점", "제주드림타워", "마이데일리"};

    for (auto str : v) {
        cout << str << endl;
    }


    return 0;
}
