#include "pch.h"
#include "MyString.h"

// 디폴트 생성자
CMyString::CMyString() : m_pszData(nullptr), m_nLength(0)
{
	// cout << "CMyString()" << endl;
}

// 변환 생성자
CMyString::CMyString(const char* pszParam) : m_pszData(nullptr), m_nLength(0)
{
	// cout << "CMyString(const char*) : " << pszParam << endl;

	SetString(pszParam);
}

// 복사 생성자
CMyString::CMyString(const CMyString &rhs) : m_pszData(nullptr), m_nLength(0)
{
	// cout << "CMyString(const CMyString &)" << endl;

	this->SetString(rhs.GetString());
}

// 이동 생성자
CMyString::CMyString(CMyString &&rhs)
{
	// cout << "CMyString(CMyString &&)" << endl;

	// 원본은 곧 소멸되므로 얕은 복사 수행.
	this->m_pszData = rhs.m_pszData; 
	this->m_nLength = rhs.m_nLength;

	// 해제하지 않고 초기화
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

// 소멸자
CMyString::~CMyString()
{
	// cout << "~CMyString()" << endl;

	Release();
}

int CMyString::SetString(const char* pszParam)
{
	// 새로운 문자열 할당에 앞서 기존 정보를 해제 (문자열 NULL 초기화, 문자열 길이 0으로 설정)
	Release();

	// NULL 값을 받은 경우 : 기존 문자열을 해제하고 NULL로 초기화만 하는 것이다.
	if (pszParam == NULL)
		return 0;

	int nLength = strlen(pszParam);

	// 문자열 길이가 0인 경우 : 역시 기존 문자열을 해제하는 것으로 본다.
	if (nLength == 0)
		return 0;

	// 문자열 끝의 NULL 문자 때문에 길이가 1 늘어남을 고려한다.
	m_pszData = new char[nLength + 1];

	// pszParam 에서,  sizeof(char) * (nLength + 1) 크기만큼, m_pszData 에 복사한다.
	strcpy_s(m_pszData, sizeof(char) * (nLength + 1), pszParam);
	m_nLength = nLength;

	// 미래를 호출한다! (추후 파생 클래스에서 OnSetString을 재정의 하여 호출.)
	OnSetString(m_pszData, m_nLength);

	return nLength;
}

// SetString 의 미래를 구현하기 위해 남겨둔 virtual method
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
	// 매개변수 유효성 검사
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	// 세트된 문자열이 없다면 새로 문자열을 할당한 것과 동일하게 처리
	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	// 현재 문자열 길이 백업
	int nLenCur = m_nLength;

	// 두 문자열을 합쳐서 저장 가능한 메모리를 새로이 할당
	char* pszResult = new char[nLenCur + nLenParam + 1];

	// 문자열 조합
	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	// 기존 문자열 삭제 및 멤버 정보 갱신
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

// 형변환 연산자
CMyString::operator char* () const
{
	// cout << "operator char*()" << endl;

	return m_pszData;
}

// 일반 대입 연산자
CMyString& CMyString::operator=(const CMyString &rhs)
{
	// cout << "operator=" << endl;

	if (this != &rhs)
		this->SetString(rhs.GetString());

	return *this;
}

// 이동 대입 연산자
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
