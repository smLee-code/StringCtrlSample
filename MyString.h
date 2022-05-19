#pragma once
class CMyString
{
protected:
	// ���ڿ� ������ ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;

	// ����� ���ڿ��� ����
	int m_nLength;
	
public:
	CMyString();
	explicit CMyString(const char* pszParam);
	CMyString(const CMyString &rhs);
	CMyString(CMyString &&rhs);
	~CMyString();

	int SetString(const char* pszParam);
	virtual void OnSetString(char* pszData, int nLength);
	char* GetString() const;
	int GetLength() const;
	int Append(const char* pszParam);
	void Release();

	operator char* () const;
	CMyString& operator=(const CMyString &rhs);
	CMyString& operator=(CMyString &&rhs);
	CMyString operator+(const CMyString &rhs);
	friend CMyString operator+(const char* pszParam, const CMyString& strParam);
	CMyString& operator+=(const CMyString &rhs);
	int operator==(const CMyString &rhs);
	int operator!=(const CMyString &rhs);
	char& operator[] (int nIndex);
	char operator[] (int nIndex) const;
	
};