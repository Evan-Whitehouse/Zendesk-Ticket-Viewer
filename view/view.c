#include <stdio.h>
#include <string.h>
#include "../model/ticket.h"

void printLabels(){
	printf("%-5s|%-28s|%-21s|%-21s|%-9s|%-8s\n", "ID", "Subject",
			"Created At", "Updated At", "Priority", "Status");
}

void displayMenuStart(){

}

void displayMenuEnd(){

}

void displayMenuSingleStruct(){

}

void displayTicketArray(int page, struct ticket **tickets){

}

void displaySingleTicket(int id, struct ticket **tickets){

}

int main(){
	printLabels();
	return 0;
}
