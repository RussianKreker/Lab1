﻿#include "pch.h"
#include "CppUnitTest.h"
#include <G:\Программирование\2 курс\1 сем\Project1\Project1\LinkedList.h>
#include <G:\Программирование\2 курс\1 сем\Project1\Project1\LinkedList.cpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(push_back_1)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(1);
			lst->push_back(2);
			Assert::IsTrue(lst->at(0) == 1);
		}

		TEST_METHOD(push_back_2)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(1);
			lst->push_back(2);
			Assert::IsTrue(lst->at(1) == 2);
		}

		TEST_METHOD(push_front_1)
		{
			LinkedList* lst = new LinkedList;
			lst->push_front(1);
			lst->push_front(2);
			Assert::IsTrue(lst->at(0) == 2);
		}

		TEST_METHOD(push_front_2)
		{
			LinkedList* lst = new LinkedList;
			lst->push_front(1);
			lst->push_front(2);
			Assert::IsTrue(lst->at(1) == 1);
		}

		TEST_METHOD(pop_back_front)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(9);
			lst->push_back(3);
			lst->push_front(8);
			lst->push_front(4);
			lst->pop_front();
			lst->pop_back();
			Assert::IsTrue(lst->at(0) == 8);
			Assert::IsTrue(lst->at(3) == 9);
		}

		TEST_METHOD(insert_1)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			lst->insert(666, 3);
			Assert::IsTrue(lst->at(3) == 666);
		}

		TEST_METHOD(insert_2)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			lst->insert(777, 0);
			Assert::IsTrue(lst->at(0) == 777);
		}

		TEST_METHOD(insert_3)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			lst->insert(666, 5);
			Assert::IsTrue(lst->at(5) == 666);
		}

		TEST_METHOD(insertlist_1)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			LinkedList* list = new LinkedList;
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			lst->insertlist(*list, 2);
			Assert::IsTrue(lst->at(2) == 1 || lst->at(3) == 2 || lst->at(4) == 3);
		}

		TEST_METHOD(insertlist_2)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			LinkedList* list = new LinkedList;
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			lst->insertlist(*list, 0);
			Assert::IsTrue(lst->at(0) == 1 || lst->at(1) == 2 || lst->at(2) == 3);
		}

		TEST_METHOD(insertlist_3)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			LinkedList* list = new LinkedList;
			list->push_back(1);
			list->push_back(2);
			list->push_back(3);
			lst->insertlist(*list, 5);
			Assert::IsTrue(lst->at(5) == 1 || lst->at(6) == 2 || lst->at(7) == 3);
		}
		TEST_METHOD(remove_1)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			lst->remove(0);
			Assert::IsTrue(lst->at(0) == 4);
		}

		TEST_METHOD(remove_2)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			lst->remove(3);
			Assert::IsTrue(lst->at(3) == 2);
		}

		TEST_METHOD(clear)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->clear();
			Assert::IsTrue(lst->get_size() == 0);
		}

		TEST_METHOD(set)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			lst->set(3, 666);
			Assert::IsTrue(lst->at(3) == 666);
		}

		TEST_METHOD(isEmpty)
		{
			LinkedList* lst = new LinkedList;
			lst->push_back(0);
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_front(4);
			lst->push_front(5);
			Assert::IsTrue(!lst->isEmpty());
		}
	};
}
