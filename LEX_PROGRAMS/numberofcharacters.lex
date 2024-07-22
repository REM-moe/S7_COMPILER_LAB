%{

%}

%%
[a-z/A-Z]+	{if(yyleng >5 && yyleng < 100) printf("YES WORD IS VALID\n"); else printf("Word is Not Valid\n");}
.	{}
\n	{return 0;}
%%
int main() {
	yylex();
	return 0;
}
