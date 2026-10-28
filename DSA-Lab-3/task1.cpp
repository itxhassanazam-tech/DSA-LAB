#include <iostream>
using namespace std;
class Course {
public:
	virtual void duration() = 0;
};

class OnlineCourse : public Course {
private:
	int weeks;
	int hoursPerWeek;

public:
	OnlineCourse(int w, int h) {
		weeks = w;
		hoursPerWeek = h;
	}

	void duration() override {
		cout << "Online Course Duration: " << weeks << " weeks" << endl;
		cout << "Total Study Hours: " << weeks * hoursPerWeek << " hours" << endl;
	}
};

class OfflineCourse : public Course {
private:
	int months;
	int hoursPerDay;

public:
	OfflineCourse(int m, int h) {
		months = m;
		hoursPerDay = h;
	}

	void duration() override {
		cout << "Offline Course Duration: "
			<< months << " months" << endl;
		cout << "Study Hours Per Day: "
			<< hoursPerDay << " hours" << endl;
	}
};


int main() {
	cout << "vhsvhgv";
	OnlineCourse online(8, 5);
	OfflineCourse offline(3, 4);

	cout << "--- Online Course ---" << endl;
	online.duration();

	cout << "\n--- Offline Course ---" << endl;
	offline.duration();

	return 0;
}