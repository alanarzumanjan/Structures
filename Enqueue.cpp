#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Peoples
{
public:
    unsigned short products_count;
    void calculate_products()
    {
        products_count = 1 + rand() % 10;
    }
    unsigned short time_kassa_come;
    void random_time_kassa()
    {
        time_kassa_come = 1 + rand() % 10;
    }
    
};

class Kassa
{
public:
    unsigned short max_open_kasses;
    unsigned short time;
    unsigned short average_time_maintenance;
    unsigned short max_people_rinda;
};

class Enqueue
{
private:
    unsigned short max_rinda = 6;

public:
};

int main()
{
    unsigned long Marki;
    cout << "Enter how many marks comes in: ";
    cin >> Marki;

    unsigned short kassa_count;
    cout << "Enter max kassa count: ";
    cin >> kassa_count;

    return 0;
}