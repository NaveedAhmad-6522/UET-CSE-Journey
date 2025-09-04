
#include<iostream>
using namespace std;l
class Node{
    public:
    int data;
    Node* next;
    Node(int val):data(val){
        next=NULL;
    }

};
int main(){
    Node* node1=new Node(3);
    cout<<node1->data<<" "<<node1->next;
    return 0;
}