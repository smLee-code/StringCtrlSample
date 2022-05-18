#include "pch.h"
#include "MyStringEx.h"

CMyStringEx::CMyStringEx() { }

CMyStringEx::CMyStringEx(const char* pszParam) : CMyString(pszParam) { }

CMyStringEx::~CMyStringEx() { }

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;

	char* pszResult = strstr(GetString(), pszParam);
	
	if (pszResult != NULL)
		return pszResult - GetString();
	
	return -1;

}

int CMyStringEx::SetString(const char* pszParam)
{

	/* 답안 코드 : 필터링 문자열과 정확히 일치하지 않으면 안된다.
	int nResultLen;

	if (strcmp(pszParam, "멍멍이아들") == 0)
		nResultLen = CMyString::SetString("착한 사람");
	else
		nResultLen = CMyString::SetString(pszParam);

	return nResultLen;
	*/

	// 풀이 코드 : 필터링 문자열이 포함만 되있어도 필터링 한다.
	int nResultLen = SetString(pszParam);

	if (strstr(GetString(), "멍멍이아들") != NULL)
		return CMyString::SetString("착한 사람");

	return nResultLen;
}