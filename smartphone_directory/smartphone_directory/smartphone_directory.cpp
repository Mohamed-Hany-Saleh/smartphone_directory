// linkedlist.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Node
{
public:
	int ID;
	int phone;
	string name; 
	string email;
	string birthdate;


	Node* next;
	Node()
	{
		ID = 0;
		phone = 0 ;
		name;
		email;
		birthdate;

		next = NULL;
	}
};
class Linkedlist
{
public:
	Node* head;
	Linkedlist()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}
	bool isFull()
	{
		Node* newnode = new Node();
		if (newnode == NULL)
			return true;
		else
			return false;
	}
	void insertatbeginning(int id,int phone_1, string name_1,string email_1,string birthdate_1)
	{
		Node* newnode = new Node();
		newnode->ID = id;
		newnode->phone = phone_1;
		newnode->name = name_1;
		newnode->email = email_1;
		newnode->birthdate = birthdate_1;

		if (isEmpty())
		{
			newnode->next = NULL;
			head = newnode;
		}
		else
		{
			newnode->next = head;
			head = newnode;
		}
	}
	/*void insertsorted(int id, int phone_1, string name_1, string email_1, string birthdate_1)
	{
		Node* newnode = new Node();
		newnode->ID = id;
		newnode->phone = phone_1;
		newnode->name = name_1;
		newnode->email = email_1;
		newnode->birthdate = birthdate_1;
		if (isEmpty())
		{
			newnode->next = NULL;
			head = newnode;
		}
		else
		{
			Node* temp1 = head;
			//Node *temp2=head;
			while ((temp1->ID > id && temp1->next->ID > id) || (temp1->ID < id && temp1->next->ID > id && temp1 != NULL))
			{
				//temp1=temp2;
				temp1 = temp1->next;
			}
			//newnode->next = temp1;
			cout << temp1->ID << temp1->next->ID;
			getchar(); 
			newnode->next = temp1->next;
			temp1->next = newnode;
			cout << endl << "END" << endl;
		}
	}*/
	void deleteitem(int value)
	{
		if (isEmpty())cout << "empty";
		else
			if (search(value))
			{
				Node* temp1 = head;
				Node* temp2 = NULL;
				if (head->ID == value)
				{
					head = head->next;
					delete temp1;
				}
				else
				{
					while ((temp1->ID != value) && (temp1 != NULL))
					{
						temp2 = temp1;
						temp1 = temp1->next;
					}
					temp2->next = temp1->next;
					delete(temp1);
				}
			}
			else cout << "not found";
		         Sleep(5000);//ms
	}
	void display()
	{
		Node* temp = head;
		while (temp != NULL)
		{
			cout << temp->ID << " ";
			cout << 0 << temp->phone << " ";
			cout << temp->name << " ";
			cout << temp->email << " ";
			cout << temp->birthdate << " , ";

			temp = temp->next;
		}
		cout << endl << "END" << endl;
	}
	int count()
	{
		int c = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			c++;
			temp = temp->next;
		}
		return(c);
	}
	bool search(int item)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->ID == item) return (true);
			else temp = temp->next;
		}
		return(false);
	}
	bool update(int old_item, int new_item)
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->ID == old_item) {
				temp->ID = new_item; return
					true;
			}
			else temp = temp->next;
		}
		return false;
	}
	void sort_list()
	{
		
		Node* prev = head;
		Node* curr = head->next;
		
		while (curr != NULL)
		{
			if (curr->ID < prev->ID)
			{
				
				prev->next = curr->next;

				
				curr->next = head;
				head = curr;

				
				curr = prev;
			}
			/* Nothing to do if current 
		    element is at right place */
			else
				prev = curr;

			// Move current
			curr = curr->next;
		}
	

		
	
	}

};



void main()
{
	string letters[] = {
		   "*********     ********     **   **    *****    *****  *********",
		   "*********   ***********    **   **    **************  *********",
		   "***         **       **    **   **    **   ****   **  ***      ",
		   "***         **       **    **   **    **    **    **  *********",
		   "***         **       **    **   **    **          **  *********",
		   "***         **       **    **   **    **          **  ***      ",
		   "*********   *************  **** ****  **          **  *********",
		   "*********     ***********  **** ****  **          **  *********"
	};
	for (int i = 0; i < 8; ++i) {
		cout << letters[i] << endl;
	}

	int id,phone, sel;
	string  birthdate, email, name;

	Linkedlist list;
	do {
		getchar();
		system("cls");
		for (int i = 0; i < 8; ++i) {
			cout << letters[i] << endl;
		}
		list.display();
		cout << "1. insertatbeginning." << endl;
		cout << "2. deleteitem." << endl;
		cout << "3. Count." << endl;
		cout << "4. Search." << endl;
		cout << "5. Update." << endl;
		cout << "6. sort." << endl;
		cout << "7. display." << endl;
		cout << "0. End." << endl;
		cout << "Enter your choice:"; cin >> sel;
		switch (sel)
		{
		case 1: 

			cout << "Enter ID to insert\n";
			cin >> id;
			cout << "Enter Phone to insert\n";
			cin >> phone;
			cout << "Enter Name to insert\n";
			cin >> name;
			cout << "Enter Email to insert\n";
			cin >> email;
			cout << "Enter Birth Date to insert\n";
			cin >> birthdate;

			list.insertatbeginning(id,phone,name,email,birthdate); 
			
			break;

		case 2: 
			
			cout << "Enter item to delete\n"; cin >> id;

			list.deleteitem(id); 
			break;

		case 3: 

			cout << " count= " << list.count(); 
			Sleep(5000);//ms
			break;

		case 4: 
			
			int l_item; 
			cout << "Enter the item to be searched of the list: ";
			cin>>l_item;
			if (list.search(l_item)) cout << "YES" << endl; 
			else cout << "NO" << endl;
			Sleep(5000);//ms
			break;

		case 5:
			
			int old_item, new_item;
			cout << "Enter the item to be changed of the list : ";
			cin>>old_item;
			cout << "Enter the new value: "; 
			cin >> new_item;
			if (list.update(old_item, new_item)) cout << "YES" << endl;
			else cout << "NO" << endl;
			Sleep(5000);//ms
			break;

		case 6:
			list.sort_list();
			break;
		case 7:
			list.display();
			Sleep(10000);
			break;//ms


		case 0:cout << "THE END... \n";
		}
	} while (sel != 0);
}