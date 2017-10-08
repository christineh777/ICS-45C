#ifndef MapArray_h
#define MapArray_h
#include <algorithm>
#include <iterator>
#include <map>
#include <iostream>
using namespace std;
template<typename T1,typename T2>
class MapArray
{
    pair<T1,T2>* m;
    int c;
public:
    MapArray():c(0),m(nullptr){};
    pair<T1,T2>& insert(const pair<T1,T2>& t)
    {
        c++;
        pair<T1,T2>* t1=m;
        m=new pair<T1,T2>[c];
        int i;
        for(i=0;i<c-1;i++)
        {
            if(t1[i].first<t.first)
                m[i]=t1[i];
            else
                break;
        }
        m[i]=t;
        for(i=i+1;i<c;i++)
        {
            m[i]=t1[i-1];
        }
        delete[] t1;
        return m[c-1];
        
    }
    T2& operator[](T1 t)
    {
        for(int i=0;i<c;i++)
        {
            if(m[i].first==t)
                return m[i].second;
        }
        return insert(make_pair(t,0)).second;
    }
    
    
    class Iterator
    {
        typedef random_access_iterator_tag iterator_category;
        typedef Iterator self_type;
        typedef pair<T1,T2> value_type;
        typedef pair<T1,T2>& reference;
        typedef pair<T1,T2>* pointer;
        //typedef ptrdiff_t difference_type;
    private:
        pointer ibuf;
    public:
        Iterator(pointer ptr):ibuf(ptr){};
        self_type operator++(){++ibuf; return *this;}
        self_type operator++(int ps){self_type cpy=*this;ibuf++;return cpy;}
        self_type operator--(){--ibuf;return *this;}
        self_type operator--(int ps){self_type cpy=*this;ibuf--;return cpy;}
        self_type operator-(int p){ibuf-=p;return *this;}
        self_type operator+(int p){ibuf+=p;return *this;}
        bool operator<(const self_type& rhs)const{return ibuf<rhs.ibuf;}
        reference operator*(){return *ibuf;}
        pointer operator->(){return ibuf;}
        bool operator==(const self_type& rhs)const {return ibuf==rhs.ibuf;}
        bool operator!=(const self_type& rhs)const {return ibuf!=rhs.ibuf;}
    };
    Iterator begin()
    {
        return Iterator(m);
    }
    Iterator end()
    {
        return Iterator(m+c);
    }
    ~MapArray()
    {
        if(m)
            delete[] m;
    }
};




#endif /* MapArray_h */
