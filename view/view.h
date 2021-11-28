#include "../model/ticket.h"
#ifndef VIEW_H
#define VIEW_H

void printLabels();

void displayMenuStart();


void displayMenuMiddle();

void displayMenuEnd();

void displayMenuSingleStruct();

void displayTicketArray(int page, int ticketCount, struct ticket **tickets);

void displaySingleTicket(int id, struct ticket **tickets);
#endif
