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
// Place comments that provide a brief explanation of the class,
// and its sample usage.

template<typename Object>
class Chain {

	public:
	
	//-----------------------------------------------------------------
	// Default "big five" -- you have to alter them for your assignment.
	// That means that you will remove the "= default" statement.
	//  and you will provide an implementation.

	// Zero-parameter constructor using new c++11 syntax.
	Chain() : size_{0}, array_{NULL}{
	}

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
	}

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
	}

	// Move-constructor.
	Chain(Chain &&rhs) {

		size_ = rhs.size_;

		//this is like what we can think of as a shallow copy. 
		//"this" array_ now "points" to 
		//what the rhs has to offer
		array_ = rhs.array_;

		//but because the rhs is really just a temporary object 
		//that will soon expire, we can set it to null.
		rhs.array_ = NULL;

		//to ensure that the other Chain's size has been cleared
		rhs.size_ = 0;

	}

	// Move-assignment.
	// Just use std::swap() for all variables.
	Chain& operator=(Chain &&rhs) {

		//swap the "array_" variable
		std::swap(array_, rhs.array_);

		//swap the "size_" variable
		std::swap(size_, rhs.size_);

	//do not need to reset (deallocate memory) as it's not necessary to - will find out in class
	//	rhs.size_ = 0;
	//	rhs.array_ =NULL;

		//return
		return *this;
	}

	//deallocate the memory pointed to by the array_
	~Chain() {

		//loop through each index of the dynamic array in the heap 
		//so that we may relcaim its memory, using the delete operator
		//at first I tried to "loop through" the elements of the array so 
		//that each element would be deleted from the array (using the size_
		//as a stopping point) but this lead to memory issues (looks like I
		//was "deleting" un authorized memory locations...
		delete [] array_;
		
		//don't forget to set the size to 0.
		size_ = 0;

		//set array to null
		array_ = NULL;
	}

	// End of big-five.
	//-----------------------------------------------------------------

	// One parameter constructor.
	Chain(const Object& item) {
		
		//size will be 1
		size_ = 1;

		//create a new object space for array to put the item in
		array_ = new Object [1];

		//place item in the array
		array_[0] = item;


	}

	//-----------------------------------------------------------------




	// Read a chain from standard input.
	void ReadChain() {
	
		//declaration of variables
		std::string line_from_file = "";
		std::string line_no_punc = "";

		size_t i = 0, t_size;

		//get the line from the file that's open
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
		
		//great now that the size is taken care of, we can place the values remaining in the Object array
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


		/*
		std::string size_as_a_string;
		std::string final_line = "";
			the following code gave me trouble. scrapped and tried again differently
		//obtain and set size using size_as_a_string and stringstream
		size_as_a_string = line_no_punc[0];
		//open the new stringstream
		std::stringstream theStream(size_as_a_string);
		//do some magic, turn size_as_a_string into size_as_a_size_t
		theStream >> size_as_a_size_t;
		size_ = size_as_a_size_t;
		std::cout << "size_: " << size_ << std::endl;
		i =2;
		//remove that number by skipping the first {{0th}} index and placing
		//the remaining characters into the final string for stringstream use
		std::cout << "line_no_punc.size(): " << line_no_punc.size() << std::endl;
		while (i < (line_no_punc.size())) {
			final_line += line_no_punc[i];
			i++;
		}
		std::cout << "final_line size: " << final_line.size() << std::endl;
		std::cout << "The line prepared for stringstream: " << final_line << std::endl;
		//put the final_line into the stringstream for manipulation
		//theStream(final_line);
		*/

		//cast as type Object

		//place in our objecy array_

		//for loop to output

}

	//returns the size of the Chain to outside non-member functions/clients
	size_t size() const {

		//return
		return size_;
	}

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
	}

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
	}

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
	}

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
	}

	private:
	
	size_t size_;
	Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
