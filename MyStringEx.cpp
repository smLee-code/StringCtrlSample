#include "pch.h"
#include "MyStringEx.h"

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;

	char* pszResult = strstr(GetString(), pszParam);
	
	if (pszResult != NULL)
		return pszResult - GetString();
	
	return -1;

}

void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "¸Û¸ÛÀÌ¾Æµé") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*ÂøÇÑ¾Æµé*");
}