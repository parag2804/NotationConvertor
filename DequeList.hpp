//Description: This is header file for the DequeList

#ifndef DEQUELIST_HPP
#define DEQUELIST_HPP
#include <string>

class DequeListNode
{
    public:
        DequeListNode() = default;                                          //default constructor
        ~DequeListNode() = default;                                         //default destructor

    private:
        std::string data;                                                   //data that the node will hold
        DequeListNode* prev;
        DequeListNode* next;

    friend class DequeList;                                                 //allow friend class access to DequeList
};

class DequeList
{
    public:
        DequeList();
        ~DequeList();
        std::string front() const
        {
            return head->next->data;                                        //returning the string of first element
        }
        std::string back() const
        {
            return tail->prev->data;                                        //returning the string of first element
        }
        void emptyAdd(DequeListNode* newData);                              //Function to add a new element to an empty list
        bool emptyList()
        {
            return (head->next == tail);                                    //checks if the list is empty
        }

        void addFront(const std::string& data);
        void addBack(const std::string& data);
        void removeFront();
        void removeBack();

    private:
        unsigned int size;                                                  //see the size of linedlist at current time
        DequeListNode* head;
        DequeListNode* tail;
};

#endif                                                                      //DEQUELIST_HPP
