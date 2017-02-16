// Include your name here.
// Place comments describing the class Chain (two lines).

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_
#include <iostream>
#include <cstddef>
#include <fstream>
#include <string>
#include <sstream>

namespace teaching_project {
/* The class takes advantage of new c++ 11 features, including move, swap, and certain syntax changes from the previous c++ version. Implementing the "big five", we can create objects that have certain powers - if a Chain has a certain length and we decide to move that chain to another object, this is easily done with the move assignment operator (as an example of a use case/ one of the "big five"'s).

A Chain is simply a dynamic array that contains a series of objects, including but not limited to having types like "int", "string", "doubles", among other primitive data types. It is unclear whether we can use user-defined types.

We overload many operations for this class to maintain our abstraction. One such includes the indexing ( [] ) operator that allows the client to retrieve an object (of type Object) from the array_ of the class.
*/


	template<typename Object>
	class Chain {

		public:

		//-----------------------------------------------------------------
		// Default "big five" -- you have to alter them for your assignment.
		// That means that you will remove the "= default" statement.
		//  and you will provide an implementation.

		// Zero-parameter constructor using new c++11 syntax.
		Chain() : size_{0}, array_{NULL}{
		}//end zero-parameter constructor

		// Copy-constructor.
		Chain(const Chain &rhs) {

			//array_ = new Object {*rhs.array_};?
	
			//first create this chain with its correct size : static cast!
			array_ = new Object[static_cast<int>(rhs.size_)];

			//make sure we aso get the size variable
			size_ = rhs.size_;

			//loop through and transfer the data stored from in one to the other
			for (size_t i = 0; i < size_; ++i) {
				array_[i] = rhs.array_[i];
			}
		}//end copy-constructor

		Chain& operator=(const Chain &rhs) {

			//create an object that does a deep copy from rhs to copy
			Chain copy = rhs;
	
			//swap the object we are working with with the copied rhs (aka "copy")
			std::swap(*this, copy);

			//what we are working with (outside this method) will now point 
			//to the swapped array - which went basically 
			// --> rhs --> copy --> swap (with whatever "this" was before).
			// now this has what rhs had 
			return *this;
		}//end =operator

		// Move-constructor.
		Chain(Chain &&rhs) {

			//"steal" rhs's size_
			size_ = rhs.size_;

			//this is like what we can think of as a shallow copy. 
			//"this" array_ now "points" to 
			//what the rhs has to offer
			array_ = rhs.array_;

			//but because the rhs is really just a temporary object 
			//that will soon expire, we can set it to null.
			rhs.array_ = NULL;

			//to ensure that the other Chain's size has been cleared/reset
			rhs.size_ = 0;
		}//end move-constructor

		// Move-assignment.
		// Just use std::swap() for all variables.
		Chain& operator=(Chain &&rhs) {

			//swap the "array_" variable
			std::swap(array_, rhs.array_);

			//swap the "size_" variable
			std::swap(size_, rhs.size_);

			//no need to reset (deallocate memory) as it's not necessary to - will find out in class
			//	rhs.size_ = 0;
			//	rhs.array_ =NULL;

			//return
			return *this;
		}//end move-assignment

		//deallocate the memory pointed to by the array_
		~Chain() {

			//loop through each index of the dynamic array in the heap 
			//so that we may relcaim its memory, using the delete operatorASXdaZ
			delete [] array_;

			//don't forget to set the size to 0.
			size_ = 0;

			//set array to null
			array_ = NULL;
		}//end destructor

//-----------------------------------------------------------------

		// One parameter constructor.
		Chain(const Object& item) {
		
			//size will be 1
			size_ = 1;

			//create a new object space for array to put the item in
			array_ = new Object [1];

			//place item in the array
			array_[0] = item;
		}//end one parameter constructor

//-----------------------------------------------------------------

