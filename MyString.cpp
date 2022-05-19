#include "pch.h"
#include "MyString.h"

// ����Ʈ ������
CMyString::CMyString() : m_pszData(nullptr), m_nLength(0)
{
	// cout << "CMyString()" << endl;
}

// ��ȯ ������
CMyString::CMyString(const char* pszParam) : m_pszData(nullptr), m_nLength(0)
{
	// cout << "CMyString(const char*) : " << pszParam << endl;

	SetString(pszParam);
}

// ���� ������
CMyString::CMyString(const CMyString &rhs) : m_pszData(nullptr), m_nLength(0)
{
	// cout << "CMyString(const CMyString &)" << endl;

	this->SetString(rhs.GetString());
}

// �̵� ������
CMyString::CMyString(CMyString &&rhs)
{
	// cout << "CMyString(CMyString &&)" << endl;

	// ������ �� �Ҹ�ǹǷ� ���� ���� ����.
	this->m_pszData = rhs.m_pszData; 
	this->m_nLength = rhs.m_nLength;

	// �������� �ʰ� �ʱ�ȭ
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

// �Ҹ���
CMyString::~CMyString()
{
	// cout << "~CMyString()" << endl;

	Release();
}

int CMyString::SetString(const char* pszParam)
{
	// ���ο� ���ڿ� �Ҵ翡 �ռ� ���� ������ ���� (���ڿ� NULL �ʱ�ȭ, ���ڿ� ���� 0���� ����)
	Release();

	// NULL ���� ���� ��� : ���� ���ڿ��� �����ϰ� NULL�� �ʱ�ȭ�� �ϴ� ���̴�.
	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);

	// ���ڿ� ���̰� 0�� ��� : ���� ���� ���ڿ��� �����ϴ� ������ ����.
	if (nLength == 0)
		return 0;

	// ���ڿ� ���� NULL ���� ������ ���̰� 1 �þ�� ����Ѵ�.
	m_pszData = new char[nLength + 1];

	// pszParam ����,  sizeof(char) * (nLength + 1) ũ�⸸ŭ, m_pszData �� �����Ѵ�.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	// �̷��� ȣ���Ѵ�! (���� �Ļ� Ŭ�������� OnSetString�� ������ �Ͽ� ȣ��.)
	OnSetString(m_pszData, m_nLength);

	return nLength;
}

// SetString �� �̷��� �����ϱ� ���� ���ܵ� virtual method
void CMyString::OnSetString(char* pszData, int nLength) { }

char* CMyString::GetString() const
{
	return m_pszData;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	// �Ű����� ��ȿ�� �˻�
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	// ��Ʈ�� ���ڿ��� ���ٸ� ���� ���ڿ��� �Ҵ��� �Ͱ� �����ϰ� ó��
	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// ���� ���ڿ� ���� ���
	int nLenCur = m_nLength;

	// �� ���ڿ��� ���ļ� ���� ������ �޸𸮸� ������ �Ҵ�
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// ���ڿ� ����
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	// ���� ���ڿ� ���� �� ��� ���� ����
	Release();
	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;
	
	return m_nLength;
}

void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}

// ����ȯ ������
CMyString::operator char* () const
{
	// cout << "operator char*()" << endl;

	return m_pszData;
}

// �Ϲ� ���� ������
CMyString& CMyString::operator=(const CMyString &rhs)
{
	// cout << "operator=" << endl;

	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

// �̵� ���� ������
CMyString& CMyString::operator=(CMyString &&rhs)
{
	// cout << "operator=(Move)" << endl;

	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;

	return *this;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
	// cout << "operator+" << endl;

	CMyString tmpResult(m_pszData);			// CMyString tmpResult(*this);
	tmpResult.Append(rhs.GetString());

	return tmpResult;
}

CMyString operator+(const char* pszParam, const CMyString& strParam)
{
	CMyString strResult(pszParam);
	strResult.Append(strParam.m_pszData);

	return strResult;
}

CMyString& CMyString::operator+=(const CMyString &rhs)
{
	// cout << "operator+=" << endl;

	Append(rhs.GetString());

	return *this;
}

int CMyString::operator==(const CMyString &rhs)
{
	// cout << "operator==" << endl;

	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;

	return 0;
}

int CMyString::operator!=(const CMyString &rhs)
{
	// cout << "operator!=" << endl;

	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;

	return 1;
}


char& CMyString::operator[] (int nIndex)
{
	return m_pszData[nIndex];
}

char CMyString::operator[] (int nIndex) const
{
	return m_pszData[nIndex];
}
