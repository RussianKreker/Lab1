#include <stdexcept>
#include "iostream"
#include "LinkedList.h"

using namespace std;

void LinkedList::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

LinkedList::LinkedList()
{
	reset_list();
	size = 0;
}

LinkedList::~LinkedList()
{
	if (!isEmpty())//if the list is already empty, nothing happens
	{
		clear();
	}
}

void LinkedList::add_first(int newElem)
{
	head = new Node(newElem);
	tail = head;
}

void LinkedList::push_back(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		tail->next = new Node(newElem, nullptr);
		tail = tail->next;
	}
	size++;
}

void LinkedList::push_front(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head = new Node(newElem, head);
	}
	size++;
}

void LinkedList::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

void LinkedList::pop_front()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Node* current = head->next;
		delete head;
		head = current;
	}
	size--;
}

void LinkedList::insert(int newElem, size_t index)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	else if (index == 0) {
		push_front(newElem);
	}
	else {
		Node* current = head;
		Node* previous = head;
		size_t counter = 0;
		while (counter != index - 1) {
			current = current->next;
			counter++;
			if (counter > 0)
			{
				previous = previous->next;
			}
		}
		current->next = new Node(newElem, current->next);
		/*current = current->next;
		current->next->prev = current;
		current->prev->next = current;*/
		size++;
	}
}

int LinkedList::at(size_t index)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	else {
		Node* current = head;
		size_t counter = 0;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}

void LinkedList::remove(size_t index)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	else if (index == 0) {
		pop_front();
	}
	else if (index == size - 1) {
		pop_back();
	}
	else {
		Node* current = head;
		Node* previous = head;
		size_t counter = 0;
		while (counter != index) {
			current = current->next;
			if (counter > 0)
			{
				previous = previous->next;
			}
			counter++;
		}
		/*current->prev->next = current->next;
		current->next->prev = current->prev;*/
		previous->next = current->next;
		delete current;
		size--;
	}
}

size_t LinkedList::get_size()
{
	return size;
}

void LinkedList::print_to_console()
{
	if (!isEmpty())
	{
		Node* current = head;
		while (current->next != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << current->data << " ";
	}
}

void LinkedList::clear()
{
	Node* current = head->next;
	while (current->next != nullptr) {
		delete head;
		head = current;
		current = head->next;
	}
	delete head;
	delete tail;
	size = 0;
}

void LinkedList::set(size_t index, int newElem)
{
	if (index >= size) {
		throw out_of_range("out of range");
	}
	Node* current = head;
	size_t counter = 0;
	while (counter != index) {
		current = current->next;
		counter++;
	}
	current->data = newElem;
}

bool LinkedList::isEmpty() // if empty - true, else false
{
	return !size;
}

void LinkedList::insertlist(LinkedList& SecList, size_t index)//I didn't write a copy constructor, so I pass the list like this
{
	Node* curr = SecList.head;
	while (curr->next != nullptr) {
		insert(curr->data, index);
		index++;
		curr = curr->next;
	}
	insert(curr->data, index);
}


