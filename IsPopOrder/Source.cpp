#include<cstdio>
#include<stack>

/*
push value to stack untill its top is pop top, unless 
*/
bool isPopOrder(int* pushOrder, int* popOrder, int length)
{
	if (!pushOrder || !popOrder || length < 1) return false;

	std::stack<int> stack;
	int pushIndex = 0, popIndex = 0;

	//push value to stack
	//if stack top is equal to pop array, pop
	//push all end top is not same pop array, return false
	//first push and judge is same and pop

	do {
		stack.push(pushOrder[pushIndex++]);

		while(!stack.empty() && stack.top() == popOrder[popIndex]) {
			stack.pop();
			popIndex++;
		}

	} while (pushIndex < length);
	if (popIndex == length) return true;
	return false;
}

void test(const char* description, int* pushOrder, int* popOrder, int length, bool expect)
{
	printf("%s :\t", description);
	if (isPopOrder(pushOrder, popOrder, length) == expect) {
		printf("passed!\n");
	}
	else {
		printf("failed!\n");
	}
}

void test1()
{
	const int length = 1;
	int pushOrder[length] = { 1 };
	int popOrder[length] = { 1 };
	test("test one value and same", pushOrder, popOrder, length, true);
}

void test2()
{
	const int length = 1;
	int pushOrder[length] = { 1 };
	int popOrder[length] = { 2 };
	test("test one value and same", pushOrder, popOrder, length, false);
}

void test3()
{
	const int length = 3;
	int pushOrder[length] = { 1, 2, 3 };
	int popOrder[length] = { 2, 1, 3 };
	test("test three value", pushOrder, popOrder, length, true);
}

void test4()
{
	const int length = 3;
	int pushOrder[length] = { 1, 2, 3 };
	int popOrder[length] = { 3, 2, 1 };
	test("test reverse", pushOrder, popOrder, length, true);
}

void test5()
{
	const int length = 3;
	int pushOrder[length] = { 1, 2, 3 };
	int popOrder[length] = { 1, 2, 3 };
	test("same array", pushOrder, popOrder, length, true);
}

void test6()
{
	const int length = 3;
	int pushOrder[length] = { 1, 2, 3 };
	int popOrder[length] = { 4, 2, 3 };
	test("have not same value", pushOrder, popOrder, length, false);
}


void test7()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 5, 3, 2, 1 };

	test("test7", push, pop, nLength, true);
}

void test8()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 2, 1 };

	test("test8", push, pop, nLength, true);
}

void test9()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 4, 3, 5, 1, 2 };

	test("test9", push, pop, nLength, false);
}

void test10()
{
	const int nLength = 5;
	int push[nLength] = { 1, 2, 3, 4, 5 };
	int pop[nLength] = { 3, 5, 4, 1, 2 };

	test("test10", push, pop, nLength, false);
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	return 0;
}