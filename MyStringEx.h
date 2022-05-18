#pragma once
#include "MyString.h"
class CMyStringEx : public CMyString
{
private:

public:
	void SetString(const char* pszParam);
	int Find(const char* pszParam);
};

