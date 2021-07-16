#include"LinkedList.h"

LinkedList::LinkedList()
{
	//Constructor
	Head = NULL;
}

void LinkedList::Push_back(int x)
{
	//TODO : Insert a node to the end of the linked list, the node¡¦s value is x.
	ListNode*temp = new ListNode;
	temp->data = x;
	temp->next = NULL;
	ListNode *ptr = Head;
	if (Head == NULL)
	{
		Head = temp;
		
	}//check if list is empty
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}//find the last element of the linked list
		ptr->next = temp;
	}


}

void LinkedList::Push_front(int x)
{
	//TODO : Insert a node to the front of the linked list, the node¡¦s value is x.
	ListNode*temp1 = new ListNode();
	temp1->data = x;
	temp1->next = NULL;
	temp1->next = Head;
	Head = temp1;
	//for(int i; i<)


}

void LinkedList::Insert(int n, int data )
{
	//n = n + 1;?
	//TODO : Insert a node to the linked list at position ¡§index¡¨, the node's value is x.
	//The index of the first node in the linked list is 0.
	//create a node call to malloc
	ListNode*temp1 = new ListNode();
	temp1->data = data;
	temp1->next = NULL;
	if (n == 0)
	{
		Push_front(data);

	}
/*	if (n == 1) 
	{
	//	ListNode* Head;
		temp1->next = Head;
		Head = temp1;
		//return;
		//temp1->next = LinkedList->Head;
		//LinkedList->Head = temp1;
	}
	*/
	else {
		ListNode*temp2 = Head;
		for (int i = 1; i < n ; i++)
		{
			//if (temp2 == NULL)
			temp2 = temp2->next;

		}
		temp1->next = temp2->next;
		temp2->next = temp1;

	}

}

void LinkedList::Delete(int index)
{
	int n = index;
	//TODO : Remove the node with index ¡§index¡¨ in the linked list.
	//fix the links! just ignore theone in between
	//when we do that it detached but still in the memory in the heap section//for that we need to free the space taken and finally the mfcker is gone
	ListNode* temp1 = Head;
	if (n == 0)
	{
		Head = temp1->next;//head now points to second Node
		free(temp1);
	}
	else
	{
		int i;
		for (i = 0; i < n -2; i++)
			temp1 = temp1->next;
		//temp1 points to (n-1)th node
		ListNode*temp2 = temp1->next;//represents the nth node
		temp1->next = temp2->next; //reference (n+1)th node
		free(temp2); //delete temp2
	}

}

void LinkedList::Reverse()
{
	//TODO : Reverse the linked list.
	//this uses the iterative method
	ListNode *temp,*prev,*next;
	temp = Head;
	prev = NULL;
	while (temp != NULL)
	{
		next = temp->next;
		 temp->next=prev;
		 prev = temp;
		 temp = next;   //to adjust the variable head
	}
	Head = prev;
	//return Head;

}

void LinkedList::Print()
{
	cout << "List: ";
	//TODO : Print all the elements in the linked list in order.
	ListNode*temp = Head;
	while (temp != NULL) {
	
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout << endl;
}

LinkedList::~LinkedList()
{
	//Destructor
	//cout << "everything is destroyed" << endl;
}
