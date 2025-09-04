#include <iostream>
#include <string>
using namespace std;
int main() {
    std::string string1 = "784";
    std::string string3="789";

    string3.swap(string1);

    std::cout << "string3: " << string3.size() << std::endl;
     std::cout << "string1: " << string1 << std::endl;

    return 0;
}


