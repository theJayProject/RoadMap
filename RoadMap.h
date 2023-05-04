#pragma once
#include <iostream>


//Classes
//Addition Overloading
class Addition {
public:
	int x, y;

	Addition operator+(const Addition& other) const {
		Addition addition;
		addition.x = x + other.x;
		addition.y = y + other.y;
		return addition;
	}
};
//Subtraction Overloading
class Subtraction {
public:
	int x, y;

	Subtraction operator-(const Subtraction& other) const {
		Subtraction sub;
		sub.x = x - other.x;
		sub.y = y - other.y;
		return sub;
	}
};
//Multiplication Overloading
class Multiply {
public:
	int x, y;

	Multiply operator*(int multiplication) const {
		Multiply mul;
		mul.x = x * multiplication;
		mul.y = y * multiplication;
		return mul;
	}
};
//Division Overloading
class Division {
public:
	int numerator, denominator;

	Division operator/(const Division& other) const {
		Division div;
		div.numerator = numerator / other.numerator;
		div.denominator = denominator / other.denominator;
		return div;
	}
};
//Equality Operator Overloading
class Equality {
public:
	int x, y;

	bool operator==(const Equality& equal) const {
		return x == equal.x && y == equal.y;
	}
};
//Inequality Operator Overloading
class Inequality {
public:
	int x, y;

	bool operator!=(const Inequality& inequal) const {
		return !(*this == inequal);
	}

	bool operator==(const Inequality& inequal) const {
		return x == inequal.x && y == inequal.y;
	}
};
//Comparison Operators >, <, <=, >= Overloading
class Comparison {
private:
	int com;
public:
	Comparison(int x = 0) : com(x) {}

	bool operator<(const Comparison& other) const {
		return com < other.com;
	}

	bool operator>(const Comparison& other) const {
		return com > other.com;
	}

	bool operator<=(const Comparison& other) const {
		return com <= other.com;
	}

	bool operator>=(const Comparison& other) const {
		return com >= other.com;
	}

	int getVal() const {
		return com;
	}
};
//Subscript Operator [] Overloading
class Subscript {
private:
	int sub[5];
public:
	int& operator[](int index) {
		return sub[index];
	}
	const int& operator[](int index) const {
		return sub[index];
	}
};
//Function Call Operator Overloading
class FunctionCall {
public:
	int operator()(int x) {
		return x * 2;
	}
};
//Conversion Operator type() Overloading
class Conversion {
private:
	int conversion;

public:
	Conversion(int con) : conversion(con) {}
	operator int() const {
		return conversion;
	}
};
//Stream Insertion and Extraction Operator overloading
class InsertionExtraction {
private:
	int inex;

public:
	InsertionExtraction(int val = 0) : inex(val) {}

	// Stream insertion operator overload
	friend std::ostream& operator<<(std::ostream& os, const InsertionExtraction& obj) {
		os << obj.inex;
		return os;
	}

	// Stream extraction operator overload
	friend std::istream& operator>>(std::istream& is, InsertionExtraction& obj) {
		is >> obj.inex;
		return is;
	}
};


//Functions


//Arithmetics
//VARIABLES FOR CIN
int n, m;
void arithmetics() {
	std::cout << "Give me an integer \n";
	std::cin >> n;
	std::cout << "Give me another integer \n";
	std::cin >> m;
	std::cout << "Added: " << n + m << "\n" << "Subtracted: " << n - m << "\n" << "Divided: " << n / m << "\n" << "Multiplied: " << n * m << "\n" << "Modulus: " << n % m << "\n" << "\n";
}
//Bitwise
void bitwise() {
	std::cout << "Bitwise and: " << (n & m) << "\n";
	std::cout << "Bitwise or: " << (n | m) << "\n";
	std::cout << "Bitwise xor: " << (n ^ m) << "\n";
	std::cout << "Bitwise unary values: " << ~n << " " << ~m << "\n" << "\n";

}
//Logical Operators
void logicalOperators() {
	if (n > 0 && m > 0) {
		std::cout << "Both integers are bigger than zero." << "\n";
	}
	else {
		std::cout << "Either one or both of the integers are smaller than zero." << "\n";
	}
	if (n > 0 || m > 0) {
		std::cout << "Either one or both of the integers are bigger than zero." << "\n";
	}
	else {
		std::cout << "Neither of the integers are bigger than zero." << "\n";
	}
	if (n != 1) {
		std::cout << "The first integer does not equal one." << "\n";
	}
	else {
		std::cout << "The first integer is one." << "\n";
	}
	std::cout << "\n";
}

