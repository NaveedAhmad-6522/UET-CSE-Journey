#include <iostream>
#include <cstring>
using namespace std;

class distanc_e
{
    int feet, inches;

public:
    void normalized();
    distanc_e() : feet(0), inches(0) {}
    distanc_e(int f, int i) : feet(f), inches(i) {}
    void showDistance()
    {
        cout << "(feet , inches ):"
             << "( " << feet << ", " << inches << " )" << endl;
        normalized();
    }
    distanc_e operator+(distanc_e &obj)
    {
        distanc_e obj1;
        obj1.feet = feet + obj.feet;
        obj1.inches = inches + obj.inches;
        obj1.normalized();
        return obj1;
    }
    void operator+=(distanc_e &obj1)
    {
        feet += obj1.feet;
        inches += obj1.inches;
    }
    bool operator>(distanc_e &obj1)
    {
        bool x = true;
        if ((feet > obj1.feet) || (feet == obj1.feet && inches > obj1.inches))
        {
            return x;
        }
        else
            return (x = false);
    }
    bool operator<(distanc_e &obj1)
    {
        bool x = true;
        if ((feet < obj1.feet) || (feet == obj1.feet && inches < obj1.inches))
        {
            return x;
        }
        else
            return (x = false);
    }
    bool operator>=(distanc_e &obj1)
    {
        bool x = true;
        if ((feet >= obj1.feet) || (feet == obj1.feet))
        {
            return x;
        }
        else
            return (x = false);
    }
    bool operator<=(distanc_e &obj1)
    {
        bool x = true;
        if ((feet <= obj1.feet) || (feet == obj1.feet))
        {
            return x;
        }
        else
            return (x = false);
    }
    bool operator==(distanc_e &obj1)
    {
        bool x = true;
        if (feet == obj1.feet) 
        {
            return x;
        }
        else
            return (x = false);
    }
    bool operator!=(distanc_e &obj1)
    {
        bool x = true;
        if (feet !=obj1.feet)
        {
            return x;
        }
        else
            return (x = false);
    }
    void operator++()
    {
        normalized();
        feet++;
        
    }
    void operator--(int)
    {
        normalized();
        feet--;
        
    }
    void operator++(int)
    {
        normalized();
        ++feet;
        
    }
    void operator--()
    {
         normalized();
        --feet;
       
    }
};
void distanc_e::normalized()
{
    if (inches >= 12)
    {
        feet += inches / 12;
        inches %= 12;
    }
}

int main()
{
    distanc_e d1(5, 8);
    distanc_e d2(2, 10);

    cout << "Initial distances:\n";
    d1.showDistance();
    d2.showDistance();
    distanc_e sum = d1 + d2;
    cout << "\nAfter addition:\n";
    sum.showDistance();
    d1 += d2;
    cout << "\nAfter compound addition:\n";
    d1.showDistance();
    cout << "\nComparison results:\n";
    cout << "d1 > d2: " << (d1 > d2) << endl;
    cout << "d1 < d2: " << (d1 < d2) << endl;
    cout << "d1 >= d2: " << (d1 >= d2) << endl;
    cout << "d1 <= d2: " << (d1 <= d2) << endl;
    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1 != d2: " << (d1 != d2) << endl;

        cout << "\nAfter post_increment and decrement:\n";
    d1++;
    d1.showDistance();

    d1--;
    d1.showDistance();
     cout << "\nAfter pre_increment and decrement:\n";

    ++d1;
    d1.showDistance();

    --d1;
    d1.showDistance();

    return 0;
}
