// It is a creational design pattern
// Define an interface for creating an object, but let subclasses decide which class to instantiate
// Also known as "virtual" constructor

/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;

class Vechile {
public:
	virtual void showType() = 0;
};

class Car : public Vechile {
public:
	void showType() {
		cout << "This is a Car" << endl;
	}
};

class Bike : public Vechile {
public:
	void showType() {
		cout << "This is a Bike" << endl;
	}
};

class VechileFactory {
public:
	static Vechile* getVechile(string vechileType) {
		Vechile *vechile;
		if (vechileType == "car") {
			vechile = new Car();
		}
		else if (vechileType == "bike") {
			vechile = new Bike();
		}
		else {
			vechile = NULL;
		}
		return vechile;
	}
};

int32_t main() {
	string vechileType;
	cin >> vechileType;
	Vechile *vechile = VechileFactory::getVechile(vechileType);
	if (vechile) {
		vechile->showType();
	}
	else {
		cout << "Invalid Type" << endl;
	}
	return 0;
}