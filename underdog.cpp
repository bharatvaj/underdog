#define UNDERDOG "UNDERDOG"
//Program analyzer for testing vulnerabilities in both binary and source code formats
#include<iostream>
#include <signal.h>
#include "clog.h"
#include "network_utils.h"
#include "shell.h"
#include "ui.h"

int help(int, char **);

void exit_handler(int sig){
	log_inf(UNDERDOG, "Writing settings to DB...");
	exit(EXIT_SUCCESS);
}
int exit_self(int count, char **args){
	exit_handler(SIGINT);
	return 0;
}
int scan_vuln(int count, char **args){
	return -1;
}

job jobs[] = {
	{"help", "shows this help message", help},
	{"exit", "exits from this shell", exit_self},
	{"scan", "scans the given file for vulnerabilities", scan_vuln}
};
int jlen = sizeof(jobs)/sizeof(job);

int help(int count, char **args){
	return sh_help(jlen, jobs);
}

int main(int argc, char *argv[]){
	signal(SIGINT, exit_handler);
	start_shell(jlen, jobs, "underdog> ");
	return 0;
}
