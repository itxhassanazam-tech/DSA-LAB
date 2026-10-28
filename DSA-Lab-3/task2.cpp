//#include <iostream>
//using namespace std;
//
//// Abstract class
//class Employee {
//public:
//	virtual double calculateSalary() = 0;  // Pure virtual function
//};
//
//// Derived class: FullTimeEmployee
//class FullTimeEmployee : public Employee {
//private:
//	double fixedSalary;
//
//public:
//	FullTimeEmployee(double salary) {
//		fixedSalary = salary;
//	}
//
//	double calculateSalary() override {
//		return fixedSalary;
//	}
//};
//
//// Derived class: PartTimeEmployee
//class PartTimeEmployee : public Employee {
//private:
//	int hoursWorked;
//	double hourlyRate;
//
//public:
//	PartTimeEmployee(int hours, double rate) {
//		hoursWorked = hours;
//		hourlyRate = rate;
//	}
//
//	double calculateSalary() override {
//		return hoursWorked * hourlyRate;
//	}
//};
//
//// Main function
//int main() {
//	FullTimeEmployee fullTime(50000);
//	PartTimeEmployee partTime(80, 500);
//
//	cout << "Full-Time Employee Salary: "
//		<< fullTime.calculateSalary() << endl;
//
//	cout << "Part-Time Employee Salary: "
//		<< partTime.calculateSalary() << endl;
//
//	return 0;
//}