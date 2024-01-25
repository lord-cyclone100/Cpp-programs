#include <iostream>
using namespace std;
#define MAX 20

class infixtopostfix{
    private:
        int front;
        char a[MAX];
    public:
        infixtopostfix(){
            front = -1;
        }
        void push(char value){
            if(front>MAX - 1){
                cout<<"Stack overflow";
                return;
            }
            front++;
            a[front] = value;
            return;
        }

        void pop(){
            if(front < 0){
                cout<<"stack underflow";
                return;
            }
            front--;
            return;
        }

        char peek(){
            if(front < 0){
                cout<<"stack underflow";
                return;
            }
            return a[front];
        }

        int is_empty(){
            return front == -1;
        }
};

int precedence(char c){
    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else{
        return 0;
    }
}

int is_operator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

int is_operand(char c){
    if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
        return 1;
    }
    else{
        return 0;
    }
}

void infix_to_postfix(char infix[], char postfix[]){
    infixtopostfix p;
    int i = 0;
    int j = 0;
    while(infix[i] != '\0'){
        if(is_operand(infix[i])){
            postfix[j] = infix[i];
            j++;
        }
        else if(infix[i] == '('){
            p.push(infix[i]);
        }
        else if(infix[i] == ')'){
            while(p.peek() != '('){
                postfix[j] = p.peek();
                j++;
                p.pop();
            }
            p.pop();
        }
        else if(is_operator(infix[i])){
            while(!p.is_empty() && p.peek() != '(' && precedence(infix[i])<=precedence(p.peek())){
                postfix[j] = p.peek();
                j++;
                p.pop();
            }
            p.push(infix[i]);
        }
        else{
            cout<<"Invalid string";
            return;
        }
        i++;
    }
    while(!p.is_empty()){
        postfix[j] = p.peek();
        p.pop();
        j++;
    }
    postfix[j] = '\0';
}

int postfix_eval(char postfix[]){
    infixtopostfix p;
    int i = 0;
    int result;
    while(postfix[i] != '\0'){
        if(is_operand(postfix[i])){
            p.push(postfix[i]);
        }
        else if(is_operator(postfix[i])){
            char op2 = p.peek();
            p.pop();
            char op1 = p.peek();
            p.pop();
            switch(postfix[i]){
                case '+':
                    result = (op1 - '0') + (op2 - '0');
                    break;
                case '-':
                    result = (op1 - '0') - (op2 - '0');
                    break;
                case '*':
                    result = (op1 - '0') * (op2 - '0');
                    break;
                case '/':
                    result = (op1 - '0') / (op2 - '0');
                    break;
            }
            p.push(result + '0');
        }
        i++;
    }
    return (result);
}

int main(){
    char infix[MAX],postfix[MAX];

    cout<<"Enter infix string:";
    cin>>infix;

    infix_to_postfix(infix,postfix);
    cout<<"Postfix string:"<<postfix<<endl;
    int result = postfix_eval(postfix);
    cout<<"Postfix evaluation result:"<<result;

    return 0;
}
