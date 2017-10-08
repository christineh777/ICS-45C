
#ifndef Picture_h
#define Picture_h

#include "Shape.h"

class Picture
{
private:
    struct LinkedListNode
    {
        Shape* data;
        LinkedListNode* next;
        LinkedListNode(Shape* sp,LinkedListNode* n=NULL)
        {
            data=sp;
            next=n;
        }
    };
    LinkedListNode* head;
public:
    Picture()
    {
        head=NULL;
    }
    void add(Shape* sp)
    {
        head=new LinkedListNode(sp,head);
    }
    double totalArea()
    {
        double result=0;
        LinkedListNode* temp=head;
        while(temp)
        {
            result+=temp->data->area();
            temp=temp->next;
        }
        return result;
    }
    void drawAll()
    {
        LinkedListNode* temp=head;
        while(temp)
        {
            temp->data->draw();
            temp=temp->next;
        }
    }
    ~Picture()
    {
        while(head)
        {
            LinkedListNode* temp=head->next;
            delete head;
            head=temp;
        }
    }
    
};

#endif /* Picture_h */
