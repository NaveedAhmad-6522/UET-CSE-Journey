#include <iostream>
int i;
int main() {
	
int x;
std::cin>>x;
if(x==1){
	exit(0);
}
    for (i = 1; i <= 10; i++) {
        if (i == 5) {
            std::cout << "Terminating the program." << std::endl;
            exit(5);
			int m;  // Exit the program when i is equal to 5
        }
        std::cout << "Iteration: " << i << std::endl;
        cin>>m;
    }

    std::cout << "This line will not be executed." << std::endl;
    

    return 0;
}

