#include <iostream>

using namespace std;

//열거형 정의
enum FoodStyle {
    KOREAN, //0 (0은 디폴트값이고 값을 주고 싶으면 korean = 0으로 한다)
    JAPANESE, //1
    CHINESE //2
};

int main(void) {
    //열거형을 사용하면 가독성도 좋아지고, 중간에 값을 유연하게 추가할 수 있다.
    FoodStyle style = KOREAN; 

    switch (style) {
    case KOREAN:
        cout << "김치, 쌈, 비빔밥" << endl;
        break;
    case JAPANESE:
        cout << "초밥, 타코야끼" << endl;
        break;
    case CHINESE:
        cout << "동파육, 마라탕후루" << endl;
        break;
    default:
        break;
    }

    return 0;
}
