#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename Type>
struct Node
{
	Type data;
	Node* next;

	Node(Type data)
	{
		this->data = data;
		this->next = nullptr;
	}
	Node()
	{
		this->data = NULL;
		this->next = nullptr;
	}
};
template <typename Type>
class List
{
public:
	Node<Type>* head;

	List()
	{
		this->head = nullptr;
	}

	List(Node<Type>* headNode, Type value)
	{
		Node<Type>* headNode = new Node(value);
		this->head = headNode;
	}
	Type read(int index)
	{
		int position = 0;
		Node<Type>* current = this->head;
		while (position < index);
		{
			current = current->next;
			position++;
		}
		return current->data;
	}

	int search(Type value)
	{
		Node<Type>* current = this->head;
		int index = 0;
		while (current != nullptr)
		{
			if (current->data == value)
				return index;
			index++;
			current = current->next;
		}
		return -1;
	}

	Node<Type>* locate(Type value)
	{
		Node<Type>* current = this->head;
		while (current != nullptr)
		{
			if (current->data == value)
				return current;
			current = current->next;
		}
		return nullptr;
	}
	
	void insert(Type value, int index)
	{
		int position = 0;
		Node<Type>* current = this->head;

		//Move curent to node one before insertion point
		while (position < index - 1)
		{
			current = current->next;
			position++;
		}

		//Create node
		Node<Type>* newNode = new Node<Type>(value);
		//Insert at head
		if (index == 0)
		{
			newNode->next = this->head;
			this->head = newNode;
		}
		//Insert anywhere else
		else
		{
			newNode->next = current->next;
			current->next = newNode;
		}
	}

	void insert(Type value, Node<Type>* location)
	{
		//insert at head
		if (location == this->head)
		{
			Node<Type>* newNode = new Node<Type>(value);
			newNode->next = this->head;
			this->head = newNode;
			return;
		}

		//Create new node with old value
		Node<Type>* newNode = new Node<Type>(location->data);
		
		//Point new node to old node's next
		newNode->next = location->next;

		//Point old node and switch value to new one
		location->data = value;
		location->next = newNode;
	}

	void display()
	{
		Node<Type>* current = this->head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}

	void remove(int index)
	{
		//Remove head node
		if (index == 0)
		{
			Node<Type>* tbd = this->head;
			this->head = this->head->next;
			delete tbd;
			return;
		}
		int position = 0;
		Node<Type>* current = this->head;

		//Move current to node one before inserion point
		while (position < index - 1)
		{
			current = current->next;
			position++;
		}

		//remember location before deletion
		Node<Type>* toBeDeleted = current->next;

		//Point node one position before deleted node's next
		current->next = current->next->next;

		//Delete the node
		delete toBeDeleted;
	}

	void remove(Node<Type>* location)
	{
		//Remove First Node
		if (location == this->head)
		{
			this->head = location->next;
			delete location;
			return;
		}

		//Swap values with next value
		location->data = location->next->data;

		//Remember the location of the node to be deleted
		Node<Type>* tbd = location->next;

		//Point location to next node's next
		location->next = location->next->next;

		//Delete old node
		delete tbd;
	}
};
