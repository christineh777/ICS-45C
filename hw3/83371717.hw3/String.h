#include<iostream>
using namespace std;
#define MAXLEN 128
class String
{
public:
    String( const char * s = "")
    {
        int i = 0;
        for (i=0; s[i] != '\0'; i++) {
            buf[i]=s[i];
        }
        buf[i]='\0';
    }
    String( const String & s )
    {
        int i = 0;
        for (i=0; s.buf[i] != '\0'; i++) {
            buf[i]=s.buf[i];
        }
        buf[i]='\0';
    }
    String operator = (const String & s )
    {
        int i = 0;
        for (i=0; s.buf[i] != '\0'; i++) {
            buf[i]=s.buf[i];
        }
        buf[i]='\0';
        return s.buf;
    }
    char & operator [] ( int index )
    {
        return buf[index];
    }
    int size()
    {
        return strlen(buf);
    }
    String reverse()
    {
        String a=buf;
        int index = 0;
        for (index = strlen(buf)-1; index >= 0; index--) {
            a.buf[strlen(buf)-index-1]=buf[index];
        }
        a[strlen(buf)-index-1]='\0';
        return a;
    }
    int indexOf( const char c ){
        for (int i = 0; buf[i]!='\0'; i++) {
            if (c==buf[i]) {
                return i;
            }
        }
        return -1;
    }
    int indexOf( String pattern ){
        for (int i = 0; pattern.buf[i]!='\0'; i++) {
            String str=pattern;
            for (int j = 0; pattern.buf[j]!='\0'; j++) {
                str.buf[j]=buf[i+j];
            }
            if (str==pattern) {
                return i;
            }
        }
        return -1;
    }
    bool operator == ( const String s ){
        int i = 0;
        for (i=0; buf[i]!='\0'; i++) {
            if (buf[i]!=s.buf[i]) {
                return false;
            }
        }
        return strlen(s.buf)==strlen(buf);
    }
    bool operator != ( const String s ){
        String slf = buf;
        return not (slf == s);
    }
    bool operator > ( const String s ){
        for (int i = 0; buf[i]!='\0'; i++) {
            if (buf[i]>s.buf[i]) {
                return true;
            }
            if (buf[i]<s.buf[i]){
                return false;
            }
        }
        return false;
    }
    bool operator < ( const String s ){
        String slf = buf;
        return slf != s && not(slf > s);
    }
    bool operator <= ( const String s ){
        String slf = buf;
        return !(slf>s);
    }
    bool operator >= ( const String s ){
        String slf = buf;
        return !(slf<s);
    }
    /// concatenates this and s to return result
    String operator + ( const String s ){
        String slf = buf;
        int i = 0;
        int len = slf.size();
        for (i=0; s.buf[i]!='\0'; i++) {
            slf.buf[len+i]=s.buf[i];
        }
        slf.buf[len+i]='\0';
        return slf;
    }
    /// concatenates s onto end of this string
    String operator += ( const String s ){
        int len =strlen(buf);
        for (int i = 0; i<=strlen(s.buf); i++) {
            buf[i+len]=s.buf[i];
        }
        String newstr=buf;
        return newstr;
    }
    void print( ostream & out ){
        out<<buf;
    }
    void read( istream & in ){
        in>>buf;
    }
    ~String(){
        
    }
private:
    bool inBounds( int i )
    {
        return i >= 0 && i < strlen(buf);
    }
    static int strlen( const char *s )
    {
        int i = 0;
        while(*s)
        {
            s++;i++;
        }
        return i;
    }
    char buf[MAXLEN];
};
ostream & operator << ( ostream & out, String & str)
    {
        str.print(out);
        return out;
    }
istream & operator >> ( istream & in, String & str )
    {
        str.read(in);
        return in;
    }

