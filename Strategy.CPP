// It is a behavioral design patter.
// Enables a client code to choose from a family of related but different algorithms and gives it a simple way to choose any of the algorithm in runtime depending on the client context.

/* जय श्री गणेश */

#include<bits/stdc++.h>
using namespace std;

class ISocialMediaStrategy {
public:
	virtual void connectTo(string fname) = 0;
};

class FacebookStrategy : public ISocialMediaStrategy {
	void connectTo(string fname) {
		cout << "Connected to " << fname << " in Facebook" << endl;
	}
};

class TwitterStrategy : public ISocialMediaStrategy {
	void connectTo(string fname) {
		cout << "Connected to " << fname << " in Twitter" << endl;
	}
};

class InstagramStrategy : public ISocialMediaStrategy {
public:
	void connectTo(string fname) {
		cout << "Connected to " << fname << " in Instagram" << endl;
	}
};

class SocialMediaContext {
private:
	ISocialMediaStrategy *smstrategy;
public:
	void setSocialMediaStrategy(ISocialMediaStrategy *smstrategy) {
		this->smstrategy = smstrategy;
	}
	void connect(string fname) {
		smstrategy->connectTo(fname);
	}
};

int32_t main() {
	SocialMediaContext *context = new SocialMediaContext();

	context->setSocialMediaStrategy(new FacebookStrategy());
	context->connect("Shivam");

	context->setSocialMediaStrategy(new InstagramStrategy());
	context->connect("Pulkit");

	context->setSocialMediaStrategy(new TwitterStrategy());
	context->connect("Anupam");

	return 0;
}