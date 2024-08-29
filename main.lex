%%
a {printf("A");}
b {printf("B");}
c {printf("C");}
. {printf("%s\n", yytext);}
\n {return 0;}
%%

int main() {
	yylex();
}
