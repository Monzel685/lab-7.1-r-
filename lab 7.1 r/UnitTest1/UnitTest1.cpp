#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 7.1 r/lab 7.1 r.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int S = 0;
            int k = 0;
            int** q = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                q[i] = new int[colCount];

            q[0][0] = 8; // парне, не кратне 8
            q[0][1] = 2; // парне, не кратне 8
            q[0][2] = 3; // непарне, не враховується
            q[1][0] = 4; // парне, не кратне 8
            q[1][1] = 5; // непарне, не враховується
            q[1][2] = 6; // парне, не кратне 8
            q[2][0] = 7; // непарне, не враховується
            q[2][1] = 8; // парне, кратне 8 (ігнорується)
            q[2][2] = 10; // парне, не кратне 8

            Calc(q, rowCount, colCount, S, k, 0, 0);

            Assert::AreEqual(30, S);
            Assert::AreEqual(5, k);

            for (int i = 0; i < rowCount; i++)
                delete[] q[i];
            delete[] q;
        }
    };
}
