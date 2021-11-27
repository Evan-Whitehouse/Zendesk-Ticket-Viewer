/* Test all functions in the model of the Zendesk Ticket viewer
 * with a sample json containing 3 tickets.
 *
 * Author: Evan Whitehouse
 */
#include <stdio.h>
#include "../minunit.h"
#include "model.c"
#include "ticket.h"
#include "parseTickets.h"

int tests_run = 0;
static FILE *fp = 0;
/* Test the ticketCount function on a sample json with 3 tickets.
 * 
 * returns:
 * 0 if test passes, otherwise error message from assert statement.
 */
static char* testTicketCount(){
	mu_assert("error, ticket count != 3", ticketCount(fp) == 3);
	return 0;
}

/*  Test the parseTickets function, and by extension the fillTicketField function
 *  on a sample json with 3 tickets, making sure all fields are written correctly.
 *
 *  returns:
 *  0 if test passes, otherwise error message from assert statement.
 */
static char* testParseTickets(){
	struct ticket ** tickets = parseTickets(fp);
	mu_assert("error, id != '1'", !strcmp(tickets[0] -> id, "1"));
	mu_assert("error, incorrect time created", !strcmp(tickets[0] -> created_at, "2021-11-21T13:50:38Z"));
	mu_assert("error, incorrect time updated", !strcmp(tickets[1] -> updated_at, "2021-11-21T19:03:05Z"));
	mu_assert("error, incorrect subject", !strcmp(tickets[1] -> subject, "velit eiusmod reprehenderit officia cupidatat"));
	mu_assert("error, incorrect description", !strcmp(tickets[1] -> description, "Aute ex sunt culpa ex ea esse sint cupidatat aliqua ex consequat sit reprehenderit. Velit labore proident quis culpa ad duis adipisicing laboris voluptate velit incididunt minim consequat nulla. Laboris adipisicing reprehenderit minim tempor officia ullamco occaecat ut laborum.\\n\\nAliquip velit adipisicing exercitation irure aliqua qui. Commodo eu laborum cillum nostrud eu. Mollit duis qui non ea deserunt est est et officia ut excepteur Lorem pariatur deserunt."));
	mu_assert("error, incorrect priority", !strcmp(tickets[2] -> priority, "null"));
	mu_assert("error, incorrect status", !strcmp(tickets[2] -> status, "open"));
	freeAll(tickets);
	free(tickets);
	return 0;
}

/* Run all unit tests in the file.
 *
 * returns:
 * 0 if test passes, otherwise error message from assert statement.
 */
static char *allTests(){
	mu_run_test(testTicketCount);
	mu_run_test(testParseTickets);
	return 0;
}

int main(){
	FILE *ip = fopen("test.json", "r");
	//set test file
	fp = ip;
	char *result = allTests(fp);
     	if (result != 0) {
        	printf("%s\n", result);
     	}
     	else {
        	printf("ALL TESTS PASSED\n");
     	}
	printf("Tests run: %d\n", tests_run);
	fclose(fp);
	return result != 0;
}
