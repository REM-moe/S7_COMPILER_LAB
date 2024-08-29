%{ 
int COMMENT = 0;
%}


%%
#.* {
	// detect header files
	if(COMMENT != 1)
		printf("\n PREPROCESSOR DETECTED: %s\n", yytext);
	
}

"//".* {
	// comment the line do nothing
}

"/*" {
	// set flag = true so all the lines are commented
	if(COMMENT == 0)
	 COMMENT = 1;
}

"*/" { 
	// found the end of the comment block, reset flag
	COMMENT = 0;
}

[+|*|"-"|"="|"<"|">"|"<="|">="|"|"] {
	if(COMMENT != 1)
		printf("\nOPERATOR DETECTED: %s\n", yytext);
}

[{|}|(|)|;] {
	if(COMMENT != 1)
		printf("DELIMITER DETECTED: %s\n", yytext);
}

int|for|while|if|else|"else if"|float|char|return {
	if(COMMENT != 1)
		printf("KEYWORD DETECTED: %s\n", yytext);
}

[a-z|A-z]+[0-9]*[a-z|A-Z]* {
	if(COMMENT != 1)
		printf("IDENTIFIER DETECTED: %s\n", yytext);
}

[0-9]*[0-9+.0-9+]* {
	if(COMMENT != 1)
	printf("DIGIT DETECTED: %s\n", yytext);
}

["\n"|" "|' '|"\t"] {

}

%%
int main() {
	FILE *file = fopen("program.txt", "r");
	yyin = file;
	yylex();
	return 0;
}
