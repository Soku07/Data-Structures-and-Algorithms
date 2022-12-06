
#include<iostream>
using namespace std;

class stackExpression
{
    struct node
    {
        char data;
        node* next;
    }*top;
public:
    stackExpression()
    { top = NULL; }
    void push(char);
    void pop();
    bool isEmpty();
    char tp();
};

void stackExpression::push(char x)
{
    node* newnode = new node;
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void stackExpression::pop()
{
    node* temp = top;
    top = top->next;
    free(temp);
}

bool stackExpression::isEmpty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

char stackExpression::tp()
{
    return top->data;
}

int prec(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string s)
{
    /*
    1. Add operands as they arrive
    2. If stack is empty or contains '(', push the incoming character
    3. If incoming char is '(', push it onto the stack
    4. If incoming char is ')', pop the stack until a '(' is encountered
    5. If incoming char has higher precedence, push it onto the top of the stack
    6. If incoming char has lower precedence, pop the top and then test the char with the new top
    7. If incoming char has same precedence, pop the top then test for operators other than '^'
    8. For '^', push the operator on top of the stack
    9. At the end, pop the entire stack into result
    */
    stackExpression st;
    string res = "";
    for(int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) // rule 1
            res += ch;
        else if(ch == '(') // rule 3
            st.push('(');
        else if(ch == ')') // rule 4
        {
            while(st.tp() != ')')
            {
                res += st.tp();
                st.pop();
            }
            st.pop();
        }
        else // ch is an operator and rules 5-8
        {
            while(st.isEmpty() == false && (prec(s[i]) <= prec(st.tp())))
            {
                res += st.tp();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(st.isEmpty() == false) // rule 9
    {
        res += st.tp();
        st.pop();
    }
    cout << "The converted string to postfix from prefix is:\n";
    cout << res;
}

int main()
{
    string infixExp;
    cout << "Enter infix expression:\n";
    cin >> infixExp;
    infixToPostfix(infixExp);
    return 0;
}