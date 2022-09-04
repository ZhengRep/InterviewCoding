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

// ====================测试代码====================
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
    // 输入0，期待的输出是0
    Test(0, 0);

    // 输入1，期待的输出是1
    Test(1, 1);

    // 输入10，期待的输出是2
    Test(10, 2);

    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);

    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);

    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);

    return 0;
}


/*
Think:
1. about for loop to while loop: make my program flexible
2.可以一直右移，右移就是除2 
*/