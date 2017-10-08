#include<iostream>
using namespace std;
class String
{
public:
    String( const char * s = "")
    {
        buf=strdup(s);
    }
    String( const String & s )
    {
        buf=strdup(s.buf);
    }
    String operator = (const String & s )
    {
        delete_char_array(buf);
        buf=strdup(s.buf);
        return String(buf);
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
        String a(buf);
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
        String ns(buf);
        ns+=s;
        return ns;
    }
    /// concatenates s onto end of this string
    String& operator += ( const String s ){
        char* ns=new_char_array(strlen(buf)+strlen(s.buf)+1);
        strcpy(ns,buf);
        delete_char_array(buf);
        strcat(ns,s.buf);
        buf=ns;
        return *this;
        
    }
    void print( ostream & out )const {
        out<<buf;
    }
    void read( istream & in ){
        in>>buf;
    }
    ~String(){
        delete_char_array(buf);
    }
    static void final_report_on_allocations()
    {
        if (allocations > 0) error("Memory Leak in class String");
        if (allocations < 0) error("Too many delete[]s in class String");
        if (allocations == 0)
            cout << "Allocations & deallocations match\n";
    }
    static int allocations;

private:
    static char * new_char_array( int n_bytes )
    {
        allocations++;
        return new char[n_bytes];
    }
    static void delete_char_array( char * p )
    {
        --allocations;
        if (allocations < 0) error("more delete[] than new[]");
        delete [] p;
    }
    static void error( const char * p )
    {
        cerr << "Error (class String): " << p << endl;
    }
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
    static char * strcpy( char *dest, const char *src )
    {
        int i=0;
        for (i=0; src[i] != '\0'; i++) {
            dest[i]=src[i];
        }
        dest[i+1]='\0';
        return dest;
    }
    static char* strdup(const char* src)
    {
        char* ns=new_char_array(strlen(src)+1);
        strcpy(ns,src);
        return ns;
    }
    
    static char * strcat(char *dest, const char *src)
    {
        int len =strlen(dest);
        for (int i = 0; i<=strlen(dest); i++) {
            dest[i+len]=src[i];
        }
        return dest;
    }

    char* buf;
};





ostream & operator << ( ostream & out, const String & str)
    {
        str.print(out);
        return out;
    }
istream & operator >> ( istream & in, String & str )
    {
        str.read(in);
        return in;
    }

