#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node *next;
  node()
  {
    data=0;
    next = NULL;
  }
  node(int k)
  {
    data = k;
    next = NULL;
  }
};

struct singlylinklist
{
  node *head, *tail;
  singlylinklist();
  void Insert_Into_Head(int);
  void Insert_After_Node(int, int);
  void Insert_In_Between(int, int);
  void Insert_Into_Tail(int);
  int Delete_From_Head();
  int Delete_From_Tail();
  int Delete_In_Between(int);
  int Delete_With_a_Given_Value(int);
  void printlist();
};

singlylinklist::singlylinklist()
{
  head = NULL;
  tail = NULL;
}

void singlylinklist::Insert_Into_Head(int k)
{
  node *cur = new node(k);
  if(tail == NULL)
  {
    head = tail = cur;
    return;
  }
  else
  cur->next = head;
  head = cur;

}


void singlylinklist::Insert_After_Node(int k, int val)
{
  node *cur = new node(k);
  node *ptr;
  cout<<"inserting "<<k<<" after node "<<val<<endl;
  ptr = head;
  while(ptr->data!=val && ptr->next != NULL)
  {
    ptr= ptr->next;
  }
  if(ptr->data == val)
  {
    cur->next = ptr->next;
    ptr->next = cur;
  }
  else
  {
    cout<<"node "<<val<<" not found!"<<endl;
  }
}


void singlylinklist::Insert_In_Between(int k, int position)
{
  node *cur = new node(k);
  node *ptr;
  int i=0;
  ptr = head;
  while(i<position-1 && ptr->next!= NULL)
  {
    i++;
    ptr= ptr->next;
  }
  if(position==0 && ptr!=NULL)
  {
    cur->next = ptr;
    head = cur;
  }
  else if(position==0 && ptr==NULL)
  {
    head = tail = cur;
  }
  else if(ptr->next != NULL)
  {
    cur->next = ptr->next;
    ptr->next = cur;
  }
  else if(ptr->next == NULL && i+1==position)
  {
    ptr->next= cur;
    tail =cur;
  }
  else
  cout<<"couldn't insert, position is out of range"<<endl;
}

void singlylinklist::Insert_Into_Tail(int k)
{
  node *cur = new node(k);
  if(head==NULL)
  {
    head = tail = cur;
  }
  else
  {
    tail->next = cur;
    tail = cur;
  }
}

int singlylinklist::Delete_From_Head()
{
  node *temp;
  temp = head;
  int ret;
  if(temp!=NULL && temp->next!=NULL)
  {
    head = head -> next;
    ret = temp->data;
    delete temp;
    return ret;
  }
  else if(temp!=NULL && temp->next == NULL)
  {
    head = tail = NULL;
    ret = temp -> data;
    delete temp;
    return ret;
  }
  else
  {
    cout<<"underflow!"<<endl;
    return -1;
  }
}
int singlylinklist::Delete_From_Tail()
{
  node *temp, *ptr;
  temp = tail;
  ptr = head;
  int ret;

  if(ptr!=NULL && ptr->next != NULL)
  {
    while(ptr->next != tail)
    {
      ptr= ptr->next;
    }
    ret = temp->data;
    tail = ptr;
    tail->next = NULL;
    delete temp;
    return ret;
  }

  else if(ptr!=NULL && ptr->next == NULL)
  {
    head = tail = NULL;
    ret = temp -> data;
    delete temp;
    return ret;
  }
  else
  {
    cout<<"underflow!"<<endl;
    return -1;
  }
}
// int Delete_In_Between(int);
int singlylinklist::Delete_With_a_Given_Value(int k)
{
  node *temp, *ptr;
  ptr = head;
  int ret;
  if(ptr==NULL)
  {
    cout<<"data not found"<<endl;
    return -1;
  }
  else
  {
    while(head!=NULL && ptr->next != NULL && ptr->data != k)
    {
      temp=ptr;
      ptr= ptr->next;
    }
    if(ptr==head && ptr->next!=NULL && ptr->data ==k)
    {
      ret = ptr->data;
      head=head->next;
      delete ptr;
      return ret;
    }
    else if(ptr==head && ptr->next==NULL && ptr->data ==k)
    {
      head = tail = NULL;
      ret = ptr->data;
      delete ptr;
      return ret;
    }
    else if(ptr==tail && ptr->data ==k)
    {
      tail = temp;
      temp->next = NULL;
      ret = ptr->data;
      delete ptr;
      return ret;
    }
    else if(ptr!=tail && ptr->data == k)
    {
      temp->next = ptr->next;
      ret = ptr->data;
      delete ptr;
      return ret;
    }
    else if(ptr==NULL)
    {
      cout<<"data not found"<<endl;
      return -1;
    }
    else
    {
      cout<<"data not found"<<endl;
      return -1;
    }
  }
}

