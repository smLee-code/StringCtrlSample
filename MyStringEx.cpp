#include "pch.h"
#include "MyStringEx.h"

void CMyStringEx::SetString(const char* pszParam)
{
	SetString(pszParam);

	if (strstr(GetString(), "¸Û¸ÛÀÌ¾Æµé") != NULL)
		SetString("ÂøÇÑ »ç¶÷");
}

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;

	char* pszResult = strstr(GetString(), pszParam);
	
	if (pszResult != NULL)
		return pszResult - GetString();
	
	return -1;

}