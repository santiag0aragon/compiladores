/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>

#include "errors.h"


IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}
   
  
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}
     
FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}


Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}


void Call::CheckArguments(FnDecl *fndecl) {
  List<VarDecl*> *formals = fndecl->GetFormals();
  int formals_num = formals->NumElements();
  int args_num = this->actuals->NumElements();
  if (formals_num != args_num)
    {
		ReportError::NumArgsMismatch(this->field, formals_num, args_num);
		return;
    }
  else
    {
		for (int i = 0; i < formals_num; i++)
			{
			VarDecl *vardecl = formals->Nth(i);
			const char *expected = vardecl->GetTypeName();
			Expr *expr = this->actuals->Nth(i);
			const char *given = expr->GetTypeName();
			
			if (given && expected)
				{
				Decl *gdecl = Program::global_table->Lookup(given);
				Decl *edecl = Program::global_table->Lookup(expected);
				
				if (gdecl && edecl) // objects
					{
					if (strcmp(given, expected))
						if (typeid(*gdecl) == typeid(ClassDecl))
							{
							ClassDecl *gcldecl = dynamic_cast<ClassDecl*>(gdecl);
							if (!gcldecl->IsCompatibleWith(edecl))
								ReportError::ArgMismatch(expr, (i+1), new Type(given), new Type(expected));
							}
					}
				else if (edecl && strcmp(given, "null")) // null arguments
					ReportError::ArgMismatch(expr, (i+1), new Type(given), new Type(expected));
				else if (gdecl == NULL && edecl == NULL && strcmp(given, expected)) // non-object arguments
					ReportError::ArgMismatch(expr, (i+1), new Type(given), new Type(expected));
				}
			}
    }
}

 

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}


NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}

       
