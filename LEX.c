#include<stdio.h>
#include<string.h>

#define FALSE 0
#define TRUE 1

	int singlecom = 0; int operator_count = 0; int comment_count = 0;
	int doublecom = 0; int delimiter_count = 0; int keyword_count = 0;

int isOperator( char c){
	// check if operator
	if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%'){ 
		operator_count++;
		return TRUE;
	}
	return FALSE;
}

int isDelimiter(char c) {
	if( c == '{' || c == '}' || c == '[' || c == ']' || c == ',' || 
	    c == '"' || c == ':' || c == ';' || c == ')'|| c == '(' ) {
				delimiter_count++;
				return TRUE;
	}
	return FALSE;
}

int isKeyword(char c[]) {
	if (strcmp(c, "int") || strcmp(c, "char") || strcmp(c, "float") || strcmp(c, "printf") ||
	    strcmp(c, "for") || strcmp(c, "while") || strcmp(c, "if") || strcmp(c, "else")) {
		  	keyword_count++;
		  	printf("keyword %s\n", c);
			return TRUE;
	}
	return FALSE;
}


int main() {
	FILE *f;
	char line[100];
		
	f = fopen("file.txt", "r");
	int index = 0;
	char token[100];

	while(fgets(line, sizeof(line), f)) {	
				strcpy(token, " ");
				// check if a line is a single line comment
				if((line[0] == '/' && line[1] == '/' )){
					comment_count++;
					continue;
				}
				// check for operator
				for(int j = 0; j<strlen(line); j++) {
					if(isDelimiter(line[j]) == TRUE || isOperator(line[j]) == TRUE) {
						printf("\nfound: %c \n", line[j]);
					} 
					else if(line[j] == ' ' || line[j] == '\n') {
						if(isKeyword(token) == TRUE) {
							strcpy(token, " ");
							index = 0;
						}
					}
					else {
						token[index] = line[j];
						index++;
					}
				}
	}
			printf("\n No of operators: %d\n", operator_count);
			printf("\n No of comments: %d\n", comment_count);
			printf("\n No of delimiters: %d\n", delimiter_count);
			printf("\n No of keywords: %d\n", keyword_count);		
			fclose(f);
}
