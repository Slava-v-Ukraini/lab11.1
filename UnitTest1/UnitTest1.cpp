#include "pch.h"
#include "CppUnitTest.h"
#include "../PR11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestFileWithPairs)
        {
            // Arrange
            std::ofstream testFile("testfile1.txt");
            testFile << "a,-,b,c,-,d,e,-,"; // �� 3 ���� ",-"
            testFile.close();

            // Act
            int result = countComaTirePairs("testfile1.txt");

            // Assert
            Assert::AreEqual(3, result); // ���������� ��������� ��������
        }

        TEST_METHOD(TestFileWithoutPairs)
        {
            // Arrange
            std::ofstream testFile("testfile2.txt");
            testFile << "a.b,c;d-e"; // ���� ��� ",-"
            testFile.close();

            // Act
            int result = countComaTirePairs("testfile2.txt");

            // Assert
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestEmptyFile)
        {
            // Arrange
            std::ofstream testFile("testfile3.txt");
            testFile.close();

            // Act
            int result = countComaTirePairs("testfile3.txt");

            // Assert
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestNonexistentFile)
        {
            // Act
            int result = countComaTirePairs("nonexistentfile.txt");

            // Assert
            Assert::AreEqual(-1, result);
        }
    };
}
