/* File: ast.cc
 * ------------
 */

#include "ast.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h> // strdup
#include <stdio.h>  // printf
#include "ast_stmt.h"
#include "errors.h"



Node::Node(yyltype loc) {
    location = new yyltype(loc);
    parent = NULL;
}

Node::Node() {
    location = NULL;
    parent = NULL;
}
	 
void Node::Print(int indentLevel, const char *label) {
    const int numSpaces = 3;
    printf("\n");
    if (GetLocation())
        printf("%*d", numSpaces, GetLocation()->first_line);
    else
        printf("%*s", numSpaces, "");
    printf("%*s%s%s: ", indentLevel*numSpaces, "",
           label? label : "", GetPrintNameForNode());
   PrintChildren(indentLevel);
}


void Identifier::PrintChildren(int indentLevel) {
    printf("%s", name);
}


Identifier::Identifier(yyltype loc, const char *n) : Node(loc) {
    name = strdup(n);
} 
// look for declaration from inner most scope to global scope
Decl *Identifier::CheckIdDecl() {
  Decl *decl = NULL;
  Node *parent = this->GetParent();
  while (parent)
    {
      Hashtable<Decl*> *scope_table = parent->GetScopeTable();
      if (scope_table != NULL)
	{
	  if ((decl = scope_table->Lookup(this->name)) != NULL)
	    return decl;
	}
      parent = parent->GetParent();
    }

  decl = Program::global_table->Lookup(this->name);

  return decl;
}

// look for declaration in the provided scope
Decl *Identifier::CheckIdDecl(Hashtable<Decl*> *scope_table, const char *name)
{
  Decl *decl = NULL;
  if (scope_table)
    decl = scope_table->Lookup(name);
  return decl;
}

