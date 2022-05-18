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

	/* ��� �ڵ� : ���͸� ���ڿ��� ��Ȯ�� ��ġ���� ������ �ȵȴ�.
	int nResultLen;

	if (strcmp(pszParam, "�۸��̾Ƶ�") == 0)
		nResultLen = CMyString::SetString("���� ���");
	else
		nResultLen = CMyString::SetString(pszParam);

	return nResultLen;
	*/

	// Ǯ�� �ڵ� : ���͸� ���ڿ��� ���Ը� ���־ ���͸� �Ѵ�.
	int nResultLen = SetString(pszParam);

	if (strstr(GetString(), "�۸��̾Ƶ�") != NULL)
		return CMyString::SetString("���� ���");

	return nResultLen;
}