		// Read a chain from standard input.
		void ReadChain() {
	
			//declaration of variables
			std::string line_from_file = "";
			std::string line_no_punc = "";
			size_t i = 0, t_size;

			//get the line from the file that's open
			//from the "test_chain < test_input_file.txt" command
			std::getline(std::cin, line_from_file);

			//remove any unecessary punctuation
			while (i < (line_from_file.size()-1)) {
				//if we find punctuation that doesn't belong, 
				if ((line_from_file[i] == 58) || (line_from_file[i] == 91) || (line_from_file[i] == 93)) {
					i++;
				}
				else {
					//place in the better line
					line_no_punc += line_from_file[i];
					i++;
				}
			}

			//create a stringstream to manipulate the line_no_punc
			std::stringstream ss(line_no_punc);

			//make sure that the first char from the string is able to be placed in size_
			ss >> t_size;

			//size_ should obtain that value
			size_ = t_size;
		
			//we can place the values remaining in the Object array
			//reinitialize i to 0 for the while loop below
			i =0;
	
			//create the array of the specified size
			array_ = new Object [size_];
	
			//loop through the rest of the stringstream to
			//place each obtained value into the Chain
			while (i < size_) {

				//create the temp object that 
				Object temp;

				//convert to the Object type
				ss >> temp;

				//assign the position in the 
				array_[i] = temp;

				//increment i!!!!
				i++;
			}
		}//end readchain

		//returns the size of the Chain to outside non-member functions/clients
		size_t size() const {

			//return
			return size_;
		}//end size

		// @location: an index to a location in the chain.
		// @returns the Object at @location.
		// const version.
		// abort() if out-of-range.
		const Object& operator[](size_t location) const {

			//declare a size_t variable
			size_t zero = 0;

			//check to see if the location is within bounds of the array
			if ((zero <= location) && (location < size_)) {

				//return the Object that exists at that location
				return array_[location];
			}
			//our "return" that is actually an "abort()"
			else abort();
		}//end []operator

		// @location: an index to a location in the range.
		// @returns the Object at @location.
		// non-const version.
		// abort() if out-of-range.
		Object& operator[](size_t location) {

			//declare a size_t variable
			size_t zero = 0;		
	
			//check to see if the location is within bounds of the array
			if ((zero <= location) && (location < size_)) {
	
				//return the Object that exists at that location
				return array_[location];
			}
			//our "return" that is actually an "abort()"
			else abort();
		}//end []operator

		//  @c1: A chain.
		//  @c2: A second chain.
		//  @return the concatenation of the two chains.
		friend Chain operator+(const Chain &c1, const Chain &c2) {

			//create the return object
			Chain return_chain;
	
			//first get the new size by obtaining the sizes from the two objects
			//also so that we can use if as part of the loop
			return_chain.size_ = ((c1.size_) +(c2.size_));
	
			//allocate memory
			return_chain.array_ = new Object[return_chain.size_];
	
			//keep track of the position of the return chain
			size_t i = 0;

			//place data into the new return chain from the first object
			for (size_t j = 0; j < c1.size_; j++) {
				return_chain.array_[i] = c1.array_[j];
				i++;
			}

			//place data into the new return chain from the second object
			for (size_t k = 0; k < c2.size_; k++) {
				return_chain.array_[i] = c2.array_[k];
				i++;
			}
	
			//return
			return return_chain;
		}//end +operator


		//  @c1: A chain.
		//  @c2: An "Object" object.
		//  @return the concatenation of the two objects given.
		friend Chain operator+(const Chain &c1, const Object &c2) {

			//create the return object
			Chain return_chain;

			//first get the new size by obtaining the sizes from the two objects
			//also so that we can use if as part of the loop
			return_chain.size_ = ((c1.size_) +1 );
	
			//allocate memory
			return_chain.array_ = new Object[return_chain.size_];
	
			//keep track of the position of the return chain
			size_t i = 0;
	
			//place data into the new return chain from the first object
			for (size_t j = 0; j < c1.size_; j++) {
				return_chain.array_[i] = c1.array_[j];
				i++;
			}
	
			//place data into the new return chain from the second object
			return_chain.array_[i] = c2;
		
			//return
			return return_chain;
		}//end +operator

		// Overloading the << operator.
		friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
	
			//for style		
			out << "[ ";
	
			//loop and output the contents from within the array.
			for (size_t i = 0; i < a_chain.size(); i++) {
				out << a_chain.array_[i] << " ";
			}

			//for style
			out << "]";

			//return
			return out;
		}//end &operator

		private:
	
		size_t size_;
		Object *array_;

	};//Chain class
}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
