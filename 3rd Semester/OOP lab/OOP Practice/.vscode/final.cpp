#include "iset.h"

int main() {
    iset S = 1000, T, U = S;

    if (!T)
        cout << "T is empty.\n";

    if (int(U))
        cout << "U is not empty.\n";

    S += 100;
    S += 10000;
    (((S += 10) += 1) += 20) += 200;

    cout << "There are " << int(S) << " elements in S\n";

    T += 50;
    T += 50;

    cout << "S : ";
    S.print();
    S -= 1000;
    cout << "1000 removed from S\n";

    if (S(1000))
        cout << "1000 belongs to S (error)\n";
    else
        cout << "1000 is no longer in S\n";

    if (S(100))
        cout << "100 still belongs to S\n";

    cout << "S : ";
    S.print();
    cout << "T : ";
    T.print();
    cout << "U : ";
    U.print();

    T = S;
    cout << "After assigning S to T, we have T : ";
    T.print();

    return 0;
}