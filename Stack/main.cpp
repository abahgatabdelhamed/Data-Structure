#include <iostream>
#include<string>
#include<cmath>
#include<stack>
using namespace std;

//implemenation  of stack
template<class T>
class Stack {
private :
    struct node{
        T val ;
        node * next;
    };
    node *top ;
public :
    Stack(){
    top = NULL;
    }
    void push(T newVal)
    {
        node * newNode = new node;
     if(newNode == NULL)
        cout<<"Stack cant Add More Element" ;
     else{
        newNode->val = newVal ;
        newNode->next = top ;
        top = newNode;
     }

    }
    void show(){


    }

    bool isEmpty(){
        return top == NULL ;
    }
    void pop(){
    if(isEmpty())
        cout<<"Stack is Empty ";
    else
    {
        node * temp =  top ;
        top = top->next ;
        temp = temp->next = NULL;
        delete(temp) ;
    }

    }

    void pop(T &StackTop){

    if(isEmpty())
        cout<<"Stack is Empty ";
    else
    {
        StackTop = top->val ;
        node * temp =  top ;
        top = top->next ;
    temp->next = NULL;
        delete(temp) ;
    }

    }

    void display()
    {
        node *current ;
        current = top ;
        while(current != NULL)
        {
            cout<<current->val<<endl ;
            current=current->next;
        }
    }
};


bool isPared(char open , char close)
{
   return open == '[' && close == ']' || open == '{' && close == '}' ||open == '(' && close == ')' ;
}

bool isBalanced(string exp) //{(}
{
    stack<char> s ;
    for(int i = 0; i< exp.length() ; i++)
    {
        if(exp[i] == '[' || exp[i] == '(' || exp[i] == '{' )
            s.push(exp[i]);
        else if(exp[i] == ']' || exp[i] == ')' || exp[i] == '}' )
        {
        if(s.empty() || !isPared(s.top() , exp[i]))
            return false ;
        else{
            s.pop();
        }
        }

    }
    return s.empty();
}



// infix to postfix
bool isPer(char op1 , char op2  )
{
    if(op1 == '^')
        return true ;
    else if(op1 == '*'|| op1 =='/' && op2 != '^'){
            return true;
    }
     else if ((op1 == '+' || op1 == '-') && (op2 != '*' && op2 != '/' && op2 != '^')) {  // Proper precedence logic
        return true;
    }
    return false;
}
bool IsOperand(char C)
{
	if (C >= '0' && C <= '9') return true;
	if (C >= 'a' && C <= 'z') return true;
	if (C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOperator(char C)
{
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '$')
		return true;

	return false;
}

string InfixToPostfix(string exp)
{
    string postfix = "" ;
    stack<char>s ;
    for(int i=0 ; i <= exp.length() ; i++) //"8/2+7-4*2"
    {
        if(IsOperand(exp[i]))
            postfix += exp[i];
        else{
                if(s.empty())
                {
                    s.push(exp[i]);
                }else
                {
                    if(isPer(s.top(),exp[i]))
                    {
                        postfix+=s.top();
                        s.pop();
                        s.push(exp[i]);
                    }
                    else
                        s.push(exp[i]);
                }
            }


    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
   /** Stack <int> s;
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(35);
    int y = 0;
    s.pop(y);
    cout<<"Deleted node =>"<<y<<endl;
    s.display(); **/



    cout<<isPer('-','*')<<endl;
    cout<<InfixToPostfix("8/2+7-4*2");
}





