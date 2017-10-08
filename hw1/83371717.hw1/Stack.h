#define STACK_CAPACITY 1000
class Stack
{
public:
char astack[1000];
Stack()
{
}
void push(char c)
{
for(int i = 999; i >0; i--)
astack[i]=astack[i-1];
astack[0]=c;
}
char pop()
{
char item = astack[0];
for(int i=0;i<999;i++)
astack[i]=astack[i+1];
return item;
}
char top()
{
return astack[0];
}
bool isEmpty()
{
if(sizeof(astack)==0)
{
return 1;
}
else
{
return 0;
}
}
bool isFull()
{
if(sizeof(astack)/sizeof(astack[0])==1000)
{
return 1;
}
else
{
return 0;
}
}
~Stack()
{
}
};
