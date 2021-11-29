/* Controller for the Zendesk Ticket Viewer. Interacts with the user
 * and displays information based on their inputs. Utilizes a finite state
 * machine to regulate menu displays.
 */

#include "../model/ticket.h"
#include "../model/parseTickets.h"
#include <stdio.h>
#include <string.h>
#include "../view/view.h"

/* Prints the ticket information for a ticket whose ID corresponds to user input,
 * catches invalid input and gives user an additional opportunity to enter new input.
 *
 * Parameters:
 * int countTickets, the number of tickets in the list. Used for checking the input for validity.
 * struct ticket **tickets, the list of tickets being searched.
 */
void searchTicket(int countTickets ,struct ticket **tickets){
	printf("Please enter the ticket number you wish to search for: ");
	char id[100];
	scanf("%s", id);
	int x = atoi(id);
	printf("\n");
	if (x < 1 || x > countTickets){
		printf("Invalid ID Number\n");
		searchTicket(countTickets, tickets);
	}
	else {
		displayMenuSingleStruct();
		displaySingleTicket(atoi(id), tickets);
	}
       			
}
/* Handles ticket viewer's interactiion with the user. Implemented as a finite state machine.
 * user input changes the state and page number, and state transitions cause output to be printed to console.
 */
int main(){
	system("./controller/get-tickets.sh");
	FILE *fp = fopen("tickets.json", "r");
	struct ticket **tickets = parseTickets(fp);
	int countTickets = ticketCount(fp);
	int state = 0;
	int page = 0;
	printf("Welcome to the Zendesk Ticket Viewer. \n");
	printf("ENTER Q TO QUIT AT ANY TIME\n");
	char c = '9'; 
	char input[100];
	displayMenuStart();
	printLabels();
	displayTicketArray(page, countTickets, tickets);
	while(c != 'q' && c != 'Q'){
		scanf("%s", input);
		if (strlen(input) != 1){
			printf("Invalid Input.");
		}
		else {
			c = input[0];
			//menu start state
			if (state == 0){
				if (c == '2'){
					page++;
					if (page > countTickets / 25){
						page--;
					}
					else if (page == countTickets / 25){
						state = 2;
						printf("\n");
						displayMenuEnd();
						printLabels();
						displayTicketArray(page, countTickets, tickets);
						
					}
					else {
						state = 1;
						printf("\n");
						displayMenuMiddle();
						printLabels();
						displayTicketArray(page, countTickets, tickets);
					}
				}
				else if (c == '3'){
					state = 3;
					printf("\n");
					searchTicket(countTickets, tickets);
				}
			}
			//menu middle state
			else if (state == 1){
				if (c == '1'){
					printf("\n");
					page--;
					if (page == 0){
						state = 0;
						displayMenuStart();
					}
					else {
						displayMenuMiddle();
					}
					displayTicketArray(page, countTickets, tickets);
				}
				else if (c == '2'){
					page++;
					if (page == countTickets / 25){
						state = 2;
						printf("\n");
						displayMenuEnd();
						printLabels();
						displayTicketArray(page, countTickets, tickets);
					}
					else {
						printf("\n");
						displayMenuMiddle();
						printLabels();
						displayTicketArray(page, countTickets, tickets);
					}
				}
				else if (c == '3'){
					state = 3;
					printf("\n");
					searchTicket(countTickets, tickets);

				}
			}
			//menu end state
			else if (state == 2){
				if (c == '1'){
					page--;
					printf("\n");
					if (page == 0){
						state = 0;
						displayMenuStart();
					}
					else {
						displayMenuMiddle();
					}
					displayTicketArray(page, countTickets, tickets);
				}
				else if (c == '3'){
					state = 3;
					printf("\n");
					searchTicket(countTickets, tickets);

				}
			}
			//single ticket details
			else if (state == 3){
				if (c == '1'){
					page = 0;
					state = 0;
					printf("\n");
					displayMenuStart();
					displayTicketArray(page, countTickets, tickets);
				}
				else if (c == '3'){
					state = 3;
					printf("\n");
					searchTicket(countTickets, tickets);

				}
			}
		}
	}


	freeAll(tickets);
	free(tickets);
	fclose(fp);
	return 0;
}