void singlylinklist:: printlist()
{
  node *ptr;
  ptr = head;
  cout<<"showing values: ";
  while(ptr != NULL)
  {
    cout<<ptr->data << " ";
    ptr = ptr -> next;
  }
  cout<<endl;
}


int main()
{
  singlylinklist sl;
  sl.Insert_In_Between(3, 0);
  sl.printlist();
  sl.Insert_In_Between(1, 0);
  sl.printlist();
  sl.Insert_In_Between(2, 1);
  sl.printlist();
  sl.Insert_In_Between(2, 4);
  sl.printlist();
  sl.Insert_Into_Head(14);
  sl.printlist();
  sl.Insert_Into_Head(47);
  sl.printlist();
  sl.Insert_Into_Head(79);
  sl.printlist();
  sl.Insert_Into_Head(77);
  sl.printlist();
  sl.Insert_Into_Head(55);
  sl.printlist();
  sl.Insert_Into_Head(12);
  sl.printlist();
  sl.Insert_After_Node(10, 55);
  sl.printlist();
  sl.Insert_After_Node(12, 21);
  sl.printlist();
  sl.Insert_In_Between(3, 13);
  sl.printlist();
  sl.Insert_In_Between(3, 12);
  sl.printlist();
  sl.Insert_In_Between(54, 13);
  sl.printlist();
  sl.Insert_In_Between(1, 0);
  sl.printlist();
  sl.Insert_In_Between(99, 1);
  sl.printlist();
  sl.Insert_Into_Tail(12);
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Delete_From_Head();
  sl.printlist();
  sl.Insert_In_Between(3, 0);
  sl.printlist();
  sl.Insert_In_Between(1, 0);
  sl.printlist();
  sl.Insert_In_Between(2, 1);
  sl.printlist();
  sl.Insert_In_Between(2, 4);
  sl.printlist();
  sl.Insert_Into_Head(14);
  sl.printlist();
  sl.Insert_Into_Head(47);
  sl.printlist();
  sl.Delete_From_Tail();
  sl.printlist();
  sl.Delete_From_Tail();
  sl.printlist();
  sl.Delete_From_Tail();
  sl.printlist();
  cout<<sl.Delete_From_Tail()<<endl;
  sl.printlist();
  cout<<sl.Delete_From_Tail()<<endl;
  sl.printlist();
  cout<<sl.Delete_From_Tail()<<endl;
  sl.printlist();
  sl.Insert_Into_Head(14);
  sl.printlist();
  sl.Insert_Into_Head(47);
  sl.printlist();
  sl.Insert_Into_Head(79);
  sl.printlist();
  sl.Insert_Into_Head(77);
  sl.printlist();
  sl.Insert_Into_Head(55);
  sl.printlist();
  sl.Insert_Into_Head(12);
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(12)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(12)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(14)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(79)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(77)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(47)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(47)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(55)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(88)<<endl;
  sl.printlist();
  cout<<sl.Delete_With_a_Given_Value(55)<<endl;
  sl.printlist();

  return 0;
}