//Loops
void loops() {
	int x = 0;
	for (x; x < 5; x++) {
		std::cout << "This is a for loop. \n";
	}

	while (x != 0) {
		std::cout << "This is a while loop. \n";
		x--;
	}
	do {
		std::cout << "This is a do...while loop. \n";
		x++;
	} while (x != 5);
}

///////Operator Overloading///////

///////ARITHMETIC OPERATOR OVERLOADING///////
//Addition Operator Overloading
int additionOperator() {
	Addition a = { n, m }, b = { m, n };
	Addition c = a + b;
	std::cout << "Adding both integers in two separate ways creates an operator overload, results being: " << c.x << ", " << c.y << "\n";
	return 0;
}

//Subtraction Operator Overloading
int subtractionOperator() {
	Subtraction a = { n, m }, b = { m, n };
	Subtraction c = a - b;
	std::cout << "Subtracting both integers in two separate ways creates an operator overload, results being: " << c.x << ", " << c.y << "\n";
	return 0;
}

//Multiplication Operator Overloading
int multiplicationOperator() {
	Multiply a = { n, m };
	Multiply multiplication = a * 2;
	std::cout << "Multiplying both integers by two creates an operator overload, results being: " << multiplication.x << ", " << multiplication.y << "\n";
	return 0;
}

//Division Operator Overloading
int divisionOperator() {
	Division a = { n, m }, b = { m, n };
	Division c = a / b;
	std::cout << "Dividing both integers in both ways ways creates an operator overload, results being: " << c.numerator << ", " << c.denominator << "\n";
	return 0;
}

//Equality Operator Overloading
int equalityOperator() {
	Equality a = { n, m }, b = { m, n };
	std::cout << "Overloading the equality operator can compare the two integers. They are the same. " << std::boolalpha << (a == b) << "\n"; // Output: false
	return 0;
}

//Inequality Operator Overloading
int inequalityOperator() {
	Inequality a = { n, m }, b = { m , n };
	std::cout << "Overloading the inequality Operator:" << "\n";
	if (a != b) {
		std::cout << "The two integers are not equal." << "\n";
	}
	else {
		std::cout << "The integers are equal." << "\n";
	}
	return 0;
}

//Comparison Operator Overloading
int comparisonOperator() {
	Comparison a(n);
	Comparison b(m);

	if (a < b) {
		std::cout << "The first integer is less than the second integer.\n";
	}
	if (a > b) {
		std::cout << "The first integer is greater than the second integer.\n";
	}
	if (a <= b) {
		std::cout << "The first integer is less than or equal to the second integer.\n";
	}
	if (a >= b) {
		std::cout << "The first integer is greater than or equal to the second integer.\n";
	}
	return 0;
}
//Subscript Operator Overloading
int subscriptOperator() {
	Subscript a;
	a[0] = n;
	a[1] = m;
	std::cout << "The first digit in the overloaded array is " << a[0] << "\n";
	std::cout << "The second digit in the overloaded array is " << a[1] << "\n";
	return 0;
}

//Function Call Operator Overloading
int functionCallOperator() {
	FunctionCall f;
	std::cout << "Doubling the second integer using an overloaded function call: " << f(m) << "\n";
	return 0;
}

//Conversion Operator Overloading
int conversionOperator() {
	Conversion num(n);
	int convertedNum = num;
	std::cout << "Using an overloaded conversion operator, here's a converted variable: " << convertedNum << "\n";
	return 0;
}

//Insertion and Extraction Operator Overloading
int insertionExtractionOperators() {
	InsertionExtraction obj1(n);
	InsertionExtraction obj2 = m;

	std::cout << "Insertion Overloading: " << obj1 << "\n";
	std::cout << "Extraction Overloading: " << obj2 << "\n";

	return 0;
}

