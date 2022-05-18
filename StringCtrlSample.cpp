// StringCtrlSample.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "MyStringEx.h"

void TestFunc(const CMyString& strParam)
{
	cout << strParam[0] << endl;
	cout << strParam[strParam.GetLength() - 1] << endl;
}

int main()
{
	CMyStringEx strTest;
	strTest.SetString("멍멍이아들");
	cout << strTest << endl;

	return 0;
}