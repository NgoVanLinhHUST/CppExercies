#include <iostream>

using namespace std;



class Employee
{
	protected:
		int ID;
		string name;
		int age;
		int telephone;
		double rate; // exception


	public:
		virtual int calcultSalary() const = 0; 
};	
class Program
{
	public:
		void addEmployee();
		void updateEmployeeByID();
		void deleteEmployeeByID();
		void searchEmployeeByName();
		void showListEmployee();
		void run();
		
};
class FulltimeEmployee: public Employee
{	

};
class ParttimeEmployee: public Employee
{

};

class HourlyEmployee: public Employee
{

};

int main(int argc, char *argv[])
{
	std::cout << "Hello world!" << std::endl;
}