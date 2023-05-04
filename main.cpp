
#include "RoadMap.h"
#include <memory>


int main() {
	//Arithmetics
	arithmetics();
	//Bitwise Operator
	bitwise();
	//Logical Operators
	logicalOperators();
	//Addition Operator Overloading
	additionOperator();
	//Subtraction Operator Overloading
	subtractionOperator();
	//Multiplication Operator Overloading
	multiplicationOperator();
	//Division Operator Overloading
	divisionOperator();
	//Equality Operator Overloading
	equalityOperator();
	//Inequality Operator Overloading
	inequalityOperator();
	//Comparison Operators Overloading
	comparisonOperator();
	//Subscript Operator Overloading
	subscriptOperator();
	//Function Call Operator Overloading
	functionCallOperator();
	//Conversion Operator Overloading
	conversionOperator();
	//Insertion and Extraction Operator Overloading
	insertionExtractionOperators();
	//Loops
	loops();
	//Empty Lambda
	lambda();
	//Templates, static and const are used in static programming
	Square();
	//Using pointers in static programming
	std::unique_ptr<uniquePointer> uptr(new uniquePointer());
	uptr->Something();
	uptr.reset();
	//Shared and Weak Pointer
	std::shared_ptr<std::string>p1 = std::make_shared<std::string>("This shared pointer is doing something\n");
	std::weak_ptr<std::string> p2;
	p2 = p1;
	std::cout << *p1 << "Weak pointer counts left: " <<  p2.use_count() << "\n";
	//Resetting the weak pointer so it is no longer shared
	p2.reset();
	if (p2.expired()) {
		std::cout << "The weak pointer has expired.\n";
	}
	//Type Traits
	//std::boolalpha changes results from "1" and "0" in booleans to "true" and "false"
	std::cout << std::boolalpha;
	
	//is_integral
	std::cout << "Int is integral: " << std::is_integral<int>::value << "\n";
	std::cout << "Double is integral: " << std::is_integral<double>::value << "\n";
	//is_pointer
	std::cout << "Int* is a pointer: " << std::is_pointer<int*>::value << "\n";
	std::cout << "Int is a pointer: " << std::is_pointer<int>::value << "\n";
	//is_class
	std::cout << "Previously created 'Addition' is a class: " << std::is_class<Addition>::value << "\n";
	std::cout << "Int is a class: " << std::is_class<int>::value << "\n";
	//is_same
	std::cout << "Int and Int are the same: " << std::is_same<int, int>::value << "\n";
	std::cout << "Int and Double are the same: " << std::is_same<int, double>::value << "\n";
	
	//Type aliases
	//using keyword
	using integer = int;
	std::cout << "integer and int are the same: " << std::is_same<int, integer>::value << "\n";
	//typedef keywoard
	typedef char character;
	std::cout << "character and char are the same: " << std::is_same<char, character>::value << "\n";
	//typename in a template
	print<std::string>("Hello, world!\n");
	//Using + Typename
	MyPointer<std::string> ptr = new std::string("This is written with a typenamed template that changes a pointer name to MyPointer.\n");
	std::cout << *ptr;
	delete ptr;

	//DYNAMIC TYPING
	//Polymorphism, Inheritence, Erasure are used in Dynamic typing. Here are different examples of each
	//////////////////////// VIRTUAL CLASS ///////////////////////////////////
	niceBody* nice_body;
	badBody bad_body;
	nice_body = &bad_body;
	//Derived class because BMI() is virtual
	nice_body->BMI();
	//Base class because funny() is not virtual
	nice_body->funny();

	//////////////////////// OVERRIDDEN FUNCTION /////////////////////////////
	niceEyes* nice_eyes;
	uglyEyes ugly_eyes;
	nice_eyes = &ugly_eyes;
	nice_eyes->colour();
	nice_eyes->shape();
	//Both cases show the derived class result, as there are two virtual functions.
	//" override "  is used to avoid bugs.

	//////////////////////// OBJECT SLICING //////////////////////////////////
	niceLegs nice_legs;
	uglyLegs ugly_legs;
	nice_legs = ugly_legs;
	//Only length and width is copied to ugly_legs.
	//Object Slicing here in ugly_legs is a space-saving method because it cuts off the tan, and applies only the length and width.

////////////// PURE VIRTUAL FUNCTIONS + ABSTRACT CLASSES /////////////////
	niceAss* nice_ass;
	uglyAss ugly_ass;
	nice_ass = &ugly_ass;
	//PRINTS DERIVED, ABSTRACT CLASS AS A PURE VIRTUAL FUNCTION IS OVERRIDDEN.
	ugly_ass.thicc();
	nice_ass->thicc();
	//RTTI
	//dynamic_cast
	BaseDynamicCast* base_ptr = new DerivedDynamicCast;
	DerivedDynamicCast* derived_ptr = dynamic_cast<DerivedDynamicCast*>(base_ptr);
	derived_ptr->text();
	delete base_ptr;
	//typeid
	BaseTypeID* base_ptr2 = new DerivedTypeID;
	if (typeid(*base_ptr2) == typeid(DerivedTypeID)) {
		std::cout << "This object is a type of DerivedTypeID - This was checked using typeid." << std::endl;
	}
	else {
		std::cout << "Object is not of type DerivedTypeID!" << std::endl;
	}
	delete base_ptr2;



	return 0;

}
