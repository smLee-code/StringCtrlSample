// StringCtrlSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "MyStringEx.h"

void TestFunc()
{
	
}

int main()
{
	CMyStringEx strTest;

	// 문자열 필터링 및 대체되는 경우
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;

	// 문자열 필터링되지 않는 경우
	strTest.SetString("Hello");
	cout << strTest << endl;

	return 0;
}