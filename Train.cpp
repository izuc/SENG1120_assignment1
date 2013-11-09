// Filename: Train.cpp
// Date Created: 29/08/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"
#include "Train.h"

using namespace std;
using lance_project::Node;
using lance_project::LinkedList;
using lance_project::Train;

namespace lance_project {

	// The default constructor creates the containing
	// LinkedList data structure used for storing the residing
	// carriage load data.
	Train::Train() {
		this->list = new LinkedList();
	}
	
	// The constructor accepts a integer array which contains the load
	// data for each carriage (being defined in each element). It must
	// have a last element identifying the end of the array containing -1.
	// This is due to the known limitation of C++ of not being able to 
	// correctly work out the size of an array after it has been passed
	// through a function call.
	Train::Train(int arr[]) {
		// Instantiates a new LinkedList.
		this->list = new LinkedList();
		bool hasMore = true; // Used to exit the loop.
		// Iterates whilst it hasMore elements. It uses 'i' to
		// identify the indice.
		for (int i = 0; hasMore; i++ ) {
			// If the element is not at the end of the array.
			if (arr[i] != -1) {
				// Adds the array element to the LinkedList (last position).
				list->addLast(arr[i]);
			} else {
				// End of the array.
				hasMore = false;
			}
		}
	}

	// The size method is used to fetch the length of the Train. It returns
	// the amount of carriages.
	int Train::size() {
		// Uses the size method of the residing LinkedList.
		return this->list->size();
	}
	
	// The totalLoad method is used to calculate the total amount of load in 
	// the Train. It iterates throughout each node element in the list adding
	// the value to the total. It returns the final calculated value.
	int Train::totalLoad() {
		int total = 0; // Stores the total.
		// Iterates foreach node in the list.
		for (const Node* current = this->list->getHead(); current != NULL; 
									current = current->link()) {
			// Adds the node data to the total.
			total += current->data();
		}
		return total; // Returns the total value.
	}
	
	// The countEmpty method is used to count the amount of carriages in the
	// Train with a empty load. It iterates throughout each node element
	// incrementing a counter value when a zero value has been spotted.
	// It returns the count of empty carriages.
	int Train::countEmpty() {
		int i = 0; // A counter used for the empty carriages.
		// Iterates foreach node in the list.
		for (const Node* current = this->list->getHead(); current != NULL; 
									current = current->link()) {
			// The carriage has no load.
			if (current->data()	== 0) {
				i++; // Increment counter.
			}
		}
		return i; // Returns the counter value.
	}
	
	// The addLoad method accepts a 'i' value for the load amount, and also a 'j'
	// value which represents the carriage number in the Train. It is used
	// to add the amount of i to the carriage of j.
	void Train::addLoad(int i, int j) {
		// Fetches the node from the structure.
		Node* node = this->list->getNode(j);
		// Adds the load to the existing amount.
		node->setData(node->data() + i);
	}
	
	// The removeLoad method accepts an 'i' value representing the amount
	// that you wish to remove from the carriage of 'j' identified by the
	// number corresponding to it's position.
	void Train::removeLoad(int i, int j) {
		// Fetches the node from the list.
		Node* node = this->list->getNode(j);
		// Subtracts the load from the existing amount.
		node->setData(node->data() - i);
	}
	
	// The getList() method is a getter that retrieves a pointer
	// to the LinkedList data structure that stores the carriage values.
	LinkedList* Train::getList() {
		return this->list;
	}
	
	// The += operator is used to append the contents of the right hand side
	// train to the left. It is used for example in a statement like train1 += train2.
	// It enables for the Train carriages to be simply appended together.
	Train Train::operator+=(Train & rhs) {
		// Iterates foreach node in the (right hand side) Train.
		for (const Node* current = rhs.getList()->getHead(); current != NULL; 
									current = current->link()) {
			// Adds the node data to the Last position of the LinkedList.
			this->list->addLast(current->data());				
		}
		// Returns the pointer to the current Train instance.
		return *this;
	}
	
	// The = operator is used to perform a deep copy of the Train contained
	// on the right hand side of the statement to the current instance. It 
	// copies the residing primitive element values to a new Node instance
	// so therefore it doesn't just simply copy the pointers. 
	Train Train::operator=(Train & rhs) {
		// Invokes the copy method corresponding to the internal list. It
		// passes the head Node of the train enabling for the list to be
		// traversed.
		this->list->copy(rhs.getList()->getHead());
		// Returns the pointer to the current Train instance.
		return *this;
	}
	
	// The << operator is used to output the contents of each carriage
	// in the Train. It iterates throughout each Node in the LinkedList,
	// whilst appending the output and separating each element with a divider.
	ostream & operator<<(ostream & out, Train & value) {
		// Iterates foreach Node in the received Train.
		for (const Node* current = value.getList()->getHead(); current != NULL; 
									current = current->link()) {
			// Appends the data, separating each element with a divider.
			out << current->data() << OUTPUT_DIVIDER;
		}
		return out; // Returns the output stream.
	}
};
