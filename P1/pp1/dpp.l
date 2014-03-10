%{
#include <string.h>
#include <map>
#include "scanner.h"
#include "utility.h" // for PrintDebug()
#include "errors.h"
#include <iostream>

using namespace std;
typedef std::map<std::string, std::string> TStrStrMap;
typedef std::pair<std::string, std::string> TStrStrPair;
static void saveReplacement(char*, char*);
static void toReplace(char*);
char* oneName;
TStrStrMap map_NR;
int num_lines = 1, num_chars = 1;
struct yyltype yylloc; 
static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();
%}
SIMPLE_COMMENT (\/\/+.*\n)
MULTI_COMMENT (\/\*([^\*]|[\r\n]|(\*+([^\*\/]|[\r\n])))*\*+\/) 


%x DEFINE_BEGIN
%x DEFINE_NAME
%x REPLACEMENT

%%
\n                      {printf("\n");num_chars = 1; num_lines++; }
	/* S0 TO S1*/
<INITIAL>(^|[:space:]*)#define 		{BEGIN(DEFINE_BEGIN);
                        //printf("------ #define found\n");
                        }
<INITIAL>(^|[:space:]*)#[A-Z]+ 		{BEGIN(REPLACEMENT);
                        //printf("------ #NAME found %s\n",yytext); 
                        toReplace(yytext);
                        }
	/* S1 TO SN*/
<DEFINE_BEGIN>[A-Z]+    {BEGIN(DEFINE_NAME); oneName = strdup(yytext);
                        //printf("------ NAME found %s\n",yytext);
                        }
<DEFINE_BEGIN>[0-9a-z\_]+[^A-Z]+\n	{//printf("------ INVALID found %s\n",yytext);
                        BEGIN(INITIAL);
                        printf("\n");
                        ReportError::InvalidDirective(num_lines);
                        num_lines++;}
<DEFINE_NAME>.+			{
                        //printf("------ REPLACEMENT found\n");
                        saveReplacement(oneName,yytext);}
	/* RETURN TO SO*/
<DEFINE_BEGIN>\n 		{BEGIN(INITIAL);printf("\n");num_lines++;}
<DEFINE_NAME>\n 		{BEGIN(INITIAL);printf("\n");num_lines++;}
<REPLACEMENT>\n			{BEGIN(INITIAL);printf("\n");num_lines++;}

	/*COMMENT MATCH*/
{SIMPLE_COMMENT} {printf("\n");}	
{MULTI_COMMENT} {
				char *p;
				for (p = yytext; *p; p++) {
        			if (*p == '\n') printf("\n");num_lines++; // walk through the string, increase the count if found
    			}
				}


%%

static void DoBeforeEachAction(){
 	yylloc.first_line = yylloc.last_line = num_lines;
 	yylloc.first_column = num_chars;
  	yylloc.last_column = num_chars + yyleng - 1;
 	num_chars = num_chars + yyleng;
}
static void saveReplacement(char* name, char* replac){
    
    replac++;
    //printf("SAVE %s:%s\n",name, replac);map<string,string>::const_iterator it = map_NR.find(name);
    map<string,string>::const_iterator it = map_NR.find(name);
    if(it != map_NR.end())
        map_NR.erase(it);
    map_NR.insert(TStrStrPair(name, replac));
}

static void toReplace(char* name){
    name++; 
    //printf("REPACING %s\n",name);
    map<string,string>::const_iterator it = map_NR.find(name);
    if(it != map_NR.end()){
    	printf("%s", it->second.c_str());
    }else{
        //printf("NOT FOUND %s\n",name);
        num_lines++;
        printf("\n");
        ReportError::InvalidDirective(num_lines);
    }

}