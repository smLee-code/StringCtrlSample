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