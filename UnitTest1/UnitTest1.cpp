#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication2/ConsoleApplication2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethodFindWordl1)
		{

			char Test[100];
			char l = 'a';
			char strTest[100] = "I";
			char* result = findWords(strTest, 'i', Test);
			printf("%s\n", result);
			Assert::AreEqual("i ", result);
		}
		TEST_METHOD(TestMethodFindWordl2)
		{

			char Test[100];
			char l = 'a';
			char strTest[100] = " ";
			char* result = findWords(strTest, 'i', Test);
			printf("%s\n", result);
			Assert::AreEqual("", result);
		}
		TEST_METHOD(TestMethodFindWordl3)
		{

			char Test[100];
			char l = 'a';
			char strTest[100] = "Dog, cat, cow, Hot Dog ";
			char* result = findWords(strTest, 'g', Test);
			printf("%s\n", result);
			Assert::AreEqual("dog dog ", result);
		}
		TEST_METHOD(TestMethodFindWordl4)
		{

			char Test[100];

			char strTest[100] = " dog:anti-flag";
			char* result = findWords(strTest, 'g', Test);
			printf("%s\n", result);
			Assert::AreEqual("dog anti-flag ", result);
		}
	};
}
