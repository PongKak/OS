#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE				1024
#define MAXARGS			128
#define MAXPATH			1024
#define MAXTHREAD		10


char prompt[] = "myshell>";
const char delim[] = " \t\n";

void process_cmd(char* cmdline);
int parse_line(char* cmdline, char** argv);

int main(void){

	char cmdline[MAXLINE];

	while (1){

		printf("%s", prompt);
		fflush(stdout);

		if (fgets(cmdline, MAXLINE, stdin) == NULL){
			return 1;
		}

		process_cmd(cmdline);

		fflush(stdout);
	}



		return 0;
}

void process_cmd(char *cmdline){
	int argc;
	char* argv[MAXARGS];

	argc = parse_line(cmdline, argv);
	
	if (argc == 0)
		return;




	printf("word count : %d\n", argc);
	/*
	if (builtin_cmd(argc, argv) == 0){
		//내장 명령 처리를 완료하고 리턴
		return;
	}
	*/

}

int parse_line(char* cmdline, char** argv){

	int number=0;
	argv[0]= strtok(cmdline, delim);


	if (argv[0] == NULL)
		return 0;

	while (1){
		argv[number] = strtok(NULL, delim);
		if (argv[number] == NULL)
			break;

		++number;

	}




	return number;
}