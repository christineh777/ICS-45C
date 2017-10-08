#ifndef SetList_h
#define SetList_h

#include <iterator>
using namespace std;
template <typename T>
struct ListNode
{
    T info;
    ListNode* next;
    ListNode(T newinfo,ListNode* n=nullptr):info(newinfo),next(n){};
};
    
template <typename nT>
class SetList
{
    ListNode<nT>* head;
public:
    SetList():head(nullptr){};
    void insert(nT t)
    {
        head=new ListNode<nT>(t,nullptr);
    }
    class Iterator
    {
        typedef forward_iterator_tag iterator_category;
        typedef Iterator self_type;
        typedef ListNode<nT> value_type;
        typedef ListNode<nT>& reference;
        typedef ListNode<nT>* pointer;
        typedef ptrdiff_t difference_type;
    private:
        pointer ibuf;
    public:
        Iterator(pointer ptr):ibuf(ptr){};
        self_type operator++(){ibuf=ibuf->next; return *this;}
        self_type operator++(int ps){self_type cpy=*this;ibuf=ibuf->next;return cpy;}
        reference operator*(){return *ibuf;}
        pointer operator->(){return ibuf;}
        bool operator==(const self_type& rhs)const {return ibuf==rhs.ibuf;}
        bool operator!=(const self_type& rhs)const {return ibuf!=rhs.ibuf;}
    };
    Iterator find(nT t)
    {
        ListNode<nT>* o=head;
        while(o)
        {
            if(o->info==t)
                return Iterator(o);
            else
                o=o->next;
        }
        return Iterator(NULL);
    }

    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(NULL);
    }
    ~SetList()
    {
        while(head!=nullptr)
        {
            ListNode<nT>* t=head->next;
            delete head;
            head=t;
        }
    }
    
};

















#endif /* SetList_h */
