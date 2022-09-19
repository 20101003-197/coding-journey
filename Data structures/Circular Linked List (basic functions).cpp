#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
/*
The lines you see commented in switch statement is what i experimented with to make circular
linked list work without creating any function in the Class.
*/
class Circular_linked_list{
	private: 
    node *head;
	public:
	Circular_linked_list(){
			head=NULL;
		}
 	void add(int n){
		node *s= new node;
		node *temp=head;
		s->data=n;
		s->next=head;
		if(head!=NULL){
			while(temp->next!=head)
				temp=temp->next;
				temp->next=s;
	}
		else
			s->next=s;
			head=s;
}

     void insertion_at_start(int val) {
      node* next_node = new node;
      next_node->data = val;
      next_node->next = NULL; 
      if(head == NULL) {
        head = next_node;
        next_node->next = head;
      } else {
        node* temp = head;
        while(temp->next != head)
          temp = temp->next;
        temp->next = next_node;
        next_node->next = head;
        head = next_node;
      }    
    }

   void insertion_at_end(int val) {
      node* next_node = new node;
      next_node->data = val;
      next_node->next = NULL; 
      if(head == NULL) {
        head = next_node;
        next_node->next = head;
      } 
	  else {
        node* temp = head;
        while(temp->next != head)
          temp = temp->next;
        temp->next = next_node;
        next_node->next = head;
      }    
    }
    
    
    void Specific_insertion(int number, int position)
{
    struct node *newnode, *current_Node;
    int i;
    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
    {
        node *newnode=new node;
		newnode->data = number;
        current_Node = head;
        for(i=0; i<=position-3; i++)
        {
            current_Node = current_Node->next;
        }
        newnode->next = current_Node->next;
        current_Node->next = newnode;
    }
} 
    
    
    void deletion_at_Start() {
      if(head != NULL) {
        if(head->next == head) {
          head = NULL;
        } else {
          node* temp = head;
          node* firstNode = head;
          while(temp->next != head) {
            temp = temp->next;
          }
          head = head->next;
          temp->next = head; 
          delete (firstNode); 
        }
      }
    }

    void deletion_at_end() {
      if(head != NULL) {
        if(head->next == head) {
          head = NULL;
        } else 
		{
          node* temp = head;
          while(temp->next->next != head)
            temp = temp->next;
          node* lastNode = temp->next;
          temp->next = head;
          delete (lastNode); 
        }
      }
    }
    
    void specific_deletion()  
    {  
        struct node *ptr1, *ptr2;  
        int place,i;   
		cout<<"Enter the location ";
	    cin>>place;
        ptr1=head;  
        for(i=0;i<place-1;i++)  
        {  
            ptr2=ptr1;       
            ptr1=ptr1->next;   
            if(ptr1==NULL)  
            {  
                 cout<<"List is empty"<<endl;
            }  
        }  
        ptr2->next=ptr1->next;  
        delete(ptr1);  
        cout<<"\n The Deleted node is: "<<place;
    }
    
    void display()
    {
    struct node *tmp;
    int s = 1;
    if(head == NULL)
    {
        cout<<"List is empty";
    }
    else
       {
        tmp = head;
        
        cout<<"\n Data in Circular linked list :\n";
        do {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
            s++;
        }while(tmp != head);
        }
    }

	
};
int main(){
Circular_linked_list obj;
  int choice;
  int key1, key2, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. add Node()" << endl;
    cout << "2. insert at start()" << endl;
    cout << "3. insert at end()" << endl;
    cout << "4. insert at specfic location()" << endl;
    cout << "5. delete at start()" << endl;
    cout << "6. delete at specific location()" << endl;
    cout << "7. print()" << endl;
    cout << "8. Clear Screen" << endl << endl;

     cin>>choice;
    node * n1 = new node();
    

    switch (choice) {
    case 0:
      break;
    case 1:
      cout << "Add Node Operation. ENTER VALUE" << endl;
      cin>>data1;
      /*cin >> key1;
      cin >> data1;
      n1->key = key1;
      n1->data = data1;*/
      obj.add(data1);
      
      break;

    case 2:
      cout << "insert at start Operation. Enter Value" << endl;
      cin >> data1;
	  /*cin >> key1;
      n1 -> key = key1;
      n1 -> data = data1;*/
      obj.insertion_at_start(data1);
      break;

    case 3:
      cout << "Insertion at end  Operation. ENTER A Value" << endl;
      cin >> data1;
	  /*cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      n1 -> key = key1;
      n1 -> data = data1;*/
      obj.insertion_at_end(data1);
      break;

    case 4:

      cout << "insertion at specefic location Operation" << endl;
      cout<<" Enter Data to be inserted"<<endl;
	  cin >> data1;
	  cout<<"Enter node Number"<<endl;
	  cin>>key1;
      obj.Specific_insertion(data1,key1);

      break;
    case 5:
      cout << "deletion at start Operation" << endl;
     // cin >> key1;
      //cin >> data1;
      obj.deletion_at_Start();

      break;
      case 6:
      	obj.specific_deletion();
      	break;
    case 7:
      obj.display();

      break;
    case 8:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (choice != 0);

return 0;
}
