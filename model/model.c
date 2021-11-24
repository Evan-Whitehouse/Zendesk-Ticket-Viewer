/* Contains all methods for parsing and managing the json file, and
 * returning it as an easier to parse structure for the view and
 * controller to handle.
 *
 * Author: Evan Whitehouse
 */
#include "ticket.h"
#include "parseTickets.h"
#include <stdio.h>
#include <string.h>

/* Count the total number of tickets in the json file, jumps to the line countaining
 * the sequence of characters surrounding the count in the file and then reads
 * the numerical characters after that character sequence, converting them to an
 * unsigned int to return.
 *
 * parameters: FILE *fp, the pointer to the json file containing ticket information.
 *
 * returns The number of tickets in the file represented as an unsigned int.
 */

size_t ticketCount(FILE *fp){
	char *buffer = NULL;
	const char count[] = ",\"count\":";
	size_t len;
	getdelim( &buffer, &len, '\0', fp);
	char *index = strstr(buffer, count);
	char num[4] = {'0','0','0','\0'};
	index = &(index[strlen(count)]);
	num[0] = index[0];
	num[1] = index[1];
	if (index[2] < '0' || index[2] > '9'){
		num[2] = '\0';
	}
	else {
		num[2] = index[2];
	}
	return atoi(num);
}

void fillTicketField(struct ticket* currentTicket, int field, char **fields, char **endpoints, char*buffer){

}	

struct ticket * parseTicket(FILE *fp){
	size_t ticketCount = ticketCount(fp);
	struct ticket* tickets[ticketCount] = (struct ticket*) malloc(ticketCount * sizeof(struct ticket*));
	char* fields[] = {",\"id\":",  ",\"created_at\":", ",\"updated_at\":", 
		",\"subject\":", ",\"description\":", ",\"priority\":", ",\"status\":"};
	char* endpoints[] = {",\"external_id\":", ",\"updated_at\":", ",\"type\":", 
		",\"raw_subject\":", ",\"priority\":", ",\"status\":", ",\"recipient\":"};
	for (int i = 0; i < ticket_count; i++){
		struct ticket *currentTicket = (struct ticket*) malloc(sizeof(struct ticket));
		//loop through each field in the array, parse next instance of that field and allocate
		//that to memory, assign it to the currently open ticket.
		for (int i = 0; i < 7; i++){

		}

	}
	return tickets;
}

int main(){
	FILE *fp = fopen("tickets.json", "r");
	int x = ticketCount(fp);
	printf("%d \n", x);
	fclose(fp);
	return 0;
}
