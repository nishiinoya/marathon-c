#ifndef HEADER_H
#define HEADER_H

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void mx_printerr(const char *s);
int mx_strlen(const char *s) ;
#endif
