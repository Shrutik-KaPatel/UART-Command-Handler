#ifndef UART_H
#define UART_H
typedef struct Node
{
	char command[33];
	struct Node* next;
}Node;

extern volatile int flag;
void enqueue(char* command);
char* dequeue();
void simulate_uart_receive(char* cmd);
#endif
