// Filename: TrainDemo.cpp
// Date Created: 30/08/2011
// Author: Lance Baker
// Course: SENG1120
// Student Number: c3128034

#include <iostream>
#include <cstdlib>
#include "Node.h"
#include "LinkedList.h"
#include "Train.h"

using namespace std;
using lance_project::Train;

void demonstration() {
	// The two arrays containing the train carriage load data. The -1 terminates the array.
	int arr1[] = {1500, 3200, 4500, 1000, 0, 2000, 0, 2300, -1};
	int arr2[] = {300, 5000, 450, 0, 0, 2900, -1};
	
	// Instantiates both Trains used throughout the demonstration.
	Train train1 = Train(arr1);
	Train train2 = Train(arr2);
	
	// Displays the contents of each Train.
	cout << endl << "#1) Two Train value_types: " << endl;
	cout << "Train1 = " << train1 << endl;
	cout << "Train2 = " << train2 << endl;
	
	// Demonstrates the use of the size method, which just returns an int value
	// based on the amount of carriages stored.
	cout << endl << "#2) Number of carriages: " << endl;
	cout << "Train1 = " << train1.size() << endl;
	cout << "Train2 = " << train2.size() << endl;
	
	// The totalLoad method is used to calculate the total load of all the carriages.
	cout << endl << "#3) Total Load: " << endl;
	cout << "Train1 = " << train1.totalLoad() << endl;
	cout << "Train2 = " << train2.totalLoad() << endl;
	
	// The countEmpty method counts the amount of empty carriages (having 0).
	cout << endl << "#4) Empty carriages in Train 1: " << endl;
	cout << "Train1 = " << train1.countEmpty() << endl;
	
	// In order to add a new carriage, you just use the corresponding method relating
	// to the list. Then therefore you can use the methods in the list to add a carriage
	// to either the first spot, middle, or last position.
	cout << endl << "#5) Add a new carriage to Train 2: " << endl;
	// addLast places the carriage at the end. 
	// addFirst places the carriage at the start.
	train2.getList()->addLast(4000);
	cout << "Train2 = " << train2 << endl;
	
	// The addLoad method is used add more contents to a carriage based on the index position.
	cout << endl << "#6) Add 1500 to the 5th carriage of Train 1: " << endl;
	train1.addLoad(1500, 5);
	cout << "Train1 = " << train1 << endl;
	
	cout << endl << "#7) Append the carriages of (new copy) Train 2 to Train 1: " << endl;
	// The following is done on a new instance.
	Train newTrain1 = Train(arr1);
	Train newTrain2 = Train(arr2);
	// The appending += is using an overloaded operator which will append the carriages together.
	// In this example train2 is appended to train1.
	newTrain1 += newTrain2;
	cout << "New Train1 = " << newTrain1 << endl;
	
	cout << endl << "#8) Add 550 kilograms of coal to the 3rd carriage of Train 2: " << endl;
	train2.addLoad(550, 3);
	cout << "Train1 = " << train1 << endl;
	cout << "Train2 = " << train2 << endl;
	
	// The following demonstrates the ability to perform a deep copy of the train data through
	// the use of the overloaded assignment operator. 
	cout << endl << "#9. Swap the contents of train 1 and train 2, display them: " << endl;
	Train temp = Train();
	temp = train2;
	train2 = train1;
	train1 = temp;
	cout << "Train1 = " << train1 << endl;
	cout << "Train2 = " << train2 << endl;
}

int main() {
	demonstration();
	return 0;
}
