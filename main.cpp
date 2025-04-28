#include <iostream>
#include <string>
using namespace std;

// Base Class: Employee
// Represents a general employee with common attributes.
class Employee {
protected:
  string name;        // Employee's name
  int employeeNumber; // Employee's ID number
  string hireDate;    // Hire date of the employee

public:
  // Default and parameterized constructor
  // Initializes name, employee number, and hire date
  Employee(string n = "", int num = 0, string date = "") {
    name = n;
    employeeNumber = num;
    hireDate = date;
  }

  // Accessor Functions (Getters)
  // Return the values of the private/protected members
  string getName() const { return name; }
  int getEmployeeNumber() const { return employeeNumber; }
  string getHireDate() const { return hireDate; }

  // Mutator Functions (Setters)
  // Allow modification of private/protected members
  void setName(string n) { name = n; }
  void setEmployeeNumber(int num) { employeeNumber = num; }
  void setHireDate(string date) { hireDate = date; }

  // Display Employee's information
  void printEmployee() const {
    cout << "Name: " << name << endl;
    cout << "Employee Number: " << employeeNumber << endl;
    cout << "Hire Date: " << hireDate << endl;
  }
};

// Derived Class: ProductionWorker (inherits from Employee)
// Represents a worker with an assigned shift and hourly pay rate.
class ProductionWorker : public Employee {
protected:
  int shift;            // Shift: 1 for day, 2 for night
  double hourlyPayRate; // Hourly pay rate for the worker

public:
  // Constructor (uses initializer list to call base class constructor)
  ProductionWorker(string n = "", int num = 0, string date = "", int s = 1,
                   double rate = 0.0)
      : Employee(n, num, date) {
    setShift(s);            // Validate and set shift
    setHourlyPayRate(rate); // Validate and set hourly pay rate
  }

  // Accessors
  int getShift() const { return shift; }
  double getHourlyPayRate() const { return hourlyPayRate; }

  // Mutators with input validation
  void setShift(int s) {
    if (s == 1 || s == 2)
      shift = s;
    else {
      cout << "Invalid shift (must be 1 for day, 2 for night). Setting to day "
              "shift by default."
           << endl;
      shift = 1; // Default to day shift if invalid input
    }
  }

  void setHourlyPayRate(double rate) {
    if (rate >= 0)
      hourlyPayRate = rate;
    else {
      cout << "Invalid hourly rate (must be positive). Setting to 0." << endl;
      hourlyPayRate = 0.0; // Default to 0 if invalid input
    }
  }

  // Display ProductionWorker's full information
  void printProductionWorker() const {
    printEmployee(); // Call base class print
    cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
    cout << "Hourly Pay Rate: $" << hourlyPayRate << endl;
  }
};

// Derived Class: ShiftSupervisor (inherits from Employee)
// Represents a supervisor with a fixed annual salary and bonus.
class ShiftSupervisor : public Employee {
private:
  double annualSalary;          // Annual salary
  double annualProductionBonus; // Annual bonus based on production

public:
  // Constructor (uses initializer list to call base class constructor)
  ShiftSupervisor(string n = "", int num = 0, string date = "",
                  double salary = 0.0, double bonus = 0.0)
      : Employee(n, num, date) {
    setAnnualSalary(salary);         // Validate and set salary
    setAnnualProductionBonus(bonus); // Validate and set bonus
  }

  // Accessors
  double getAnnualSalary() const { return annualSalary; }
  double getAnnualProductionBonus() const { return annualProductionBonus; }

  // Mutators with validation
  void setAnnualSalary(double salary) {
    if (salary >= 0)
      annualSalary = salary;
    else {
      cout << "Invalid salary (must be positive). Setting to 0." << endl;
      annualSalary = 0.0;
    }
  }

  void setAnnualProductionBonus(double bonus) {
    if (bonus >= 0)
      annualProductionBonus = bonus;
    else {
      cout << "Invalid bonus (must be positive). Setting to 0." << endl;
      annualProductionBonus = 0.0;
    }
  }

  // Display ShiftSupervisor's full information
  void printShiftSupervisor() const {
    printEmployee(); // Call base class print
    cout << "Annual Salary: $" << annualSalary << endl;
    cout << "Annual Production Bonus: $" << annualProductionBonus << endl;
  }
};

// Derived Class: TeamLeader (inherits from ProductionWorker)
// Represents a team leader with bonus and training hours.
class TeamLeader : public ProductionWorker {
private:
  double monthlyBonus;       // Monthly bonus for leading the team
  int requiredTrainingHours; // Required training hours
  int attendedTrainingHours; // Training hours actually attended

public:
  // Constructor (uses initializer list to call base class constructor)
  TeamLeader(string n = "", int num = 0, string date = "", int s = 1,
             double rate = 0.0, double bonus = 0.0, int required = 0,
             int attended = 0)
      : ProductionWorker(n, num, date, s, rate) {
    setMonthlyBonus(bonus);
    setRequiredTrainingHours(required);
    setAttendedTrainingHours(attended);
  }

  // Accessors
  double getMonthlyBonus() const { return monthlyBonus; }
  int getRequiredTrainingHours() const { return requiredTrainingHours; }
  int getAttendedTrainingHours() const { return attendedTrainingHours; }

  // Mutators with validation
  void setMonthlyBonus(double bonus) {
    if (bonus >= 0)
      monthlyBonus = bonus;
    else {
      cout << "Invalid monthly bonus (must be positive). Setting to 0." << endl;
      monthlyBonus = 0.0;
    }
  }

  void setRequiredTrainingHours(int hours) {
    if (hours >= 0)
      requiredTrainingHours = hours;
    else {
      cout << "Invalid required training hours. Setting to 0." << endl;
      requiredTrainingHours = 0;
    }
  }

  void setAttendedTrainingHours(int hours) {
    if (hours >= 0)
      attendedTrainingHours = hours;
    else {
      cout << "Invalid attended training hours. Setting to 0." << endl;
      attendedTrainingHours = 0;
    }
  }

  // Display TeamLeader's full information
  void printTeamLeader() const {
    printProductionWorker(); // Call parent class print
    cout << "Monthly Bonus: $" << monthlyBonus << endl;
    cout << "Required Training Hours: " << requiredTrainingHours << endl;
    cout << "Attended Training Hours: " << attendedTrainingHours << endl;
  }
};

int main() {
  // Create two ProductionWorker objects with test data
  ProductionWorker worker1("Alice Johnson", 101, "01/15/2020", 1, 25.50);
  ProductionWorker worker2("Bob Smith", 102, "03/22/2021", 2, 22.75);

  // Create one ShiftSupervisor object with test data
  ShiftSupervisor sup1("Charles Brown", 201, "06/30/2018", 75000, 5000);

  // Create one TeamLeader object with test data
  TeamLeader team1("Dana White", 301, "09/10/2019", 1, 30.00, 1000, 40, 38);

  // Display all object information
  cout << "Production Worker 1:" << endl;
  worker1.printProductionWorker();
  cout << "\nProduction Worker 2:" << endl;
  worker2.printProductionWorker();

  cout << "\nShift Supervisor:" << endl;
  sup1.printShiftSupervisor();

  cout << "\nTeam Leader:" << endl;
  team1.printTeamLeader();

  return 0;
}
