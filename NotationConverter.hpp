//Description: This is header file for the program which convert the notation. It can be prefix, infix, postfix


#include <algorithm>                                                //To reverse a string
#include "NotationConverterInterface.hpp"
#include "DequeList.hpp"
#include "LinkedDeque.hpp"

class NotationConverter : public NotationConverterInterface
{
    public:
        NotationConverter() = default;
        ~NotationConverter() = default;
        void clear();                                               //helper function to clear the entire deque

        std::string postfixToInfix(std::string inStr);              //postfix conversion functions
        std::string postfixToPrefix(std::string inStr);
        std::string infixToPostfix(std::string inStr);              //infix conversion functions
        std::string infixToPrefix(std::string inStr);
        std::string prefixToInfix(std::string inStr);               //prefix conversion functions
        std::string prefixToPostfix(std::string inStr);

    private:
        LinkedDeque dq;                                             //Deque that we use to convert between notations
};
