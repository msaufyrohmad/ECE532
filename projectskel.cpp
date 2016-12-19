#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string.h>

using namespace std;

//function prototype
void addplayer(int id,string name,int age,int fitness,int height,int weight,float value);
void read();
void delete_node(int del_id);
void cari(int id);
void save();
void loaddb();
void update(int id_cari);

/*global variables that can be use by all function */
string name;
int age;
int fitness;
int height;
int weight;
int value;

struct MSLplayer
{
   int id;
   string name;
   int age;
   int fitness;
   int height;
   int weight;
   float value;
   struct MSLplayer *next;
}*head;

void loaddb()
{
   cout<<endl<<" === READ DB! ==="<<endl<<endl;
   ifstream db;
   db.open("MSLdata.txt");
   string line;
   if (db.is_open())
  {
    while ( getline (db,line) )
    {
      cout << line << '\n';
    }
    db.close();
  }
  else cout << "Unable to open file";


}

void save()
{
   ofstream db;
   db.open("MSLdata.txt");
   cout<<"Writing Player data to DB"<<endl;
   struct MSLplayer *temp=head;
   while(temp)
   {
      db<<"Player id is:"<<temp->id<<endl;
      db<<"Player name is:"<<temp->name<<endl;
      db<<"Player age is:"<<temp->age<<endl;
      db<<"Player fitness is:"<<temp->fitness<<endl;
      db<<"Player height is:"<<temp->height<<endl;
      db<<"Player weight is:"<<temp->weight<<endl;
      db<<"Player value in thousand USD is:"<<temp->value<<endl<<endl;
      temp=temp->next;
   }
   db.close();
}

void addplayer(int id,string name,int age,int fitness,int height,int weight,float value)
{
   cout<<"Adding new player!"<<endl;
   if(head==0)
   {
      struct MSLplayer *n = new MSLplayer;
      n->id=id;
      n->name=name;
      n->age=age;
      n->fitness=fitness;
      n->height=height;
      n->weight=weight;
      n->value=value;
      n->next=NULL;
      head=n;
   }
   else
   {
      struct MSLplayer *n=new MSLplayer;
      n->id=id;
      n->name=name;
      n->age=age;
      n->fitness=fitness;
      n->height=height;
      n->weight=weight;
      n->value=value;
      n->next=NULL;
      struct MSLplayer *temp=head;
      while(temp->next!=NULL)
      {
         temp=temp->next;
      }
      temp->next=n;
      n->next=NULL;
}

}
void read_input()
{
   cout<<"Enter name, age,fitness, height,weight and value of the player:";
   cout<<"Enter name of the player;";
   cin>>name;
   cout<<"Enter age,fitness, height,weight and value of the player:";
   cin>>age>>fitness>>height>>weight>>value;
   cout<<"Your input :"<<name<<" age: "<<age<<"fitness :"<<fitness<<"height :"<<height<<"weight :"<<weight<<"value:"<<value;
}

void read()
{
   struct MSLplayer *temp=head;
   cout<<"READ PLAYER DATA FROM LINKED LIST!"<<endl;
   while(temp)
   {
      cout<<"Player id is:"<<temp->id<<endl;
      cout<<"Player name is:"<<temp->name<<endl;
      cout<<"Player age is:"<<temp->age<<endl;
      cout<<"Player fitness is:"<<temp->fitness<<endl;
      cout<<"Player height is:"<<temp->height<<endl;
      cout<<"Player weight is:"<<temp->weight<<endl;
      cout<<"Player value in thousand USD is:"<<temp->value<<endl<<endl;
      temp=temp->next;
   }
}

void delete_node(int del_id)
{
   struct MSLplayer *temp=head;
   int count=0;
   while(temp->next!=NULL)
   {
      if(temp->id==del_id-1)
         break;
      temp=temp->next;
   }
   struct MSLplayer *temp2;
   temp2=temp->next->next;
   temp->next=temp2;
}
void cari(int id_cari)
{
   struct MSLplayer *temp=head;
   while(temp)
   {
      if(temp->id==id_cari)
      {
         cout<<endl<<"FOUND player with id :"<<id_cari<<endl;
         cout<<"Player name is:"<<temp->name<<endl;
         cout<<"Player age is:"<<temp->age<<endl;
         cout<<"Player fitness is:"<<temp->fitness<<endl;
         cout<<"Player height is:"<<temp->height<<endl;
         cout<<"Player weight is:"<<temp->weight<<endl;
         cout<<"Player value in thousand USD is:"<<temp->value<<endl<<endl;
      }
      temp=temp->next;
   }
}

/*void update(int id_cari)
{
   struct MSLplayer *temp=head;
   string update;
   int new_val;
   while(temp)
   {
      if(temp->id==id_cari)
      {
         cout<<"nak tukar apa?:"<<endl;
         cin>>update;
         cout<<"Enter new value?:"<<endl;
         cin>>new_val;
         if (!strcmp("fitness",update))
            temp->fitness=new_val;
         else if (!strcmp("weight",update))
            temp->weight=new_val;
         else if (!strcmp("value",update))
            temp->value=new_val;
         else
            cout<<"No information on that!"<<endl;
      }
      temp=temp->next;
   }
}
*/


int main()
{
   /*
   *int id;char *name;int age;int fitness;int height;int weight;float value;
   */
   addplayer(1,"muhammad",34,100,165,68,1000);
   addplayer(2,"ahmad",30,100,175,75,2000);
   addplayer(3,"ali",20,90,175,75,3000);
   addplayer(4,"abu",22,90,180,85,4000);

   read();
   delete_node(2);
   read();
   cari(3);
   save();
   loaddb();
}
