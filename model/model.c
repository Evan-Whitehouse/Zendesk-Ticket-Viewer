#include "ticket.h"
#include "parseTickets.h"
#include <stdio.h>
#include <string.h>

int ticketCount(FILE *fp){
	char *buffer = NULL;
	const char count[] = ",\"count\":";
	size_t len;
	getdelim( &buffer, &len, '\0', fp);
	char *index = strstr(buffer, count);
	char num[4] = {'0','0','0','\0'};
	index = &(index[9]);
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


struct ticket * parseTicket(FILE *fp){
	return NULL;
}

int main(){
	FILE *fp = fopen("tickets.json", "r");
	int x = ticketCount(fp);
	printf("%d \n", x);
	return 0;
}
