// Filename: LinkedList.cpp
// Date Created: 28/08/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"

using namespace std;
using lance_project::Node;
using lance_project::LinkedList;

namespace lance_project {

	// The default constructor just creates
	// a instance with the residing fields pointing
	// to NULL references.
	LinkedList::LinkedList() {
		this->head_ptr = NULL;
		this->tail_ptr = NULL;
	}
	
	// The destructor clears the List, then
	// deletes the head and tail pointers.
	LinkedList::~LinkedList() {
		this->clear();
		delete this->head_ptr;
		delete this->tail_ptr;
	}

	// The addLast method receives a value corresponding
	// to the value_type defined in the Node class.
	// It is used to add a element to the last position in
	// the list. The node is firstly instantiated with the 
	// value received from the parameter. If the head pointer
	// contains a NULL reference the node is then added to
	// the head and tail references. Otherwise, the list has
	// content therefore it is added to the tail pointer. It sets
	// the tail to contain a link to the node, the tail pointer is
	// then updated with a reference to the newly added node.
	void LinkedList::addLast(Node::value_type value) {
		// Instantiates a new Node containing the received data.
		Node* node = new Node(value);
		// If the head pointer is null, the list is empty.
		if (this->head_ptr == NULL) {
			// Therefore update the head & tail pointer to
			// contain a reference to the newly created Node.
			this->head_ptr = node;
			this->tail_ptr = node;
		} else {
			// Otherwise, the list has content. So set the link on
			// the tail to point to the new node.
			this->tail_ptr->setLink(node);
			//  Then update the tail pointer to point to the new tail node.
			this->tail_ptr = node;
		}
	}
	
	// The addFirst method receives a value, and then instantiates a new Node wrapping
	// that value. It then checks to see whether the head pointer is null; if the head is
	// null then it means the list is actually empty. So therefore it adds the node
	// to the head & tail pointer. Otherwise, the list has content so it then sets the newly
	// created node link to the head pointer. It then changes the head pointer to the new node. Thus
	// wacking the node ontop of the list.
	void LinkedList::addFirst(Node::value_type value) {
		// Creates a new Node containing the received value.
		Node* node = new Node(value);
		// If the list is empty.
		if (this->head_ptr == NULL) {
			// It sets the head & tail pointer to the new node.
			this->head_ptr = node;
			this->tail_ptr = node;
		} else {
			// Otherwise, it sets the new node's link to the
			// head pointer.
			node->setLink(this->head_ptr);
			// It then changes the head pointer to the node.
			this->head_ptr = node;
		}
	}

	// The insert method is used to add a received value (corresponding to the 
	// Node value_type) to the list after a given node. If the 'prev_node' is
	// NULL it therefore uses the addFirst method to wack the value to the top of
	// the list. If the 'prev_node' is equal to the tail, then it will use the 
	// addLast method to append the value to the end. Otherwise, if the 'prev_node'
	// is a node other than the tail, it will instantiate a new Node containing
	// the received value. It then sets the link to the new instance to the previous
	// node's link. It then sets the prev_node's link to the new node. Therefore 
	// inserting it inbetween.
	void LinkedList::insert(Node* prev_node, Node::value_type value) {
		// If the prev_node is NULL
		if (prev_node == NULL) {
			// It will then use the addFirst method.
			this->addFirst(value);
		// If the prev_node is the tail.
		} else if (prev_node == this->tail_ptr) {
			// It will then use the addLast method.
			this->addLast(value);
		} else {
			// Otherwise, it will create a new Node wrapping the value.
			Node* node = new Node(value);
			// It will then set the link of the new Node to the link of
			// the prev_node.
			node->setLink(prev_node->link());
			// It will then set the link of the prev_node to the new Node.
			prev_node->setLink(node);
		}
	}
	
