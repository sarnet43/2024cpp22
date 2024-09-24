﻿#include <iostream>
#include <vector>

using namespace std;

void main(void) {
	vector<long long> v;

	//미리 공간을 많이 확보하자, 성능을 위해
	v.reserve(100);


	//벡터 추가
	v.push_back(4);
	v.push_back(6);
	v.push_back(4567);
	v.push_back(632);
	v.push_back(225);
	v.push_back(46151545);

	//값 접근
	cout << v[0] << endl;
	cout << v.at(1) << endl;
	
	//값 수정
	cout << v[5] << endl;
	v[5] = 500000000;
	cout << v[5] << endl;

	//크기
	for (int i = 0; i < v.size(); i++) 
		cout << v[i] << endl;
	
	//끝의 값 제거
	v.pop_back();
	v.pop_back();

	cout << endl;
	//반복자 (iterator)
	vector<long long>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << endl;
}