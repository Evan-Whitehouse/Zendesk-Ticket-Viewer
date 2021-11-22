#ifndef TICKET_H
#define TICKET_H

struct ticket {
	char *id;
	char *subject;
	char *updated_at;
	char *created_at;
	char *priority;
	char *status;
	char *description;
	char *submitter_id;
};

#endif
