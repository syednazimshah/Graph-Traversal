#include <iostream> //2019504 Syed Nazim Shah
using namespace std;

struct node
{
    string info;
    int distance;
    struct node *next;
    struct node *forward;
};

node *head=NULL;

node * create_node(string value, int dist)
{
    struct node *temp, *s;
    temp = new(struct node); 
    if (temp == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {
        temp->info = value;
        temp->distance = dist;
        temp->next = NULL;
        temp->forward=NULL;
        return temp;
    }
}

void insert_vertex(string value)
{
    struct node *temp, *s;
    temp = create_node(value,999999);
    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        s=head;
    while (s->next != NULL)
    {         
        s = s->next;        
    }
    s->next = temp;
    }
}

void insert_edge(string src, string dest, int distance)
{
    node * ptr = head;
    struct node *temp, *s;
    temp = create_node(dest,distance);
    while (ptr->info!=src)
    {
        ptr=ptr->next;
    }
    if(ptr->forward==NULL)
    {
        ptr->forward=temp;
    }
    else
    {
        s=ptr;
    while (s->forward  != NULL)
    {         
        s = s->forward;        
    }
    s->forward = temp;
        
    }
}

void Display()
{
    struct node *ptr, *ptr1;
    
    for(ptr=head; ptr!=NULL; ptr=ptr->next)
    {  
        for(ptr1=ptr; ptr1!=NULL; ptr1=ptr1->forward)
        {
        	if(ptr1->distance!=999999)
                cout<<"--("<<ptr1->distance<<"Km)--";
                cout<<ptr1->info;
                
        }
    cout<<endl;    
    }
}


int main()
{
int vertex;
cout<<"Enter the Number of Cities You want in your Graph:  ";
cin>>vertex;
string cities[vertex];

for(int i=0;i<vertex;i++)
{
    cout<<"\nEnter City " << i+1<<": "; cin>>cities[i];
    insert_vertex(cities[i]);
}


while(true){
	string city1,city2; int dist;
	cout<<"\nCreating an Edge \nEnter City 1: "; cin>>city1;
	cout<<"\nEnter City 2: "; cin>>city2;
	cout <<"\nEnter Distance: "; cin>>dist;
	insert_edge(city1,city2,dist);
	cout<<"Add another Edge(Y/N)?";
	char choice;
	cin>>choice;
	if(choice=='y' || choice =='Y') continue;
	else break;
}

	Display();
	return 0;
}
