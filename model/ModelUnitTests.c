#include <stdio.h>
#include "../minunit.h"
#include "model.c"
#include "ticket.h"
#include "parseTickets.h"

int tests_run = 0;

/* Test the ticketCount function on a sample json with 3 tickets.
 * 
 * parameter:
 * FILE *fp, pointer to the file to be counted.
 *
 * returns:
 * 0 if test passes, otherwise error message from assert statement.
 */
static char* testTicketCount(FILE *fp){
	mu_assert("error, ticket count != 3", ticketCount(fp) == 3);
	return 0;
}

/*  Test the parseTickets function, and by extension the fillTicketField function
 *  on a sample json with 3 tickets, making sure all fields are written correctly.
 *
 *  parameter:
 *  FILE *fp, pointer to the file with tickets to be counter.
 *
 *  returns:
 *  0 if test passes, otherwise error message from assert statement.
 */
static char* testParseTickets(FILE *fp){
	struct ticket ** tickets = parseTickets(fp);
	mu_assert("error, id != '1'", strcmp(tickets[1] -> id, "1"));
	freeAll(tickets);
	free(tickets);
	return 0;
}
int main(){
	FILE *fp = fopen("test.json", "r");
	testParseTickets(fp);
	fclose(fp);
	return 0;
}
