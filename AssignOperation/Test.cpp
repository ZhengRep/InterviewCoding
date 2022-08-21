/*
to test:
1. the end of str is '\0' - yes
2. print &str private value - yes
3. what is object reference - alias of object
*/

#include "CMyString.h"

//Test continues assign
void TestContinuesAssign()
{
	CMyString str1 = CMyString((char*)"Hello");

	CMyString str2 = CMyString((char*)"World");
	CMyString str3 = CMyString((char*)"World");
	
	
	str2 = str3 = str1;
}

//Test assign myself
void TestAssignMyself()
{
	CMyString str1 = CMyString((char*)"HelloWorld");

	CMyString str2 = CMyString(str1);

	str2 = str2;

}


void main()
{
	TestContinuesAssign();
	TestAssignMyself();
}