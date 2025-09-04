#include <iostream>
#include <string>
using namespace std;

string Reverse(string str) {
    if (str.empty() || str.length() == 1)
        return str;
   else
        return str.back() + Reverse(str.substr(0, str.length() - 1));
}

int main() {
    cout << Reverse("program") << endl;
    return 0;
}