//Lambda expressions create inline, anonymous functions - auto is used in static programming
auto lambda = []() {
	std::cout << "This lambda has an empty capture list.\n";
};



//////////////////////STRUCTURAL PROGRAMMING//////////////////////////
//Templates, static and const, when used correctly are good to be used in static programming
template <int N>
struct square {
	static const int value = N * N;
};

auto Square() {
	const int f = 12;
	std::cout << "The square of 12 was created using a template: " << square<f>::value << "\n";
}
//POINTERS
//Unique Pointer
class uniquePointer {
public:
	uniquePointer() {
		std::cout << "Constructing a Class.\n";
	}
	~uniquePointer() {
		std::cout << "Destructing a Class. - unique_ptr used.\n";
	}
	void Something() {
		std::cout << "The class doing something.\n";
	}
};

//Typename in Template
template<typename Template>
void print(Template value) {
	std::cout << value << std::endl;
}
//Using = Typename
template<typename T>
using MyPointer = T*;


//Say yay to Polymorphism

//////////////////////////////////////////////////////////////////////////
//////////////////////// VIRTUAL CLASS ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//MAKE A FOOKIN CLASS
class niceBody {

public:
	//MAKE A VIRTUAL FUNCTION THAT IS BOTH 'virtual' AND A FUNCTION(){}
	virtual void BMI() {
		std::cout << "Your BMI is good" << "\n";
	}
	//HERE'S A NON-VIRTUAL FUNCTION
	void funny() {
		std::cout << "You're beautiful anyway" << "\n";
	}
};

//HERE'S A DERIVED CLASS
class badBody : public niceBody {
public:
	void BMI() {
		std::cout << "Your BMI is bad" << "\n";
	}
	void funny() {
		std::cout << "You're ugly anyway" << "\n";
	}
};
//////////////////////////////////////////////////////////////////////////
//////////////////////// OVERRIDDEN FUNCTION /////////////////////////////
//////////////////////////////////////////////////////////////////////////

class niceEyes {
public:
	//Introduce virtual class (OVERRIDDE) 
	virtual void colour() {
		std::cout << "All eye colours are beautiful" << "\n";
	}
	//Introduce virtual class (NO OVERRIDDE)
	virtual void shape() {
		std::cout << "All eye shapes are beautiful" << "\n";
	}
};
class uglyEyes : public niceEyes {
public:
	//Override virtual class (OVERRIDDE) 
	void colour() override {
		std::cout << "All eye colours are ugly" << "\n";
	}
	//Override virtual class (NO OVERRIDDE)
	void shape() {
		std::cout << "All eye shapes are ugly" << "\n";
	}
};
//////////////////////////////////////////////////////////////////////////
//////////////////////// OBJECT SLICING //////////////////////////////////
//////////////////////////////////////////////////////////////////////////
class niceLegs {
public:
	void length() {
		std::cout << "Long legs are nice" << "\n";
	}
	void width() {
		std::cout << "Thicc legs are nice" << "\n";
	}
};
class uglyLegs : public niceLegs {
public:
	void tan() {
		std::cout << "Tanned legs are ugly" << "\n";
	}
};
//////////////////////////////////////////////////////////////////////////
////////////// PURE VIRTUAL FUNCTIONS + ABSTRACT CLASSES /////////////////
//////////////////////////////////////////////////////////////////////////
class niceAss {
public:
	//PURE VIRTUAL FUNCTION
	virtual void thicc() = 0;
};
class uglyAss : public niceAss {
public:
	void thicc() {
		std::cout << "Dat ass is thicc" << "\n";
	}
};
//Pure Virtual Functions are a Virtual Functions where you don't declare the function, by assigning a 0 in the declaration.
//Pure Virtual Functions are used in Abstract Classes.

//RTTI - RUN-TIME TYPE INFORMATION

//dynamic_cast
class BaseDynamicCast {
public:
	virtual ~BaseDynamicCast() {}
};
class DerivedDynamicCast : public BaseDynamicCast {
public:
	void text() {
		std::cout << "This is the Derived Class called using dynamic_cast.\n";
	}
};

//type_id