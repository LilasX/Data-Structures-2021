#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

/*
Codez un Queue circulaire contenant dix éléments  (Circular Queue) à partir de liste chaînée en c/c++?

 On doit pouvoir y : 
 
 - insérer un nouvel élément, 
 - effacer (delete) un élément, 
 - Rechercher un élément, 
 - afficher le contenu de liste chainée. 
 
 Vous devrez expliquer votre code en détails tout en ajoutant des commentaires. Attention : Vous devrez appliquer les deux règles suivantes :
 a)    Le troisième élément de la liste est fixe. C'est-à-dire, vous y insérez la première fois un élément, et cet élément ne va plus bouger de la !
 b)    Le Queue est circulaire pour trois itérations ! ensuite il devient un Queue non circulaire.
*/

struct Node
{
	int data; //the contained data in the node
	struct Node* next; //the pointer to the address of the next node, self referencial structure
};

struct Node* front = NULL; //global pointer that points the front of the queue
struct Node* rear = NULL; //global pointer that points the rear of the queue

//Insert an element
void enqueue(int x)
{
	struct Node* node = new Node; //create a space for node to insert data

	if (node == NULL) //if node pointer is null, it reached the end of the queue
	{
		cout << "Queue is full." << endl;
	}
	else
	{
		node->data = x; //the node we created to insert data is assigning a value x to data
		node->next = NULL; //next is null unless we create another new Node which next will stored the address of the next node created

		if (front == NULL) //if queue is empty
		{
			front = rear = node; //since it's the first element in the queue, there's only one node so the current node is the first and last element in the queue
		}
		else //if first isn't null, it means there's already an element before the one we just inserted in the queue
		{
			rear->next = node; //save the current node to the next of last
			rear = node; //the node we just inserted in the queue is now the element at the rear of the queue, so we change our last to our current node
			node->next = front; //our current node's 'next' points to first since it's a circular queue
		}
	}
}

//Delete an element
int dequeue()
{
	int x = -1; 
	struct Node* node; //declaring a Node pointer

	if (front == NULL) //if the front is null, then the queue is empty
	{
		cout << "Queue is empty." << endl;
	}
	else if (front == rear) //if the front caught up to the rear
	{
		x = front->data; //change x to the value 'front' is pointing
		node = front; //the current node is the front
		front = rear = NULL; //pointers are null 
		free(node); //free the last node in the queue
	}
	else
	{
		x = front->data; //change x to the value 'front' is pointing
		node = front; //the current node is the front
		front = front->next; //the front pointer is now pointing to the next node
		rear->next = front; //update the rear's link to the current front
		free(node); //deallocate node's allocated memory
	}
	return x; //returns the value we deleted
}

//Display elements
void Display()
{
	struct Node* p = front; //declaring pointer, starting at the front of the queue

	do //print data and iterate
	{
		printf("%d ", p->data); //print data 
		p = p->next; //p becomes the next node
	} while (p != front); //while the pointer 'p' isn't back to the front
	cout << endl;
}

//Search an element
int LSearch(int key)
{
	struct Node* p = front;

	do
	{
		if (p->data == key) //if key (the element we're searching for) matches with a data in the queue
		{
			return p->data; //return the element found
		}

		p = p->next; //p becomes the next node if we didn't find our 'key'
	} while (p != front); //while the pointer isn't back to the front

	return -1; //return null if we didn't find the element in the queue
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	enqueue(70);
	enqueue(80);
	enqueue(90);
	enqueue(100);

	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();

	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);

	Display();

	cout << LSearch(900);


	return 0;
}


//Reference(s)
//Queue folder in Omnivox