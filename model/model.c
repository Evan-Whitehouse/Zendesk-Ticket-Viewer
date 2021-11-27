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
 * parameters: 
 * FILE *fp, the pointer to the json file containing ticket information.
 *
 * returns: 
 * The number of tickets in the file represented as an unsigned int.
 */

size_t ticketCount(FILE *fp){
	fseek(fp, 0, SEEK_SET);	
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
	free(buffer);
	return atoi(num);
}
/* Fill the ticket field corresponding to the index parameter with the next section corresponding to that
 * from the buffer. Copies the text between the buffer and the endpoint representing the next json attribute.
 * 
 * parameters: 
 * struct ticket *currentTicket, the ticket being modified.
 * int index, the parameter to be filled out.
 * char **fields, list of all included parameter names.
 * char **endpoints, list of the next parameter after the field of matching index value.
 * char *buffer, current pointer location in the open json file's full text.
 */
void fillTicketField(struct ticket *currentTicket, int index, char **fields, char **endpoints, char*buffer){
	char *endpoint = strstr(buffer, endpoints[index]);
	buffer += strlen(fields[index]);
	if (buffer[0] == 34){
		buffer += 1;
		endpoint -= 1;
	}
	size_t length = endpoint - buffer;
	char* field = (char*) malloc(length + 1);
	field[length] = '\0';
	memcpy(field, buffer, length);
	switch (index){

		case 0 :
			currentTicket -> id = field;
			break;
		case 1 :
			currentTicket -> created_at = field;
			break;
		case 2 :
			currentTicket -> updated_at = field;
			break;
		case 3 :
			currentTicket -> subject = field;
			break;
		case 4 :
			currentTicket -> description = field;
			break;
		case 5:
			currentTicket -> priority = field;
			break;
		case 6:
			currentTicket -> status = field;

	}
}	

/* Parses an entire json file into a list of tickets allocated to the heap, with all fields
 * filled out.
 *
 * parameter:
 * FILE *fp, the JSON file being parsed.
 *
 * returns:
 * struct ticket **tickets, the list of tickets being returned.
 */
struct ticket **parseTickets(FILE *fp){
	fseek(fp, 0, SEEK_SET);	
	char *buffer = NULL;
	size_t len;
	getdelim( &buffer, &len, '\0', fp);
	size_t ticketCounter = ticketCount(fp);
	struct ticket** tickets;
	tickets = (struct ticket **) malloc(len * sizeof(struct ticket**));
	//initialize list
	for (int i = 0; i < len; i++){
		tickets[i] = NULL;
	}
	char* bufPointer = buffer;
	char* fields[] = {",\"id\":",  ",\"created_at\":", ",\"updated_at\":", 
		",\"subject\":", ",\"description\":", ",\"priority\":", ",\"status\":"};
	char* endpoints[] = {",\"external_id\":", ",\"updated_at\":", ",\"type\":", 
		",\"raw_subject\":", ",\"priority\":", ",\"status\":", ",\"recipient\":"};
	for (int i = 0; i < ticketCounter; i++){
		tickets[i]  = (struct ticket*) malloc(sizeof(struct ticket));
		//loop through each field in the array, parse next instance of that field and allocate
		//that to memory, assign it to the currently open ticket.
		for (int j = 0; j < 7; j++){
			bufPointer = strstr(bufPointer, fields[j]);
			fillTicketField(tickets[i], j, fields, endpoints, bufPointer);
		}

	}
	free(buffer);
	return tickets;
}
/* Frees all memory allocated to the heap for each ticket in a list of tickets.
 *
 * parameter: 
 * struct ticket **tickets, a pointer to a group of pointers to tickets.
 */
void freeAll(struct ticket **tickets){
	while (*tickets){
		free((*tickets) -> id);
		free((*tickets) -> created_at);
		free((*tickets) -> updated_at);
		free((*tickets) -> subject);
		free((*tickets) -> description);
		free((*tickets) -> priority);
		free((*tickets) -> status);
		free(*(tickets++));
	}
}

