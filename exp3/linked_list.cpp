# include <iostream>
# include <sys/time.h>
using namespace std;
template <typename T>
class Node
{
public:
T data;
Node <T> * next;
Node(T data)
{
this->data=data;
this->next=NULL;
}
};
template <typename T>
class LinkedList
{
private:
Node <T> * head;
Node <T> * tail;
int size;
public:
LinkedList()
{
head=NULL;
tail=NULL;
size=0;
}
void insert(T data)
{
Node <T> * currNode=new Node <T> (data);
size++;
// Linked list is empty
if (head==NULL)
{
head=currNode;
tail=currNode;
}
else
{
tail->next=currNode;
tail=currNode;
}
}
void print()
{
Node <T> * temp=head;while (temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<endl;
}
int getSize()
{
return size;
}
int findElement(T data)
{
Node <int> * temp=head;
int count=-1;
while (temp!=NULL)
{
count++;
if (temp->data==data)
{
return count;
}
temp=temp->next;
}
return -1;
}
void insertAtPos(T data,int pos)
{
Node <int> * currNode=new Node <int> (data);
size++;
if (pos==0)
{
currNode->next=head;
head=currNode;
}
else
{
Node <int> * temp=head;
int count=-1;
while (temp!=NULL && count!=pos-1)
{
count++;
temp=temp->next;
}
currNode->next=temp->next;
temp->next=currNode;
}
}void deleteAtPos(int pos)
{
if (pos>=size)
{
return;
}
size--;
if (pos==0)
{
Node <int> * temp=head;
head=temp->next;
delete temp;
}
else
{
Node <int> * temp=head;
int count=0;
while (temp!=NULL && count!=pos-1)
{
temp=temp->next;
count++;
}
Node <int> * toDelete=temp->next;
Node <int> * nextNode=toDelete->next;
if (nextNode==NULL)
{
delete nextNode;
temp->next=NULL;
}
else
{
toDelete->next=NULL;
temp->next=nextNode;
delete toDelete;
}
}
}
};
long getTimeInMicroSeconds()
{
struct timeval start;
gettimeofday(&start,NULL);
return start.tv_sec*1000000+start.tv_usec;
}
int main(int argc, char const *argv[])
{int data,pos,choice,ans;
LinkedList <int> ll;
long startTime,endTime;
cout<<"Enter data in LinkedList:"<<endl;
cin>>data;
float space;
while(data!=-1)
{
ll.insert(data);
cin>>data;
}
cout<<"Linked List operations:"<<endl;
cout<<"1:PRINT"<<endl;
cout<<"2:INSERT AT SOME POSITION:"<<endl;
cout<<"3:FIND ELEMENT"<<endl;
cout<<"4:GET SIZE"<<endl;
cout<<"5:DELETE AT SOME POSITION"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>choice;
space=4*ll.getSize()+32;
switch(choice)
{
case 1:
startTime=getTimeInMicroSeconds();
ll.print();
endTime=getTimeInMicroSeconds();
cout<<"Time taken for execution is:"<<endTime-startTime<<"microseconds"<<endl;
cout<<"Space Complexity is:"<<(1.0)*space/ll.getSize()<<"bytes"<<endl;
break;
case 2:
cout<<"Enter data:"<<endl;
cin>>data;
cout<<"Enter the position:"<<endl;
cin>>pos;
startTime=getTimeInMicroSeconds();
ll.insertAtPos(pos,data);
endTime=getTimeInMicroSeconds();
cout<<"Time taken for execution is:"<<endTime-startTime<<"microseconds"<<endl;
cout<<"Space Complexity is:"<<(1.0)*(space+8)/ll.getSize()<<"bytes"<<endl;
break;
case 3:
cout<<"Enter data of element to find"<<endl;
cin>>data;
startTime=getTimeInMicroSeconds();
ans=ll.findElement(data);
endTime=getTimeInMicroSeconds();
cout<<"Space Complexity is:"<<(1.0)*(space+4)/ll.getSize()<<endl;
if (ans)
cout<<"ELement found at:"<<ans<<" th index"<<endl;
else
cout<<"Element not found"<<endl;
cout<<"Time taken for execution is:"<<endTime-startTime<<"microseconds"<<endl;
cout<<"Space Complexity is:"<<(1.0)*(space+4)/ll.getSize()<<"bytes"<<endl;
break;
case 4:
startTime=getTimeInMicroSeconds();
cout<<"Size of Linked List is"<<ll.getSize()<<endl;
endTime=getTimeInMicroSeconds();
cout<<"Time taken for execution is:"<<endTime-startTime<<"microseconds"<<endl;
cout<<"Space Complexity is:"<<(1.0)*space/ll.getSize()<<"bytes"<<endl;
break;
case 5:
cout<<"Enter the position you want to delete:"<<endl;
cin>>pos;
startTime=getTimeInMicroSeconds();
ll.deleteAtPos(pos);
ll.print();
endTime=getTimeInMicroSeconds();
cout<<"Time taken for execution is:"<<endTime-startTime<<"microseconds"<<endl;
cout<<"Space Complexity is:"<<(1.0)*(space+4)/ll.getSize()<<"bytes"<<endl;
break;
}
return 0;
}