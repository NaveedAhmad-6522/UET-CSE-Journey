#include <iostream>

class Distance {
private:
    int feet, inches;

    // Private member function to normalize inches (ensure it's between 0 and 11)
    void normalizeInches() {
        if (inches >= 12) {
            feet += inches / 12;
            inches %= 12;
        } else if (inches < 0) {
            feet += (inches / 12) - 1;
            inches = 12 + (inches % 12);
        }
    }

public:
    // Default constructor
    Distance() : feet(0), inches(0) {}

    // Parameterized constructor
    Distance(int f, int i) : feet(f), inches(i) {
        normalizeInches();
    }

    // Display distance
    void showDistance() const {
        std::cout << "Distance: " << feet << " feet, " << inches << " inches\n";
    }

    // Overloaded addition operator
    Distance operator+(const Distance& obj) const {
        Distance result;
        result.feet = feet + obj.feet;
        result.inches = inches + obj.inches;
        result.normalizeInches();
        return result;
    }

    // Overloaded addition assignment operator
    void operator+=(const Distance& obj) {
        feet += obj.feet;
        inches += obj.inches;
        normalizeInches();
    }

    // Overloaded relational operators
    bool operator>(const Distance& obj) const {
        return (feet > obj.feet) || (feet == obj.feet && inches > obj.inches);
    }

    bool operator<(const Distance& obj) const {
        return (feet < obj.feet) || (feet == obj.feet && inches < obj.inches);
    }

    bool operator>=(const Distance& obj) const {
        return !(*this < obj);
    }

    bool operator<=(const Distance& obj) const {
        return !(*this > obj);
    }

    // Overloaded equality operators
    bool operator==(const Distance& obj) const {
        return (feet == obj.feet) && (inches == obj.inches);
    }

    bool operator!=(const Distance& obj) const {
        return !(*this == obj);
    }

    // Overloaded pre-increment operator
    Distance& operator++() {
        ++inches;
        normalizeInches();
        return *this;
    }

    // Overloaded post-increment operator
    Distance operator++(int) {
        Distance temp(feet, inches);
        ++inches;
        normalizeInches();
        return temp;
    }

    // Overloaded pre-decrement operator
    Distance& operator--() {
        --inches;
        normalizeInches();
        return *this;
    }

    // Overloaded post-decrement operator
    Distance operator--(int) {
        Distance temp(feet, inches);
        --inches;
        normalizeInches();
        return temp;
    }
};

int main() {
    Distance d1(5, 8);
    Distance d2(2, 10);

    std::cout << "Initial distances:\n";
    d1.showDistance();
    d2.showDistance();

    Distance sum = d1 + d2;
    std::cout << "\nAfter addition:\n";
    sum.showDistance();

    d1 += d2;
    std::cout << "\nAfter compound addition:\n";
    d1.showDistance();

    std::cout << "\nComparison results:\n";
    std::cout << "d1 > d2: " << (d1 > d2) << '\n';
    std::cout << "d1 < d2: " << (d1 < d2) << '\n';
    std::cout << "d1 >= d2: " << (d1 >= d2) << '\n';
    std::cout << "d1 <= d2: " << (d1 <= d2) << '\n';
    std::cout << "d1 == d2: " << (d1 == d2) << '\n';
    std::cout << "d1 != d2: " << (d1 != d2) << '\n';

    std::cout << "\nAfter increment and decrement:\n";
    ++d1;
    d1.showDistance();

    d1--;
    d1.showDistance();

    Distance d3 = ++d1;
    std::cout << "\nAfter pre-increment and assignment:\n";
    d3.showDistance();

    Distance d4 = d1--;
    std::cout << "\nAfter post-decrement and assignment:\n";
    d4.showDistance();

    return 0;
}
