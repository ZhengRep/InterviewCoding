#include "CMyString.h"

CMyString::CMyString(char* pData)
{
	if (pData == NULL) {
		m_pData = new char[1];
		*m_pData = '\0';
	}
	else {
		int length = strlen(pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, pData);
		//*(m_pData + length + 1) = '\0';
		// m_pData[length + 1] = '\0'; strcpy can copy null terminater character
	}
}

CMyString::CMyString(const CMyString& str)
{
	int length = strlen(str.m_pData);
	m_pData = new char[length + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)
{
	/*if (this != &str) {
		delete[] m_pData;
		int length = strlen(str.m_pData);
		m_pData = new char[length + 1];
		strcpy(m_pData, str.m_pData);
	}
	return *this;*/

	if (this != &str) {
		/*
		first to allocate memory
		then to judge is safe
		*/

	}
	return *this;
}
