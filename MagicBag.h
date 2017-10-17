/*


This project is ment to demeonstrate object oriented programming in C++
A template class for a magic bag was created and it can hold unlimited items and draw items at random
*/
#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>  
#include <time.h> 

using namespace std;

template <class T> class MagicBag
{
public:
	class Node
	{
	public:
		Node *next;
		T payload;
		Node()
		{

			payload = NULL;
			next = nullptr;
		}
		~Node()
		{

		}
	};

	MagicBag()
	{
		head = nullptr;
		// seeds random number generator
		srand((unsigned int)time(NULL));
	}

	MagicBag(const MagicBag& other) {
		Node *tmp;
		if (other.head)
		{
			tmp = other.head;
			while (tmp)
			{
				insert(tmp->payload);
				tmp = tmp->next;
			}
		}
	}
	/*
	equals operator
	used to make a copy of a magic bag and the copy is independent from the one copied 
	*/
	MagicBag& operator=(const MagicBag& other) {
		Node *kill;
		Node *tmp;
		// deletes contens of list if there is any
		// added due to mb3=mb2=mb1 whould add the contents of mb1 to mb2 and add all of the contents of mb2 to mb3
		if (head)
		{
			kill = head;
			tmp = kill->next;
			delete kill;
			while (tmp)
			{
				kill = tmp;
				tmp = tmp->next;
				delete kill;
			}
		}

		if (other.head)
		{
			tmp = other.head;
			while (tmp)
			{
				insert(tmp->payload);
				tmp = tmp->next;
			}
		}
		return *this;
	}
	/*
	deletes the linked list created on the heap to prevent memory leaks
	*/
	~MagicBag() {
		Node *kill;
		Node *tmp;
		if (head)
		{
			kill = head;
			tmp = kill->next;
			delete kill;
			while (tmp)
			{
				kill = tmp;
				tmp = tmp->next;
				delete kill;
			}
		}
	}


	/**
	adds the passed in item on the end of list
	working
	*/
	void insert(T item)
	{
		Node*add;
		Node *tmp;
		add = new Node;
		add->payload = item;
		// puts the head pointer to a node if head is null
		if (!head)
		{
			head = add;


		}
		else
		{

			tmp = head;
			// iterates over the list and adds node to the end
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = add;
		}

	}
	/*
	draws a random element from the list and removes that item from the list.
	works
	*/
	T draw() {
		int total;
		Node *tmp;
		if (!head)
		{
			//throws exception if list is empty
			throw;
		}
		tmp = head;
		total = 1;
		// finds number of elements in the list
		while (tmp->next)
		{
			tmp = tmp->next;
			total++;

		}
		int remove;
		
		// number between 1 and total
		remove = rand() % total + 1;
		// resets tmp to the start at the list
		tmp = head;
		Node *kill;
		int find = 1;
		//if the random number is one then it removes the head and returns the data;
		if (remove == 1)
		{
			T info = head->payload;
			head = tmp->next;
			delete tmp;
			return info;
		}
		// finds the proceding node
		find++;
		while (tmp->next)
		{
			if (remove = find)
			{
				kill = tmp->next;
				T info = kill->payload;
				tmp->next = kill->next;
				delete kill;
				return info;
			}
			tmp = tmp->next;
			find++;

		}

	}

	/*
	returns the number of elements that are the same as the perameter
	working
	*/
	int peek(T item)
	{
		Node *tmp;
		// sets counter to zero
		int count = 0;
		if (!head)
		{
			// return zero for empty list
			return 0;
		}
		else
		{
			// checks to see if the first element matches
			tmp = head;
			if (tmp->payload == item)
			{
				count++;
			}
			while (tmp->next)
			{
				tmp = tmp->next;
				if (tmp->payload == item)
				{
					count++;
				}
			}
		}
		return count;
	}

	/*
	outputs the contents of the list
	*/
	void print(ostream&os)
	{
		os << "The contents of this bag are: ";
		Node * tmp;
		
		if (head)
		{
			tmp = head;
			while (tmp)
			{
				os << tmp->payload << " ";
				tmp = tmp->next;
			}
		}
		os << endl;
	}

private:
	Node *head;


};






