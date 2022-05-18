#pragma once
#include "MyString.h"
class CMyStringEx : public CMyString
{
private:

public:
	int Find(const char* pszParam);
	int SetString(const char* pszParam);
};

