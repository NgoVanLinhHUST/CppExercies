#pragma once 
class rateGreaterTen : public exception
{
    public:
        const char* what() const throw()
        {
            return "Error: rate error!";
        }
};

class SamdIdException : public exception
{
    public:
        const char* what() const throw()
        {
            return "Error: Same Id!";
        }
};
