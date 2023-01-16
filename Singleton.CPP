// It is a creational design pattern
// It ensures that a class has only one instance, while providing global access point to this instance

// Implementation Steps:

// 1. Make the default constructor private, to prevent other objects from using the new operator with the Singleton class
// 2. Create a static creation method that acts as a constructor. Under the hood, this method calls the private constructor to create an object and saves it in a static field. All following calls to this method return the cached object

/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;

class Logger {
private:
	static Logger *loggerInstance;
	Logger() { // private constructor
		cout << "First Time Instance is Created" << endl;
	}

public:
	static Logger* getInstance() {
		if (loggerInstance == NULL) {
			loggerInstance = new Logger();
		}
		return loggerInstance;
	}
	void log(string msg) {
		cout << msg << endl;
	}
};

Logger *Logger::loggerInstance = NULL;

int32_t main() {
	Logger *logger1 = Logger::getInstance();
	logger1->log("Message from User 1");
	Logger *logger2 = Logger::getInstance();
	logger2->log("Message from User 2");
	return 0;
}