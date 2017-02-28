// Natalie Souaid - Spring 2017 February 16th
// The Chain class holds a series of numbers (using a dynamic array).
// The Chain class has many overloaded operators, and can therefore
// be used in a natural way (adding two chains together/ "giving"
//a chain the contents of another (moving)/ etc).
// This is the ALTERED test_input_file.txt main/test file for more (in my opinion) readability

#include <chain.h>
#include <iostream>
#include <string>
using namespace std;
using namespace teaching_project;

// Place stand-alone function in unnamed namespace.
namespace {
	
	void TestPart1() {
	
		//cout << endl << "We are in TestPart1()" << endl;
		cout << "LINE 1: Two empty Chains are created and should yield 0 0: ";
		Chain<int> a, b;  // Two empty Chains are created
		cout << a.size() << ", " << b.size() << endl; // yields 0 0

		Chain<int> d{7};  // A chain containing 7 should be created.
		cout << "LINE 2: Should print 7: ";
		cout << d << endl;  // Should just print [7]

		cout << "LINE 3: a.ReadChain ->";
		a.ReadChain(); // User enters a chain, for example [4: 10 30 -1 2]

		cout << a << endl;  // Output should be what user entered.

		cout << "LINE 4: b.ReadChain ->";
		b.ReadChain();  // Same for b.
		cout << b << endl;

		//cout << "Copy constructor for c called with a's data" << endl;
		Chain<int> c{a};  // Calls copy constructor for c.
		
		cout << "LINE 5: cout << c ->";
		cout << c << endl;

		cout << "LINE 6: cout << a ->";
		cout << a << endl;

		cout << "LINE 7: a = b, cout << a ->";
		a = b;  // Should call the copy assignment operator for a.
		cout << a << " ";
		cout << "cout << b ->";
		cout << b << endl;

		//cout << "Move constructor for c called" << endl;
		Chain<int> e = move(c);  // Move constructor for c.
		
		cout << "LINE 8: (((Chain<int> e = move(c); move constructor))) cout << e ->";
		cout << e << endl;
		cout << "LINE 9: (((Chain<int> e = move(c); move constructor))) cout << c ->";
		cout << c << endl;

		a = move(e);  // Move assignment operator for a.
		cout << "LINE 10: (((a = move(e); move assignment))) cout << a ->";
		cout << a << endl;
		cout << "LINE 11: (((a = move(e); move assignment))) cout << e ->";
		cout << e << endl;
	}

	void TestPart2() {

		//cout << "We are in TestPart2" << endl;

		//cout << "string chain a and b created" << endl;
		Chain<string> a, b;

		
		a.ReadChain();  // User provides input for Chain a.
		cout << "LINE 12: a ->";
		cout << a << endl;

		b.ReadChain();  // User provides input for Chain b.
		cout << "LINE 13: b ->";
		cout << b << endl;

		cout << "LINE 14: a + b -> ";
		cout << a + b << endl; // Concatenates the two Chains.

		cout << "LINE 15: d ->";
		Chain<string> d = a + b;
		cout << d << endl;

		cout << "LINE 16: d +'high_there' -> ";
		cout << d + "hi_there" << endl;  // Adds an element to the end.
		cout << "LINE 17: a[2]->" << a[2] << endl;  // Should print the 3rd element.
		b[1] = "b_string";  // Should change the 2nd element to “b_string”.
		cout << "LINE 18: b[1]->" << b << endl;
		b[0] = "a_string";
		cout <<"LINE 19: b[0]->" << b << endl;

	}
}// namespace

int main(int argc, char **argv) {
	TestPart1();
	TestPart2();
return 0;
}


