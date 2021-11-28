#include "ticket.h"
#ifndef PARSE_TICKETS_H
#define PARSE_TICKETS_H

struct ticket ** parseTickets(FILE *fp);

size_t ticketCount(FILE *fp);

void fillTicketField(struct ticket *currentTicket, int index, char **fields, char **endpoints, char*buffer);

void freeAll(struct ticket **tickets);

#endif
