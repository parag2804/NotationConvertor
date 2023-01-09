//Description: This is source file for the program which convert the notation. It can be prefix, infix, postfix

#include "NotationConverter.hpp"

bool isCharOperator(const char& c)                                                  //if char is a operator
{
    bool multiply = (c == '*');
    bool add = (c == '+');
    bool sub = (c == '-');
    bool divide = (c == '/');
    bool isOperator = (multiply || add || sub || divide);
    return isOperator;
}

bool isCharLetter(const char& c)                                                    //if char is a letter
{
    bool Lower = (c >= 'a' && c <= 'z');
    bool Upper= (c >= 'A' && c <= 'Z');
    bool Letter = (Lower || Upper);
    return Letter;
}

int orderOfOP(char op)                                                              //Return precedence of operator
{
    switch(op)
    {
        case '*':
            return 2;
            break;

        case '/':
            return 2;
            break;

        case '+':
            return 1;
            break;

        case '-':
            return 1;
            break;

        default:
            return 0;
    }
}

void NotationConverter::clear()
{
    while(!dq.clearDeque())
    {
        dq.removeFront();
    }
}

std::string NotationConverter::postfixToInfix(std::string inStr)
{
    std::string rtrn;
    for(auto c : inStr)                                                             //Loop to go through each char
    {
        if(c == ' ')
        {
            continue;
        }
        else if(isCharLetter(c))                                                    //when char is an letter
        {
            std::string tmpry = "";
            tmpry += c;
            dq.insertFront(tmpry);
        }
        else if(isCharOperator(c))                                                  //when char is an operator
        {
            std::string tmpry = "";
            tmpry += ')';
            tmpry += dq.front();
            dq.removeFront();
            tmpry += ' ';
            tmpry += c;
            tmpry += ' ';
            tmpry += dq.front();
            dq.removeFront();
            tmpry += '(';
            dq.insertFront(tmpry);
        }
        else
        {
            throw("Invalid String");                                                //if invalid, it will throw
        }
    }

    while(!dq.clearDeque())
    {
        rtrn += dq.front();
        dq.removeFront();
    }
    reverse(rtrn.begin(), rtrn.end());
    return rtrn;
}

std::string NotationConverter::postfixToPrefix(std::string inStr)
{
    std::string rtrn = "";
    std::string tmpry = "";
    tmpry = postfixToInfix(inStr);
    rtrn = infixToPrefix(tmpry);
    return rtrn;
}

std::string NotationConverter::infixToPostfix(std::string inStr)
{
    std::string rtrn;
    std::string endDeque = "end";
    dq.insertBack(endDeque);

    for(auto c : inStr)                                                             //checking every char in the input string
    {
        if (c == ' ')
        {
            continue;
        }
        else if(isCharLetter(c))                                                    //if char is letter
        {
            rtrn += c;
            rtrn += ' ';
        }
        else if (c == '(')
        {
            std::string tmpry = "";
            tmpry += c;
            dq.insertFront(tmpry);
        }
        else if(c == ')')
        {
            while(dq.front() != endDeque && dq.front() != "(")
            {
                std::string tmpry = "";
                tmpry = dq.front();
                dq.removeFront();
                rtrn += tmpry;
                rtrn += ' ';
            }
            if(dq.front() == "(")
            {                                                                        //when the front of the deque contains a (
                dq.removeFront();                                                    //ignore and remove it
            }
        }
        else if(isCharOperator(c))
        {                                                                             //if the char is a operator
            while(dq.front() != endDeque && orderOfOP(c) <= orderOfOP(dq.front().at(0)))
            {
                std::string tmpry = dq.front();
                dq.removeFront();
                rtrn += tmpry;                                                        //appending the front of the deque to the return string
                rtrn += ' ';
            }
            std::string stringInsert = "";
            stringInsert += c;                                                      //add the new operator to the front of the deque
            dq.insertFront(stringInsert);
        }
        else
        {
            throw("Invalid String");                                                //Invalid char in input string
        }
    }

    while(dq.front() != endDeque)
    {
        std::string tmpry = "";
        tmpry = dq.front();
        dq.removeFront();
        rtrn += tmpry;                                                               //append the front of the deque to return string until the deque is empty
        rtrn += ' ';
    }

    clear();                                                                         //clears the elements of the deque (including the end flag)
    if(rtrn.at(0) == ' ')                                                            //Gets rid of unecessary white space at beginning of string
        rtrn.erase(rtrn.begin());
    if(rtrn.back() == ' ')                                                          //Gets rid of unecssary whtie space at end of string
        rtrn.erase(rtrn.end() - 1);
    return rtrn;
}

std::string NotationConverter::infixToPrefix(std::string inStr)
{

    std::string rtrn = "";
    std::string tmpry = "";

    for(auto c : inStr)
    {
                                                                                    //append every char of input string to a temporary string
        tmpry += c;
    }

    for (unsigned int i = 0; i < tmpry.length(); i++)
    {
        if(tmpry.at(i) == '(')
        {
            tmpry.at(i) = ')';
        }
        else if (tmpry.at(i) == ')')
        {
            tmpry.at(i) = '(';
        }
    }

    reverse(tmpry.begin(), tmpry.end());
    rtrn = infixToPostfix(tmpry);
    reverse(rtrn.begin(), rtrn.end());

    clear();
    if(rtrn.at(0) == ' ')
        rtrn.erase(rtrn.begin());
    if(rtrn.back() == ' ')
        rtrn.erase(rtrn.end()-1);
    return rtrn;
}

std::string NotationConverter::prefixToInfix(std::string inStr)
{
    std::string rtrn;
    reverse(inStr.begin(), inStr.end());
    for(auto c : inStr)
    {
        if(c == ' ')
        {
            continue;
        }
        else if(isCharLetter(c))                                                              //when char is operand
        {
            std::string tmpry = "";
            tmpry += c;                                                                         //insert operand to the back of the deque
            dq.insertBack(tmpry);
        }
        else if (isCharOperator(c))                                                             //when char is operator
        {
            std::string tmpry = "";
            tmpry += '(';
            tmpry += dq.back();
            dq.removeBack();
            tmpry += ' ';
            tmpry += c;
            tmpry += ' ';
            tmpry += dq.back();
            dq.removeBack();
            tmpry += ')';
            dq.insertBack(tmpry);                                                               //insert the new string created back into the deque
        }
        else
        {
            throw("Invalid String");
        }
    }
    while(!dq.clearDeque())
    { //until the deque is empty
        rtrn += dq.back(); //appending the back of the deque to to the return string
        dq.removeBack();
    }

    return rtrn;
}

std::string NotationConverter::prefixToPostfix(std::string inStr)
{
    std::string rtrn = "";
    std::string tmpry = "";
    tmpry = prefixToInfix(inStr); //prefix -> infix
    rtrn = infixToPostfix(tmpry); //infix -> postfix
    return rtrn;
}
