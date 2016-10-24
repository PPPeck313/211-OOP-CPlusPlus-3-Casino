#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int size;//does not correlate to index, counts elements

	T getHead();
	T getTail();

	void insertAtHead(T data);
	void insertAtTail(T data);

	void removeAtHead();
	void removeAtTail();

	bool isEmpty();
public:
	LinkedList();
	LinkedList(LinkedList& other);

	T getAtIndex(int index);
	void insertAtIndex(T data, int index);
	void removeAtIndex(int index);
	void remove(T data);

	bool contains(T c);
	T search(T c);

	void sort();

	int getSize();
	void setSize(int s);

	T& operator[](int index);

	void display();
	friend ostream& operator<<(ostream& out, LinkedList& ll);

	void operator=(const LinkedList& otherList);
	~LinkedList();
};

template <class T>
T LinkedList<T>::getHead() {//head is new*
	if (isEmpty()) {
		cout<<"List is empty!"<<endl;
		return NULL;
	}
	return head->getData();
}

template <class T>
T LinkedList<T>::getTail() {//tail is Node*
	if (isEmpty()) {
		cout<<"List is empty!"<<endl;
		return NULL;
	}
	return tail->getData();
}


template <class T>
void LinkedList<T>::insertAtHead(T data) {
	if (isEmpty()) {
		head = new Node<T>(data);
		tail = head;
		size++;
	}
	else {
		Node<T>* temp = head;
		head = (new Node<T>(data, temp));
		size++;
	}
}

template <class T>
void LinkedList<T>::insertAtTail(T data) {
	if (isEmpty()) {
		tail = new Node<T>(data);
		head = tail;
		size++;
	}
	tail->setNext(new Node<T>(data));
	tail = tail->getNext();//update tail position
	size++;
}


template <class T>
void LinkedList<T>::removeAtHead() {
	if (head != NULL) {
		Node<T>* traveler = head->getNext();
		delete head;
		head = traveler;
		size--;
	}
}

template <class T>
void LinkedList<T>::removeAtTail() {
	if (tail != NULL) {
		Node<T>* traveler = head;
		for (int i = 0; i < size - 1; i++) {
			 traveler = traveler->getNext();
		}
		delete tail;
		tail = traveler;
		size--;
	}
}


template <class T>
bool LinkedList<T>::isEmpty() {
	return size == 0;
}

template <class T>
LinkedList<T>::LinkedList() {
	size = 0;
	head = NULL;
	tail = head;
}

template <class T>
LinkedList<T>::LinkedList(LinkedList& other) {//deep copy
	size = other.size;
	head = new Node<T>(other.head->getData(), other.head->getNext());
	Node<T>* traveler = head;
	Node<T>* travelerOther = other.head;
	for (int i = 0; i < size; i++) {
		traveler->setNext(new Node<T>(travelerOther->getData(), travelerOther->getNext()));
		traveler = traveler->getNext();
		travelerOther = travelerOther->getNext();
	}
	tail = traveler;
}


template <class T>
T LinkedList<T>::getAtIndex(int index) {
	if (index == 0) {
		return getHead();
	}
	else if (index == size - 1) {
		return getTail();
	}
	else if ((index < 0) || (index >= size)) {
		cout<<"Error: Out of range!"<<endl;
		return NULL;
	}
	else {
		Node<T>* traveler = head;
		for (int i = 0; i < index; i++) {
			traveler = traveler->getNext();
		}
		return traveler->getData();
	}
}

template <class T>
void LinkedList<T>::insertAtIndex(T data, int index) {//index correlates to index 1:1
	if (index == 0) {
		insertAtHead(data);
	}
	else if (index == size) {//insert new past size insead of before
		insertAtTail(data);
	}
	else if ((index < 0) || (index > size)) {
		cout<<"Error: Out of range!"<<endl;
	}
	else {
		Node<T>* travelerPrev = head;
		for (int i = 0; i < index - 1; i++) {
			travelerPrev = travelerPrev->getNext();
		}
		Node<T>* traveler = travelerPrev->getNext();//loses previous next when repointed so have to store
		travelerPrev->setNext(new Node<T>(data, traveler));
		size++;
	}
}

