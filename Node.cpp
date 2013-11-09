// Filename: Node.cpp
// Date Created: 28/08/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include "Node.h"
#include <cstdlib>
using namespace std;
using lance_project::Node;

namespace lance_project {

	// The default constructor to the Node. 
	// It creates a instance without any data.
	Node::Node() {
	
	}
	
	// The constructor for the Node receives the data
	// as a parameter, setting the data instance field with the 
	// received value.
	Node::Node(const Node::value_type& data_field) {
		this->data_field = data_field;
	}

	// The constructor receives the data value, and also the Node
	// that it will be linked to. It sets both instance fields with
	// the received parameters.
	Node::Node(const Node::value_type& data_field, Node* link_field) {
		this->data_field = data_field;
		this->link_field = link_field;
	}
	
	// The destructor sets the instance fields with a NULL reference.
	Node::~Node() {
		this->link_field = NULL;
	}

	// The setData method receives the data as a parameter,
	// setting the instance field with the value received.
	void Node::setData(const Node::value_type& data_field) {
		this->data_field = data_field;
	}

	// The setLink method is a setter for the next Node linkage.
	void Node::setLink(Node* link_field) {
		this->link_field = link_field;
	}

	// Getter for the data.
	Node::value_type Node::data() const {
		return this->data_field;
	}

	// Constant Getter for the Node Link.
	const Node* Node::link() const {
		return this->link_field;
	}

	// Getter for the Node Link.
	Node* Node::link() {
		return this->link_field;
	}
}
