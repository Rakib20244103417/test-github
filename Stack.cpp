#include <iostream>
using namespace std;
int MAXSIZE = 8;
int stack[8];
int top = -1;
int isempty(){
   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull(){
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek(){
   return stack[top];
}

int pop(){
   int data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;
      return data;
   }
   else
      cout<<"It's unable to insert data due to full stack"<<endl;
}

int push(int data){
   if(!isfull()) {
      top = top + 1;
      stack[top] = data;
   } else
      cout << "Could not insert data, Stack is full." << endl;
}

int main(){
   push(4);
   push(10);
   push(12);
   push(30);
   push(25);
   cout << "Element at top of the stack: " << peek() << endl;
   printf("Elements: \n");
   // print stack data
   while(!isempty()) {
      int data = pop();
      cout << data <<endl;
   }
   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   return 0;
}
