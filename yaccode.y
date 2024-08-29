%{
	#include<stdio.h>
	int valid = 1;
%}

%token num id op

%%
start: id'='s;|s;
s: id x;
	| num x
	| '-' num x
	| '('s')'x
	;
x: op s
	|'-' s
	|
	;
%%
int yyerror() {
	valid = 0;
	printf("\n invalid Expression\n");
	return 0;
}

int main() {
	printf("Enter the expression: ");
	yyparse();
	if(valid) {
		printf("\n valid expression \n");
	}
}
