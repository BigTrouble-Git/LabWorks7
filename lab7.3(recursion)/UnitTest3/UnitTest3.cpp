#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\lab7.3(recursion)\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod2)
		{
			int Low = -10;
			int High = 10;
			int rowCount = 2;
			int colCount = 2;
			int sumRaw = -1;
			int k = 0;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			Create(a, rowCount, colCount, Low, High, 0, 0);

			a[0][0] = -10;  a[0][1] = 0;
			a[1][0] = -4; 	a[1][1] = -6;
			
			Search(a, rowCount, colCount, 0, 0, k);
			Assert::AreEqual(k+1, 2);

		}
	};
}
