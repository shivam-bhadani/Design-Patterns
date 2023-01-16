// It is a behavioral design pattern
// Defines a subscription mechanism to notify multiple objects about any events that happen to the object they are observing.

// Subject is also called Publisher and Observer is also called subscriber

/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;


// Observer
class IObserver {
protected:
	int observerID;
public:
	IObserver(int id) {
		observerID = id;
	}
	virtual void notification(string msg) = 0;
};

// Subject
class ISubject {
private:
	list<IObserver*> observarsList;
public:
	void subscribe(IObserver *observer) {
		observarsList.push_back(observer);
	}
	void unsubscribe(IObserver *observer) {
		observarsList.remove(observer);
	}
	void notify(string msg) {
		for (auto& observar : observarsList) {
			observar->notification(msg);
		}
	}
};

// Concrete Observer
class CarObserver : public IObserver {
public:
	CarObserver(int id) : IObserver(id) {}
	void notification(string msg) {
		cout << "CarObserver " << observerID << " recieves a msg - " << msg << endl;
	}
};

// Concrete Observer
class BikeObserver : public IObserver {
public:
	BikeObserver(int id) : IObserver(id) {}
	void notification(string msg) {
		cout << "BikeObserver " << observerID << " recieves a msg - " << msg << endl;
	}
};

// Concrete Subject
class CarSubject : public ISubject {
public:
	void publishCar() {
		notify("New Car Published");
	}
};

// Concrete Subject
class BikeSubject : public ISubject {
public:
	void publicBike() {
		notify("New Bike Published");
	}
};

int32_t main() {

	CarSubject *carSubject = new CarSubject();
	BikeSubject *bikeSubject = new BikeSubject();

	CarObserver *carObserver1 = new CarObserver(1);
	CarObserver *carObserver2 = new CarObserver(2);
	CarObserver *carObserver3 = new CarObserver(3);

	BikeObserver *bikeObserver1 = new BikeObserver(1);
	BikeObserver *bikeObserver2 = new BikeObserver(2);
	BikeObserver *bikeObserver3 = new BikeObserver(3);

	carSubject->subscribe(carObserver1);
	carSubject->subscribe(carObserver2);
	carSubject->subscribe(carObserver3);

	bikeSubject->subscribe(bikeObserver1);
	bikeSubject->subscribe(bikeObserver2);
	bikeSubject->subscribe(bikeObserver3);

	carSubject->publishCar();
	bikeSubject->publicBike();

	carSubject->unsubscribe(carObserver1);
	bikeSubject->unsubscribe(bikeObserver3);

	carSubject->publishCar();
	bikeSubject->publicBike();

	return 0;
}