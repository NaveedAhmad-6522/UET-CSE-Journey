#include <iostream>
using namespace std;

/*A point on a two-dimensional space has two numbers: an ‘X’ coordinate and a ‘Y’ 
coordinate such as (4, 5). Write a program that uses a structure called ‘point’ to model a 
point and draw a rectangle of ‘*’ based on the entered height and width of the rectangle.
Sample Run:
Enter the point coordinates: (x, y)
3 2
Enter width of the rectangle: 3
Enter Height of the rectangle: 2
* * *
* * *
*/



struct point{
	int x;
	int y;
};

void draw(int width,int height){
	 for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }


}
main(){
point rec;
cout<<"x coordinate: \n"	;
cin>>rec.x;
cout<<"y coordinate \n";
cin>>rec.y;
int height,width;
cout << "Enter the width of the rectangle: ";
    cin >> width;
    cout << "Enter the height of the rectangle: ";
    cin >> height;
    draw(height,width);
	
}
