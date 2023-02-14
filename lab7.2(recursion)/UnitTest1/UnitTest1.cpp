#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\lab7.2(recursion)\Source.cpp"

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
			int n, min,max;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			a[0][0] = 3;
			a[0][1] = 0;
			a[1][0] = -1;
			a[1][1] = 1;


			Change(a, n,min,max,0,0,rowCount,colCount,0);
			Assert::AreEqual(a[0][1], 3);
		}
	};
}