template <class T>
void LinkedList<T>::removeAtIndex(int index) {
	if (index == 0) {
		removeAtHead();
	}
	else if (index == size) {
		removeAtTail();
	}
	else if ((index < 0) || (index > size)) {
		cout<<"Error: Out of range!";
	}
	else {
		Node<T>* travelerPrev = head;
		for (int i = 0; i < index - 1; i++) {
			travelerPrev = travelerPrev->getNext();
		}
		Node<T>* travelerNext = travelerPrev->getNext()->getNext();//loses next when deleted so have to store
		delete[] travelerPrev->getNext();//index
		travelerPrev->setNext(travelerNext);
		size--;
	}
}

template <class T>
void LinkedList<T>::remove(T c) {//use search
	for (int i = 0; i < size; i++) {
		if (getAtIndex(i) == c) {
			removeAtIndex(i);//possible to have duplicates?
			size--;
			//return;
		}
	}
}

template <class T>
bool LinkedList<T>::contains(T c) {
	Node<T>* traveler = head;
	for (int i = 0; i < size; i++) {
		if (traveler->getData()) {
			return true;
		}
		traveler->getNext();
	}
	return false;
}

template <class T>
T LinkedList<T>::search(T c) {//LinkedList* create linked list look at size > 0 insert card that match
	Node<T>* traveler = head;
	for (int i = 0; i < size; i++) {
		if (c == traveler->getData()) {
			return traveler->getData();
		}
		traveler->getNext();
	}
	return NULL;
}

template <class T>
void LinkedList<T>::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if ((*(getAtIndex(j))).compareTo(*(getAtIndex(j + 1))) > 0) {
				if (j == 0) {//no nodePrev
					Node<T>* travelerNext = head->getNext();
					head->setNext(travelerNext->getNext());
					travelerNext->setNext(head);
					head = travelerNext;
				}
				else {
					Node<T>* travelerPrev = head;
					for (int k = 0; k < j - 1; k++) {
						travelerPrev = travelerPrev->getNext();
					}
					Node<T>* traveler = travelerPrev->getNext();
					Node<T>* travelerNext = traveler->getNext();
					traveler->setNext(travelerNext->getNext());//NULL if last two because last three stored and tail's next is NULL
					travelerNext->setNext(traveler);
					travelerPrev->setNext(travelerNext);
				}
            }//don't exchange data but instead location in list
        }//is this really the easiest way? Instead be invoking getData() same way as getNext()
    }//getAtIndex doesn't return Node pointer just card
	Node<T>* traveler = head;
	for (int i = 0; i < size - 1; i++) {
		traveler = traveler->getNext();
	}
	tail = traveler;
}

template <class T>
int LinkedList<T>::getSize() {
	return size;
}

template <class T>
void LinkedList<T>::setSize(int s) {
	size = s;
}

template <class T>
T& LinkedList<T>::operator[](int index) {//LinkedList
	T c = getAtIndex(index);
	if (c != NULL) {
		return c;
	}
	exit(1);
}


template <class T>
void LinkedList<T>::display() {
	if (!isEmpty()) {
		for (int i = 0; i < size; i++) {
			cout<<*this[i];
		}
	}
	else {
		cout<<"List is empty!"<<endl;
	}
}

template <class T>
ostream& operator << (ostream& out, LinkedList<T>& ll) {
	if (ll.size > 0) {
		for (int i = 0; i < ll.size; i++) {
			out<<*ll[i]<<endl;
		}
	}
	else {
		out<<"List is empty!"<<endl;
	}
	return out;
}

template <class T>
void LinkedList<T>::operator=(const LinkedList<T>& otherList) {
	size = otherList.size;
	Node<T>* travelerOther = otherList.head;
	for (int i = 0; i < size; i++) {
		insertAtIndex(travelerOther->getData(), i);
		travelerOther = travelerOther->getNext();
	}
}

template <class T>
LinkedList<T>::~LinkedList() {
	for (int i = size - 1; i > 0; i--) {
		removeAtIndex(i);
	}//hand is lost but cards are still part of the deck, don't destroy object
}

#endif