#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\lab7.1\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int S = 0;
			int k = 0;
			
			int rowCount = 8;
			int colCount = 6;
			int** Z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				Z[i] = new int[colCount];
			
			Create(Z, rowCount, colCount, -2, 1);
			Calc(Z, rowCount, colCount, S, k);
			Assert::AreEqual(k, 27);

		}
	};
}
