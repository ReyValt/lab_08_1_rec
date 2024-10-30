#include "pch.h"
#include "CppUnitTest.h"
#include "../pr_08_1_rec/pr_08_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestContainsWhileLetters_Basic)
		{
			Assert::IsTrue(ContainsWhileLetters("The while", 0, false, false, false, false, false)); 
			Assert::IsFalse(ContainsWhileLetters("This lacks some letters", 0, false, false, false, false, false)); 
		}

		TEST_METHOD(TestReplaceWhile_Basic)
		{
			char str1[] = "Check while here";
			char dest1[100];
			ReplaceWhile(str1, dest1, 0);
			Assert::AreEqual("Check ** here", dest1);

			char str2[] = "Testing while and while together";
			char dest2[100];
			ReplaceWhile(str2, dest2, 0);
			Assert::AreEqual("Testing ** and ** together", dest2);
		}
	};
}
