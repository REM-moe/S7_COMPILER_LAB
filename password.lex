%%

[a-z 0-9]+"@"[a-z 0-9]+["."]+[a-z]+ {
	printf("valid email\n");
}

[0-9]+ {
	if(yyleng==10) {
		printf("valid phoneno\n");
	}else {
		printf("\ninvalid phone number\n");
	}
}

\n {

}

.* {
	printf("\n not valid\n");
}

%%
int main() {

	yylex();
	return 0;
}
