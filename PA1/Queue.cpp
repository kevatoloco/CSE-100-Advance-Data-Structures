#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
	head = NULL;
	tail = NULL;
	numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
	clear();
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
	return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
	Node* current = head;
	while(current != NULL) {
		head = current->next;
		delete(current);
		current = head;
	}
	numElements = 0; 
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
	Node* newNode = new Node(s);
	if(head == NULL) {
		head = newNode;	
	} 
	if(tail != NULL) {
		tail->next = newNode;
	}
	tail = newNode;
	numElements += 1;
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
	string s = head->data;
	Node * nextNode = head->next;
	delete(head);
	head = nextNode;
	numElements -= 1;
	return s;
}
