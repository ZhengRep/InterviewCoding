#include<stdio.h>

int NumberOfOneInBinaryByAssembly(int value)
{
	int sum = 0;
	int andValue;
	while(value)
	{
		andValue = value & 0x1;
		if (andValue == 1) {
			sum++;
			_asm {
				shr value, 0x1
			}
		}
		else
		{
			__asm {
				shr value, 0x1
			}
		}
	}
	return sum;
}

int NumberOfOneInBinary(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if (n & flag)
            count++;

        flag = flag << 1;
    }

    return count;
}

int perfect(int n)
{
    int count = 0;
    unsigned int flag;
    while (n)
    {
        count++;
        n = (n - 1) & n; //n - 1 only change rightmost 1 to 0, and left all is changed to 0. 
    }
    return count;
}

// ====================���Դ���====================
void Test(int number, unsigned int expected)
{
    int actual = NumberOfOneInBinary(number);
    if (actual == expected)
        printf("Test for %d passed.\n", number);
    else
        printf("Test for %d failed.\n", number);
}

int main(int argc, char* argv[])
{
    // ����0���ڴ��������0
    Test(0, 0);

    // ����1���ڴ��������1
    Test(1, 1);

    // ����10���ڴ��������2
    Test(10, 2);

    // ����0x7FFFFFFF���ڴ��������31
    Test(0x7FFFFFFF, 31);

    // ����0xFFFFFFFF�����������ڴ��������32
    Test(0xFFFFFFFF, 32);

    // ����0x80000000�����������ڴ��������1
    Test(0x80000000, 1);

    return 0;
}


/*
Think:
1. about for loop to while loop: make my program flexible
2.����һֱ���ƣ����ƾ��ǳ�2 
*/