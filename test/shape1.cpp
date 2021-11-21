#include <iostream>
using namespace std;
// class FileNotFoundException : public exception
// {
//     public:
//         const char* what() const throw()
//         {
//             return "Error: File not found!";
//         }
// };
class DivisionByZeroException : public exception
{
    public:
        const char* what() const throw()
        {
            return "Error: division by zero!";
        }
};
int division(const int &a, const int &b)
{
	//if (b == 0) throw "Division by zero exception!";
	if (b == 0) throw DivisionByZeroException();
	return a/b;
}

int main(int argc, char *argv[])
{
	int x, y;
	cout << "Enter x: "; cin >> x;
	while (true)
	{
		try {
			cout << "Enter y: "; cin >> y;
			int z = division(x, y);
			cout << x << "/" << y << " = " << z << endl;
			break;
		} catch (const char* msg) {
			cout << msg << ". Please try again" << endl;
		} catch (DivisionByZeroException ex)
		{
			cout << ex.what() << ". Please try again!" << endl;
		}
	}
	return 0;
}