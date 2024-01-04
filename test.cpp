#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <syslog.h>
int main() {
    openlog("test", LOG_PID, LOG_DAEMON);
    syslog(LOG_INFO, "Hello");
    closelog();
}