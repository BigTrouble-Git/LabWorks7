#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\lab7.2\Source.cpp"

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
			int n;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];
			 a[0][0] = 3;
			 a[0][1] = 0;
			 a[1][0] = -1;
			 a[1][1] = 1;

			
			ChangeMinRow(a, n, rowCount, colCount, 0, 0);
			Assert::AreEqual(a[1][0], 1);

		}
	};
}
