#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\lab7.3\Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rowCount = 2;
			int colCount = 2;
			int k = 0;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 9;  a[0][1] = 3;
			a[1][0] = 0;  a[1][1] = -2;


			int srch = Search(a,rowCount,colCount, k);
			Assert::AreEqual(k + 1, 1);

		}
	};
}
