#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include <vector>
using namespace std;
class Employee{
    /* This class is abstract class.
     * So, you must define pure virtual function.
     * Lists: double earnings() const;
     */
private:
    string firstName;
    string lastName;
    string socialSecurityNumber;
public:
    Employee(const string& first, const string& last, const string& ssn)
        : firstName{ first }, lastName{ last }, socialSecurityNumber{ ssn }{}
    virtual ~Employee() = default;

    void setFirstName(const string& first){ firstName = first; }
    void setLastName(const string& last) { lastName = last; }
    void setSocialSecurityNumber(const string& ssn) { socialSecurityNumber = ssn; }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getSocialSecurityNumber() const { return socialSecurityNumber; }

    virtual double earnings() const=0; //pure virtual
    virtual string toString() const{
        return getFirstName() + " " + getLastName() + " " + getSocialSecurityNumber();
    } //virtual
};

class SalariedEmployee: public Employee { //concrete class
private:
    double weeklySalary;
public:
    SalariedEmployee(const string& first, const string& last, const string& ssn, double salary = 0.0)
        : Employee(first, last, ssn){ setWeeklySalary(salary); } //delegating Constructor.
    virtual ~SalariedEmployee() = default;

    void setWeeklySalary(double salary) {
        if (salary < 0.0)
            throw invalid_argument("Weekly salary must be >= 0.0");
        weeklySalary = salary;
    }
    double getWeeklySalary() const { return weeklySalary; }

    //overriding
    virtual double earnings() const override{
        return getWeeklySalary();
    }
    virtual string toString() const override{
        ostringstream output;
        output << fixed << setprecision(2) << "salaried employee: "
            << Employee::toString() << endl;
        output << "weekly salary: " << getWeeklySalary();
        return output.str();
    }
};

class CommissionEmployee : public Employee{
private:
    double grossSales;
    double commissionRate;
public:
    CommissionEmployee(const string& first, const string& last, const string& ssn, double sales = 0.0, double rate = 0.0)
        : Employee{first, last, ssn}, grossSales{ sales }{ setCommissionRate(rate); }
    virtual ~CommissionEmployee() = default;

    void setCommissionRate(double rate){
        if (rate <= 0.0 || rate > 1.0)
            throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
        commissionRate = rate;
    }
    double getCommissionRate() const{ return commissionRate; }

    void setGrossSales(double sales) {
        if (sales < 0.0)
            throw invalid_argument("Gross sales must be >= 0.0");
        grossSales = sales;
    }
    double getGrossSales() const { return grossSales; }

    virtual double earnings() const override{
        return getCommissionRate() * getGrossSales();
    }
    virtual string toString() const override{
        ostringstream output;
        output << fixed << setprecision(2) << "commission employee: "
               << Employee::toString() << endl;
        output << "gross sales: " << getGrossSales() << endl;
        output << "commission rate: " << getCommissionRate();
        return output.str();
    }
};

class BasePlusCommissionEmployee: public CommissionEmployee{
private:
    double baseSalary;
public:
    BasePlusCommissionEmployee(const string& first, const string& last, const string& ssn, double sales = 0.0, double rate =0.0, double salary = 0.0)
        : CommissionEmployee(first, last, ssn, sales, rate){ setBaseSalary(sales); }
    virtual ~BasePlusCommissionEmployee() = default;

    void setBaseSalary(double salary){
        if(salary < 0.0)
            throw invalid_argument("Salary must be >= 0.0");
        baseSalary = salary;
    }
    double getBaseSalary() const { return baseSalary; }

    virtual double earnings() const override{
        return getBaseSalary() + CommissionEmployee::earnings();
    }
    virtual string toString() const override{
        ostringstream output;
        output << fixed << setprecision(2) << "Base-salaried: " << CommissionEmployee::toString() << endl;
        output << "base salary: " << getBaseSalary();
        return output.str();
    }
};

void virtualViaPointer(const Employee* const);
void virtualViaReference(const Employee&);

int main(void){
    cout << fixed << setprecision(2);
    SalariedEmployee salariedEmployee{"John", "Smith", "111-11-1111", 800};
    CommissionEmployee commissionEmployee{"Sue", "Jones", "333-33-3333", 10000, .06};
    BasePlusCommissionEmployee basePlusCommissionEmployee{"Bob", "Lewis", "444-44-4444", 5000, .04, 300};

    cout << "Employee processed individually using static binding" << endl;
    cout << salariedEmployee.toString();
    cout << salariedEmployee.earnings() << endl;
    cout << commissionEmployee.toString();
    cout << commissionEmployee.earnings() << endl;
    cout << basePlusCommissionEmployee.toString();
    cout << basePlusCommissionEmployee.earnings() << endl;

    vector<Employee*> employees{&salariedEmployee,&commissionEmployee,&basePlusCommissionEmployee};

    for (const Employee* e : employees){
        virtualViaPointer(e);
    }

    for (const Employee* e : employees){
        virtualViaReference(*e);
    }
    return 0;
}

void virtualViaPointer(const Employee* const baseClassPtr){
    cout << baseClassPtr->toString() << endl;
    cout << "earned: " << baseClassPtr->earnings() << endl << endl;
}
void virtualViaReference(const Employee& baseClassRef){
    cout << baseClassRef.toString() << endl;
    cout << "earned: " << baseClassRef.earnings() << endl << endl;
}