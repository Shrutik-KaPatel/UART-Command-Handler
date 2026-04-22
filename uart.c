#include "uart.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

volatile int flag = 0; // if command arives flag = 1

static int commandCounter = 0;
static Node* head = NULL; // should only visible in uart.c

void enqueue(char* command)
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //create a new Node

	strcpy(newNode->command,command); // copy the string into it
	newNode->next = NULL; //last node pointer
	if(head == NULL)  // if this is the first node
	{
       		head = newNode;
	}
	else //add into bottom of node
	{
		Node* temp = head;
		while(temp->next != NULL)
		{
		temp = temp->next;
		}
		temp->next = newNode;
	}
	
}

char* dequeue() // remove the node from the front of the queue and returns the command string 
{
	if(head == NULL) //if first node
	{
		return NULL;
	}

	static char buffer[33]; 
	strcpy(buffer,head->command);
 
	Node* temp = head;
	head = temp->next; //declared new head
	free(temp);	//removed head
	
	return buffer;
}

void simulate_uart_receive(char* cmd) //it simulates what a hardware interrupt would do when a command arrives over UART.
{
	printf("[UART] Command received: %s\n", cmd);
	enqueue(cmd);
       flag = 1;	
}