	// The removeHead() method is used to chop the head off the list. It first
	// checks to ensure the head pointer is not NULL; then it assigns a temp pointer
	// with the head pointer, and replaces the head pointer with it's link. It deletes
	// the temp pointer to free the heap.
	void LinkedList::removeHead() {
		if (this->head_ptr != NULL) { // Ensures it has a Node.
			// Assigns the head pointer to a temp.
			Node* temp_ptr = this->head_ptr;
			// Replaces the head pointer with the link pointer.
			this->head_ptr = this->head_ptr->link();
			delete temp_ptr;
		}
	}
	
	// The remove method is used to delete a node from the List. 
	// Since the nodes themselves don't have access to the previous
	// link, it must be received in order to remove the next node.
	void LinkedList::remove(Node* prev_node) {
		if (prev_node != NULL) { // Ensures a valid pointer is received.
			// The node that you desire to remove.
			Node* temp_ptr = prev_node->link(); 
			// The node is removed by setting the link of the previous one
			// with the link of the node that you wish to remove. Therefore,
			// it chops it out of the chain.
			prev_node->setLink(temp_ptr->link());
			// Frees the memory.
			delete temp_ptr; 
			delete prev_node;
		}
	}
	
	// The clear() method removes all elements from the LinkedList.
	// It iterates throughout the List chopping the head off each time (via the 
	// removeHead() method) until the head pointer is NULL.
	void LinkedList::clear() {
		// Iterates until the head pointer is NULL.
		while (this->head_ptr != NULL) {
			this->removeHead(); // Chops the head off.
		}
	}
	
	// The copy method is used to perform a deep copy of a LinkedList. It
	// first ensures that the received pointer is not NULL, otherwise it ceases to
	// continue. The current instance is then cleared using the clear() method.
	// The received 'source_ptr' is generally the head pointer of the desired list,
	// but also can be any pointer within the list that you wish to copy from. The list
	// is then iterated from the starting pointer, and then with each iteration it copies
	// the Node data to the current instance using the addLast method.
	void LinkedList::copy(Node* source_ptr) {
		if (source_ptr != NULL) { // Ensures the received pointer is not NULL.
			this->clear(); // Clears the current list.
			// Iterates foreach Node.
			for (; source_ptr != NULL; source_ptr = source_ptr->link()) {
				// Copies the Node data to the current list using the addLast method.
				this->addLast(source_ptr->data());
			}
		}
	}

	// The search method receives a target value that you wish to find the relating node
	// for. It iterates foreach node in the list until a matching node (against the data)
	// is found. It then returns either the found node, or a NULL reference if there weren't
	// any matches.
	Node* LinkedList::search(Node::value_type target) {
		// Iterates foreach Node.
		for (Node* current = this->head_ptr; current != NULL; 
									current = current->link()) {
			// If the target value matches the Node data.
			if (target == current->data()) {
				// It returns the found Node.
				return current;
			}
		}
		return NULL; // Otherwise no matches were found.
	}
	
	// The getNode method is used to fetch the Node in the list relating
	// to the position parameter received. It iterates foreach Node, whilst
	// also incrementing a counter with each iteration. It then compares the counter
	// with the position, and returns the Node if there is a match. Otherwise it returns null.
	Node* LinkedList::getNode(int position) {
		int count = 1; // The counter value.
		// Iterates foreach Node. Also increments the counter.
		for (Node* current = this->head_ptr; current != NULL; 
						current = current->link(), count++) {
			// Checks if the counter equals the position.
			if (count == position) {
				return current; // Returns the Node relating to the position.
			}
		}
		return NULL; // Otherwise returns NULL.
	}
	
	// The getHead() method is used as a getter to retrieve the head pointer.
	Node* LinkedList::getHead() {
		return this->head_ptr;
	}

	// The size() method is used to iterate throughout the Nodes in the list
	// whilst iterating a value counting the amount of Nodes. It returns the 
	// total size of the LinkedList.
	int LinkedList::size() {
		int size = 0;
		// Iterates foreach Node counting the size.
		for (const Node* current = this->head_ptr; current != NULL; current = current->link(), size++);
		return size; // Returns the size.
	}
}
