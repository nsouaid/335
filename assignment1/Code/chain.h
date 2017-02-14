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
	Chain() : size_{0}, array_{new Object[0]}{
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
	}

	// Move-assignment.
	// Just use std::swap() for all variables.
	Chain& operator=(Chain &&rhs) = default;

	//deallocate the memory pointed to by the array_
	~Chain() {
		//loop through each index of the dynamic array in the heap 
		//so that we may relcaim its memory, using the delete operator
		for (size_t i =0; i < size_; i++) {
			delete [] array_;
		}
		//don't forget to set the size to 0.
		size_ = 0;
	}

	// End of big-five.
	//-----------------------------------------------------------------

	// One parameter constructor.
	Chain(const Object& item) {
		
		//size will be 1
		size_ = 1;

		//create a new object space for array to put the item in : static cast!
		array_ = new Object[static_cast<int>(size_)];

		//place item in the array : static cast!
		array_[static_cast<int>(size_)] = item;

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

		std::cout << "Original line from file (should be): " << line_from_file << std::endl;

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

		std::cout << "Line without the punctuation: " << line_no_punc << std::endl;

		//create a stringstream to manipulate the line_no_punc
		std::istringstream s_stream(line_no_punc);

		//make sure that the first char from the string is able to be placed in size_
		s_stream >> t_size;

		std::cout << t_size << std::endl;

		this.size_ = t_size;
















		/*
		std::string size_as_a_string;
		std::string final_line = "";
			the following code gave me trouble. scrapped and tried again differently
		//obtain and set size using size_as_a_string and stringstream
		size_as_a_string = line_no_punc[0];
		//open the new stringstream
		std::istringstream theStream(size_as_a_string);
		//do some magic, turn size_as_a_string into size_as_a_size_t
		theStream >> size_as_a_size_t;
		size_ = size_as_a_size_t;
		std::cout << "size_: " << size_ << std::endl;
		i =2;
		//remove that number by skipping the first {{0th}} index and placing
		//the remaining characters into the final string for stringstream use
		std::cout << "line_no_punc.size(): " << line_no_punc.size() << std::endl;
		while (i < (line_no_punc.size())) {
			final_line[i-2] += line_no_punc[i];
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

	size_t size() const {
		return size_;
	}

	// @location: an index to a location in the chain.
	// @returns the Object at @location.
	// const version.
	// abort() if out-of-range.
	const Object& operator[](size_t location) const { 
	// Write something
	}

	// @location: an index to a location in the range.
	// @returns the Object at @location.
	// non-const version.
	// abort() if out-of-range.

	Object& operator[](size_t location) {
	// Write something (will be the same as above)
	}

	//  @c1: A chain.
	//  @c2: A second chain.
	//  @return the concatenation of the two chains.
	friend Chain operator+(const Chain &c1, const Chain &c2) {
	// Write something.
	}

	// Overloading the << operator.
	friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
		for (size_t i = 0; i < a_chain.size()-1; i++) {
			out << a_chain.array_[i] << std::endl;
		}
	return out;
	}

	private:
	
	size_t size_;
	Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
