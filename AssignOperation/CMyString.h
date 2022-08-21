#pragma once

#include<string>

#pragma warning(disable:4996)

class CMyString
{
public:
	CMyString(char* pData);
	CMyString(const CMyString& str);
	~CMyString();

	//operation
	CMyString& operator = (const CMyString & str);

private:
	char* m_pData;
};

