%{
	int count = 0;
%}

%%
[a-z/A-Z]+	{if(yyleng >5 && yyleng < 100) printf("YES WORD IS VALID\n"); else printf("Word is Not Valid\n"); count++;}
.	{}
\n	{return 0;}
%%
int main() {
	yylex();
	printf("NO OF WORDS: %d\n", count);
	return 0;
}
