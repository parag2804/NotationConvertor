//Description: This is source file for the LinkedDeque

#include "LinkedDeque.hpp"

LinkedDeque::LinkedDeque()                                                          //Constructor
{
    size = 0;                                                                       //set initial size to 0
}

std::string LinkedDeque::front()
{
    if(clearDeque())
        throw("Empty Deque");
    return list.front();                                                            //Uses list to retrieve first element
}

std::string LinkedDeque::back()
{
    if(clearDeque())
        throw("Empty Deque");
    return list.back();                                                             //Uses list to retrieve the last element
}

void LinkedDeque::insertFront(const std::string& data)
{
    list.addFront(data);                                                            //uses list to insert the new element
    size++;
}

void LinkedDeque::insertBack(const std::string& data)
{
    list.addBack(data);                                                             //uses list to insert the new element
    size++;
}

void LinkedDeque::removeFront()
{
    if(clearDeque())
        throw("Empty Deque");
    list.removeFront();                                                             //uses list to remove first element
    size--;
}

void LinkedDeque::removeBack()
{
    if(clearDeque())
        throw("Empty Deque");
    list.removeBack();                                                              //uses list to remove last element
    size--;
}
