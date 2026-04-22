#ifndef UART_H
#define UART_H
typedef struct Node
{
	char command[33];
	struct Node* next;
}Node;

extern volatile int flag;

#endif
