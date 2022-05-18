#pragma once
#include "MyString.h"
class CMyStringEx : public CMyString
{
private:

public:
	explicit CMyStringEx(const char* pszParam);

	int Find(const char* pszParam);
	int SetString(const char* pszParam);
};

