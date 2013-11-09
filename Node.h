// Filename: Node.h
// Date Created: 28/08/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#ifndef LANCE_NODE_H
#define LANCE_NODE_H
namespace lance_project {
	class Node {
		public:
			// A public datatype defined in order to make the LinkedList
			// have more reusability. Allowing the alteration of the datatype
			// to be centralised.
			typedef int value_type;
			
			// Postconditions: The default constructor creates a empty instance.
			Node();
			
			// Postconditions: The constructor creates a instance with data.
			Node(const value_type& data_field);
			
			// Postconditions: The constructor creates a instance with data and a Node link.
			Node(const value_type& data_field, Node* link_field);
			
			// Postconditions: The destructor ensures that the memory is freed.
			~Node();
			
			// Postconditions: The setter for the data.
			void setData(const value_type& data_field);
			
			// Postconditions: The setter for the next linked Node.
			void setLink(Node* link_field);
			
			// Postconditions: The getter for the data.
			value_type data() const;
			
			// Postconditions: The getter for the next linked Node.
			const Node* link() const;
			
			// Postconditions: The getter for the next linked Node.
			Node* link();
		private:
			value_type data_field; // Instance field containing the data.
			Node* link_field; // Pointer to the next Node.
	};
}
#endif
