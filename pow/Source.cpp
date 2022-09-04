#include<stdio.h>

bool equal(double valueOne, double valueTwo)
{
    if (valueOne - valueTwo > 0.0000001 || valueTwo - valueOne > 0.0000001) return false;
    return true;
}

double GetPowValueWithUnsignedExponent(double base, unsigned int exponent)
{
    /*double result = 1.0;
    for (int i = 0; i < exponent; i++)
    {
        result *= base;
    }
    return result;*/

    
}

double GetPowValue(double base, int exponent)
{
    if (exponent == 0) return 1;
    if (equal(base, 0)) return 0;

    unsigned int absExponent = exponent;
    if (exponent < 0) absExponent = -exponent;

    double result = GetPowValueWithUnsignedExponent(base, absExponent);

    if (exponent < 0) return 1 / result;

    return result;
}

// ====================���Դ���====================
void Test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    printf(testName); printf(":\n");
    double result = GetPowValue(base, exponent);
    printf("the result: %f\n", result);
    printf("the expect result: %f\n", expectedResult);
}

int main(int argc, char* argv[])
{
    // ������ָ����Ϊ����
    Test("Test1", 2, 3, 8, false);

    // ����Ϊ������ָ��Ϊ����
    Test("Test2", -2, 3, -8, false);

    // ָ��Ϊ����
    Test("Test3", 2, -3, 0.125, false);

    // ָ��Ϊ0
    Test("Test4", 2, 0, 1, false);

    // ������ָ����Ϊ0
    Test("Test5", 0, 0, 1, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test6", 0, 4, 0, false);

    // ����Ϊ0��ָ��Ϊ����
    Test("Test7", 0, -4, 0, true);

    return 0;
}
