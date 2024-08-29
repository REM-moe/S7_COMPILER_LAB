#include<stdio.h>
#include<string.h>

#define FALSE 0
#define TRUE 1

	int singlecom = 0; int operator_count = 0; int comment_count = 0;
	int doublecom = 0; int delimiter_count = 0; int keyword_count = 0;
	char token[100];

int isOperator( char c){
	// check if operator
	if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){ 
		printf("FOUND OPERATOR: %c \n", c);
		operator_count++;
		return TRUE;
	}
	return FALSE;
}

int isDelimiter(char c) {
	if( c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || 
	    c == '"' || c == ':' || c == ';' || c == ')'|| c == '(' ) {
	    			printf("FOUND DELIMITER: %c \n", c);
				delimiter_count++;
				return TRUE;
	}
	return FALSE;
}

int isKeyword(char c[]) {
	if( strcmp(c, "int") == 0 || strcmp(c, "char") == 0|| strcmp(c, "float") == 0 || strcmp(c, "printf") == 0 ||
	    strcmp(c, "for") == 0 || strcmp(c, "while") == 0 || strcmp(c, "if") == 0 || strcmp(c, "else") == 0 ) {
		  	keyword_count++;
		  	printf("FOUND KEYWORD: %s\n", c);
		  	strcpy(token, " ");
		  	return TRUE;
	}
	if(strcmp(c, " ") != 0 )
		printf("FOUND identifier: %s\n", c);
	strcpy(token, " ");
	return FALSE;
}

int main() {
	FILE *f;
	char line[100];
		
	f = fopen("file.txt", "r");
	int index = 0;

	while(fgets(line, sizeof(line), f)) {	
				strcpy(token, " ");
				// check if a line is a single line comment
				if((line[0] == '/' && line[1] == '/' )) {
					comment_count++;
					continue;
				}
				
				// check for operator
				for(int j = 0; j<strlen(line); j++) {
					if(isDelimiter(line[j]) == TRUE || isOperator(line[j]) == TRUE) {
						// we dont do anything
					} 
					else if(line[j] == ' ' || line[j] == '\n') {
						if(isKeyword(token)) {
							index = 0;
						}
					}
					else {
						token[index] = line[j];
						index++;
					}
				}
	}
			printf("\n**************\nNo of operators: %d\n", operator_count);
			printf("No of comments: %d\n", comment_count);
			printf("No of delimiters: %d\n", delimiter_count);
			printf("No of keywords: %d\n", keyword_count);		
			fclose(f);
}

