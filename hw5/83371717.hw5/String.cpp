#include "String.h"

String::ListNode* String::ListNode::stringToList(const char* s)
{
    if(s==NULL || s[0]=='\0')return NULL;
    return new String::ListNode(s[0],stringToList(s+1));
}

String::ListNode* String::ListNode::copy(String::ListNode* L)
{
    if(L==NULL)return NULL;
    return new String::ListNode(L->info,copy(L->next));
}

bool String::ListNode::equal(String::ListNode* L1, String::ListNode* L2)
{
    if(L1==NULL && L2==NULL)return true;
    if(L1==NULL || L2==NULL)return false;
    if(L1->info==L2->info)return equal(L1->next,L2->next);
    return false;
}

String::ListNode* String::ListNode::concat(String::ListNode* L1,String::ListNode* L2)
{
    String::ListNode* templ=copy(L1);
    String::ListNode* temp=templ;
    while(templ->next!=NULL)
        templ=templ->next;
    templ->next=copy(L2);
    return temp;
}


int String::ListNode::compare(String::ListNode* L1, String::ListNode* L2)
{
    if(L1==NULL && L2==NULL)return 0;
    if(L1==NULL)return -L2->info;
    if(L2==NULL)return L1->info;
    if(L1->info==L2->info)return compare(L1->next,L2->next);
    return L1->info-L2->info;
}

void String::ListNode::deleteList(String::ListNode* L)
{
    if ( L != NULL )
    {
        deleteList( L->next );
        L = L->next;
    }

}

int String::ListNode::length(String::ListNode* L)
{
    if(L==NULL)
        return 0;
    return length(L->next)+1;
}

String::String( const char * s)
{
    head = ListNode::stringToList(s);
}

String::String( const String & s )
{
    head = String::ListNode::copy(s.head);
}

String String::operator = (const String & s)
{
    head = String::ListNode::copy(s.head);
    return *this;
}

char & String:: operator [] (const int index)
{
    if(index>=this->length())
    {
        char s = NULL;
        return s;
    }
    String::ListNode* temp=head;
    int current = 0;
    while(current != index)
    {
        temp = temp->next;
        current++;
    }
    return temp->info;
}

int String::length() const
{
    return String::ListNode::length(head);
}

int String::indexOf(char c) const
{
    int index = 0;
    String::String::ListNode * temp = head;
    while(temp)
    {
        if(temp->info==c)
            return index;
        temp=temp->next;
        index++;
    }
    return -1;
}

bool String::operator==(const String &s) const
{
    return String::ListNode::equal(head, s.head);
}

bool String::operator<(const String &s)const
{
    return String::ListNode::compare(head, s.head)<0;
}

String String::operator+(const String &s)const
{
    String temp;
    temp.head=String::ListNode::concat(head, s.head);
    return temp;
}

String String::operator+=(const String &s)
{
    head=String::ListNode::concat(head, s.head);
    return *this;
}

String String::reverse()
{
    char s[this->length()];
    int index = 0;
    for (index = this->length()-1; index >= 0; index--) {
        s[index]=(*this)[this->length()-index-1];
    }
    String temp(s);
    return temp;
}

void String::print( ostream & out )
{
    String::ListNode* temp=head;
    while(temp)
    {
        cout<<temp->info;
        temp=temp->next;
    }
}
void String::read( istream & in )
{
    char s[256];
    in>>s;
    head = String::ListNode::stringToList(s);
}
String::~String()
{
    String::ListNode::deleteList(head);
}

ostream & operator << ( ostream & out, String str)
{
    str.print(out);
    return out;
}
istream & operator >> ( istream & in, String & str )
{
    str.read(in);
    return in;
}
