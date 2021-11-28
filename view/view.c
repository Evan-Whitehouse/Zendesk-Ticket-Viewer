/* Contains all functions for displaying information to the user based on possible menu states.
 *
 * Author: Evan Whitehouse
 */

#include <stdio.h>
#include <string.h>
#include "../model/ticket.h"

// Print labels for each ticket information category, with fixed column widths.
void printLabels(){
	printf("%-5s|%-28s|%-21s|%-21s|%-9s|%-8s\n", "ID", "Subject",
			"Created At", "Updated At", "Priority", "Status");
}

// Display the menu for page 0 (can't scroll backwards).
void displayMenuStart(){
	printf("Enter 2 to view next 25 tickets, or 3 to search for a ticket by ID. \n");
}

// Display the menu for a page with tickets before and after it.
void displayMenuMiddle(){
	printf("Enter 1 to view previous 25 tickets, 2 to view the next 25, or 3 to search for a ticket by ID.\n");
}

// Display the menu for the last page (can't scroll forwards).
void displayMenuEnd(){
	printf("Enter 1 to view previous 25 tickets, or 3 to search for a ticket by ID. \n");
}

// Display the menu for when a single ticket is being viewed.
void displayMenuSingleStruct(){
	printf("Enter 1 to return to list view, or 3 to search for a ticket by ID. \n");
}

/* Display a range of 25 tickets, based on a page number that indicates which group of 25 to show.
 *
 * Parameters: 
 * int page, the page number to display. Prints tickets from page * 25 to page * 25 + 25.
 * int ticketCount, the number of tickets in the array. Ensure we won't print past that number of tickets.
 * struct ticket **tickets, the list of tickets to print from.
 */
void displayTicketArray(int page, int ticketCount, struct ticket **tickets){
	int max = 0;
	if (page * 25 + 25 > ticketCount){
		max = ticketCount;
	}
	else {
		max = page * 25 + 25;
	}
	for(int i = page * 25; i < max; i++){
		printf("%-5.5s|%-28.28s|%-21.21s|%-21.21s|%-9.9s|%-8.8s\n", tickets[i] -> id, tickets[i] -> subject,
				tickets[i] -> created_at, tickets[i] -> updated_at, tickets[i] -> priority, tickets[i] -> status);

	}
}

/* Print a single ticket with a detailed description.
 *
 * Parameters:
 * int id, the ID of the ticket being printed
 * struct ticket **tickets, the list of tickets to print from.
 */
void displaySingleTicket(int id, struct ticket **tickets){
	printf("%-5s|%-38s|%-21s|%-21s|%-9s|%-8s\n", "ID", "Subject",
			"Created At", "Updated At", "Priority", "Status");
	printf("%-5.5s|%-38.38s|%-21.21s|%-21.21s|%-9.9s|%-8.8s\n", tickets[id - 1] -> id, tickets[id - 1] -> subject,
	tickets[id - 1] -> created_at, tickets[id - 1] -> updated_at, tickets[id - 1] -> priority, tickets[id - 1] -> status);
	printf("%s\n", tickets[id - 1] -> description);
}

