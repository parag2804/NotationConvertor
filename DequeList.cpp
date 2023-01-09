//Description: This is source file for the DequeList

#include "DequeList.hpp"

DequeList::DequeList()                                                          //Constructor
{
    head = new DequeListNode;
    tail = new DequeListNode;
    head->next = tail;
    tail->prev = head;
    size = 0;                                                                   //initial size is 0
}

DequeList::~DequeList()                                                         //Destructor
{
    while(!emptyList())
    {
        removeFront();                                                          //Call removeFront() until the list is empty
    }
    delete tail;
    delete head;
}

void DequeList::emptyAdd(DequeListNode* newData)                                //adding new node to an empty linkedList
{
    head->next = newData;
    newData->prev = head;
    newData->next = tail;
    tail->prev = newData;
}

void DequeList::addFront(const std::string& data)                               //adding new node to the front
{
    DequeListNode* newData = new DequeListNode;
    newData->data = data;

    if(emptyList())
    {
        emptyAdd(newData);                                                      //Call function if list is empty
    }

    else
    {
        auto newNode = head->next;
        head->next = newData;
        newData->prev = head;
        newData->next = newNode;
        newNode->prev = newData;
    }
}

void DequeList::addBack(const std::string& data)                                 //adding new node to the back
{
    DequeListNode* newData = new DequeListNode;
    newData->data = data;
    if(emptyList())
    {
        emptyAdd(newData);                                                       //Call function if the list is empty
    }
    else
    {
        auto oldNode = tail->prev;
        tail->prev = newData;
        newData->next = tail;
        newData->prev = oldNode;
        oldNode->next = newData;
    }
}

void DequeList::removeFront()                                                    //removing node from the front
{
    if(emptyList())
        throw("EmptyList");                                                     //Cannot remove from empty list

    auto nodeRemove = head->next;
    auto newNode = nodeRemove->next;
    head->next = newNode;
    newNode->prev = head;

    delete nodeRemove;
    size--;                                                                     //decrement size
}

void DequeList::removeBack()
{
    if(emptyList())
        throw("EmptyList");                                                     //Cannot remove from empty list

    auto nodeRemove = tail->prev;
    auto oldNode = nodeRemove->prev;
    tail->prev = oldNode;
    oldNode->next = tail;

    delete nodeRemove;
    size--;                                                                     //decrement size
}
