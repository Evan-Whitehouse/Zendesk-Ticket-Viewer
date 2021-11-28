/* Test all the functions in the view of the Zendesk Ticket viewer
 * with a sample json containing 3 tickets.
 *
 * Author: Evan Whitehouse
 */

#include <stdio.h>
#include "../minunit.h"
#include "../model/model.c"
#include "../model/ticket.h"
#include "../model/parseTickets.h"

int tests_run = 0;
static FILE *fp = 0;

/* Test displaying a single ticket by making sure the ID adjustment matches.
 *
 * returns:
 * 0 if test passes, otherwise error message from assert statement. 
 */
char *testDisplaySingleTicket(){
	struct ticket **tickets = parseTickets(fp);
	mu_assert("Wrong id accessed.", !strcmp(tickets[1] -> id, "2"));
	freeAll(tickets);
	free(tickets);
	return 0;
}

/*Run all tests in the file.
*
* returns:
* 0 if test passes, otherwise error message from assert statement.
*/
static char *allTests(){
	mu_run_test(testDisplaySingleTicket);
	return 0;
}

int main(){
	FILE *ip = fopen("../model/test.json", "r");
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
