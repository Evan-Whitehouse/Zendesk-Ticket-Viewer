#!/bin/sh
domain=
email=
password=
curl --get -f -u ${email}:${password} https://${domain}.zendesk.com/api/v2/incremental/tickets.json?start_time=0 > tickets.json
clear
