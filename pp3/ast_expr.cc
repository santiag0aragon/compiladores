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
  Expr::type = Type::intType;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
	value = val;
  Expr::type = Type::doubleType;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
	value = val;
  Expr::type = Type::boolType;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
	Assert(val != NULL);
	value = strdup(val);
  Expr::type = Type::stringType;
}

NullConstant::NullConstant(yyltype loc)
: Expr(loc) {
  Expr::type = Type::nullType;
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


void ArithmeticExpr::CheckStmts() {
  const char *lt = NULL, *rt = NULL;
  if (this->left) // binary
    {
		this->left->CheckStmts();
		lt = this->left->GetTypeName();
    }
	
  this->right->CheckStmts();
  rt = this->right->GetTypeName();
  if (lt && rt) // binary
    {
		if ((strcmp(lt, "int") && strcmp(lt, "double")) ||
				(strcmp(rt, "int") && strcmp(rt, "double")) ||
				(strcmp(lt, rt)))
			ReportError::IncompatibleOperands(this->op, new Type(lt), new Type(rt));
    }
  else if (rt) // unary
    {
		if (strcmp(rt, "int") && strcmp(rt, "double"))
			ReportError::IncompatibleOperand(this->op, new Type(rt));
    }
}

void RelationalExpr::CheckStmts() {
  this->left->CheckStmts();
  const char *lt = this->left->GetTypeName();
  this->right->CheckStmts();
  const char *rt = this->right->GetTypeName();
  if (lt && rt) // binary
    {
		if ((strcmp(lt, "int") && strcmp(lt, "double")) ||
				(strcmp(rt, "int") && strcmp(rt, "double")) ||
				(strcmp(lt, rt)))
			ReportError::IncompatibleOperands(this->op, new Type(lt), new Type(rt));
    }
}

void EqualityExpr::CheckStmts() {
  this->left->CheckStmts();
  this->right->CheckStmts();
  const char *lt = this->left->GetTypeName();
  const char *rt = this->right->GetTypeName();
  if (lt && rt)
    {
		Decl *ldecl = Program::scope_table->Lookup(lt);
		Decl *rdecl = Program::scope_table->Lookup(rt);
		
		if (ldecl && rdecl) // objects
			{
			if (!strcmp(lt, rt))
				return;
			else if (typeid(*ldecl) == typeid(ClassDecl))
				{
	      ClassDecl *lcldecl = dynamic_cast<ClassDecl*>(ldecl);
	      if (lcldecl->IsCompatibleWith(rdecl))
					return;
				}
			else if (typeid(*rdecl) == typeid(ClassDecl))
				{
	      ClassDecl *rcldecl = dynamic_cast<ClassDecl*>(rdecl);
	      if (rcldecl->IsCompatibleWith(ldecl))
					return;
				}
			}
		else if (ldecl && !strcmp(rt, "null")) // object = null
			return;
		else if (!strcmp(lt, rt)) // non-objects
			return;
    }
  ReportError::IncompatibleOperands(this->op, new Type(lt), new Type(rt));
}

void LogicalExpr::CheckStmts() {
  const char *lt = NULL, *rt = NULL;
  if (this->left)
    {
		this->left->CheckStmts();
		lt = this->left->GetTypeName();
    }
  this->right->CheckStmts();
  rt = this->right->GetTypeName();
  if (lt && rt)
    {
		if (strcmp(lt, "bool") || strcmp(rt, "bool"))
			ReportError::IncompatibleOperands(this->op, new Type(lt), new Type(rt));
    }
  else if (rt)
    {
		if (strcmp(rt, "bool"))
			ReportError::IncompatibleOperand(this->op, new Type(rt));
    }
	
}

void AssignExpr::CheckStmts() {
	PrintDebug("debug","CheckStmts  left %s \n",this->left->GetPrintNameForNode());
  this->left->CheckStmts();
	PrintDebug("debug","Checking right%s\n",this->left->GetPrintNameForNode());
  this->right->CheckStmts();
	const char *lt = this->left->GetTypeName();
  const char *rt = this->right->GetTypeName();
	
  if (lt && rt)
    {
		Decl *ldecl = Program::scope_table->Lookup(lt);
		Decl *rdecl = Program::scope_table->Lookup(rt);
		
		if (ldecl && rdecl) // objects
			{
			if (!strcmp(lt, rt))
				return;
			else if (typeid(*rdecl) == typeid(ClassDecl))
				{
	      ClassDecl *rcldecl = dynamic_cast<ClassDecl*>(rdecl);
	      if (rcldecl->IsCompatibleWith(ldecl))
					return;
				}
			}
		else if (ldecl && !strcmp(rt, "null")) // object = null
			return;
		else if (!strcmp(lt, rt)) // non-objects
			return;
		PrintDebug("debug","rt:%s lt:'%s' \n", rt,lt);
		ReportError::IncompatibleOperands(this->op, new Type(lt),new Type(rt));
    }
}

void This::CheckStmts() {

  Node *parent = this->GetParent();
	
  while (parent)
    {
		if (typeid(*parent) == typeid(ClassDecl))
			{
			this->type = new NamedType(dynamic_cast<ClassDecl*>(parent)->GetID());
			return;
			}
		PrintDebug("debug","Checking this parent%s \n",parent->GetPrintNameForNode());
		//Hashtable<Decl*> *scope_table = parent->GetScopeTable();
			//	if(scope_table)
			//	scope_table->printTable(); //uncomment
		parent = parent->GetParent();
    }
  ReportError::ThisOutsideClassScope(this);
}


ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
	(base=b)->SetParent(this);
	(subscript=s)->SetParent(this);
}

Type *ArrayAccess::GetType() {
  Type *type = base->GetType();
  if (type)
    return type->GetElemType();
  else
    return NULL;
}

const char *ArrayAccess::GetTypeName() {
  Type *type = this->base->GetType();
  if (type)
    return type->GetElemType()->GetTypeName();
  else
    return NULL;
}

void ArrayAccess::CheckStmts() {
		//PrintDebug("debug", "=====================Array Access::CHECK\n");
  this->base->CheckStmts();
  if (typeid(*this->base->GetType()) != typeid(ArrayType))
    ReportError::BracketsOnNonArray(this->base);
  this->subscript->CheckStmts();
  if (strcmp(this->subscript->GetTypeName(), "int"))
    ReportError::SubscriptNotInteger(this->subscript);
}

FieldAccess::FieldAccess(Expr *b, Identifier *f)
: LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
	Assert(f != NULL); // b can be be NULL (just means no explicit base)
	base = b;
	if (base) base->SetParent(this);
	(field=f)->SetParent(this);
}
/*
Type* FieldAccess::GetType() {
	
	if (this->base != NULL) {
		return   base->GetType();
	}
	else{
		Decl *d;
		d= this->field->CheckIdDecl();
		if (d == NULL)
			return Type::errorType;
	if (dynamic_cast<VarDecl*>(d) == NULL)
		return Type::errorType;

	return static_cast<VarDecl*>(d)->GetType();
	}
}
*/
const char *FieldAccess::GetTypeName()
{
	PrintDebug("debug", "=====================FieldAccess::GETypeName\n");
	
	if (this->type){
		PrintDebug("debug", "=====================FieldAccess::GETypeName IF \n");
			//		Decl *decl = this->field->CheckIdDecl();
			//const char *typeName = decl->GetTypeName();
		PrintDebug("debug","====================FieldAccessGETtypeName type:%s",this->type->GetTypeName());
		return this->type->GetTypeName();
	}
	else{
		PrintDebug("debug", "=====================FieldAccess::GETypeName ELSE\n");
		return NULL;
	}
}

void FieldAccess::CheckStmts() {
		PrintDebug("debug","=====================FieldAccess::CHECK \n");
  Decl *decl = NULL; // to keep the result of looking up the symbol table
  if (this->base)
    {
		this->base->CheckStmts();  // whether base is declared
		const char *name = this->base->GetTypeName();
		PrintDebug("debug","=====================FieldAccess::CHECK base typename %s\n",name);

		if (name)
			{
			Node *parent = this->GetParent();
			Decl *cldecl = NULL; // look for ClassDecl
													 // whether the base is this
													 // otherwise the variable is inaccessible
			while (parent)
				{
	      Hashtable<Decl*> *scope_table = parent->GetScopeTable();
/*				if(scope_table){

				}*/
				
				if (scope_table)
					if ((cldecl = scope_table->Lookup(name)) != NULL)
						{
						PrintDebug("debug","=====================FieldAccess::Printing scope table for ...\n");
						//parent->Print(1); //uncomment
						//scope_table->printTable();  //uncomment
						PrintDebug("debug","\n===================================\n");

						
						
						

						decl = this->field->CheckIdDecl(cldecl->GetScopeTable(), this->field->GetName());
						PrintDebug("debug", "=====================FieldAccess:: Trying %s, %s,%s,%S",this->field->GetName());
						if ((decl == NULL) || (typeid(*decl) != typeid(VarDecl))){
							if(decl == NULL)
								PrintDebug("debug","=====================FieldAccess::Error 1.1 \n");
						if (typeid(*decl) != typeid(VarDecl))
								PrintDebug("debug","=====================FieldAccess::Error 1.2 \n");
							ReportError::FieldNotFoundInBase(this->field, new Type(name));
						}
						}
				PrintDebug("debug","=====================FieldAccess::Error 1 \n");
	      parent = parent->GetParent();
				}
			PrintDebug("debug","\n===================================\n");
			
			if (cldecl == NULL)
				{
	      if ((cldecl = Program::scope_table->Lookup(name)) != NULL) // look up global symbol table
	        {
					decl = this->field->CheckIdDecl(cldecl->GetScopeTable(), this->field->GetName());
					if ((decl != NULL) && (typeid(*decl) == typeid(VarDecl))){
						PrintDebug("debug","=====================FieldAccess::Error 2 \n");
						ReportError::InaccessibleField(this->field, new Type(name)); // data member is private
						
					}else{
						PrintDebug("debug","=====================FieldAccess::Error 3 \n");
						ReportError::FieldNotFoundInBase(this->field, new Type(name)); // no such field
						
					}
	        }
	      else{ // for those with no symbol tables, e.g. int[]
					PrintDebug("debug","=====================FieldAccess::Error 4 \n");
					ReportError::FieldNotFoundInBase(this->field, new Type(name));
				}
				}
			}
		}
  else
    {
				
      // no base, just check whether the field is declared
		//parent = this->GetParent()->GetParent();
		//if(parent != NULL){
		//}
		decl = this->field->CheckIdDecl();
		if (decl == NULL || typeid(*decl) != typeid(VarDecl))
			{
			PrintDebug("debug","=====================FieldAccess::NOT FOUND IN GLOBAL %s \n",decl);
			ReportError::IdentifierNotDeclared(this->field, LookingForVariable);
			decl = NULL; // to force not to get the type
									 // and avoid cascading error reports
			}
    }
  if (decl != NULL)
    this->type = decl->GetType();
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
				Decl *gdecl = Program::scope_table->Lookup(given);
				Decl *edecl = Program::scope_table->Lookup(expected);
				
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

void Call::CheckStmts() {
	
	PrintDebug("debug", "==================CALL::CHECK");
  if (this->actuals)
    {
		for (int i = 0; i < actuals->NumElements(); i++)
			this->actuals->Nth(i)->CheckStmts();
    }
	
  Decl *decl = NULL;
	
  if (this->base)
    {
		this->base->CheckStmts();
		const char *name = this->base->GetTypeName();
      // all the methods are public
      // no need to check the accessibility
		if (name)
			{
			if ((decl = Program::scope_table->Lookup(name)) != NULL)
				{
	      decl = this->field->CheckIdDecl(decl->GetScopeTable(), this->field->GetName());
	      if ((decl == NULL) || (typeid(*decl) != typeid(FnDecl)))
					ReportError::FieldNotFoundInBase(this->field, new Type(name));
	      else
					CheckArguments(dynamic_cast<FnDecl*>(decl));
				}
			else if ((typeid(*this->base->GetType()) == typeid(ArrayType))
							 && !strcmp(this->field->GetName(), "length")) // arr.length() is supported
				{
	      this->type = Type::intType;
				}
			else
				{
				PrintDebug("debug", "Call::error 4");
	      ReportError::FieldNotFoundInBase(this->field, new Type(name));
				}
			}
    }
  else
    {
      // no base, just check whether the field is declared
		decl = this->field->CheckIdDecl();
		if ((decl == NULL) || (typeid(*decl) != typeid(FnDecl)))
			{
			ReportError::IdentifierNotDeclared(this->field, LookingForFunction);
			decl = NULL; // to force not to get the type
									 // and avoid cascading error reports
			}
		else
			CheckArguments(dynamic_cast<FnDecl*>(decl));
    }
  if (decl != NULL)
    this->type = decl->GetType(); // returnType
}




NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) {
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

void NewExpr::CheckStmts() {
  if (this->cType)
    {
		const char *name = this->cType->GetTypeName();
		if (name)
			{
			Decl *decl = Program::scope_table->Lookup(name);
			if ((decl == NULL) || (typeid(*decl) != typeid(ClassDecl)))
				ReportError::IdentifierNotDeclared(new Identifier(*this->cType->GetLocation(), name), LookingForClass);
			}
    }
}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
	Assert(sz != NULL && et != NULL);
	(size=sz)->SetParent(this);
	(elemType=et)->SetParent(this);
}

const char *NewArrayExpr::GetTypeName() {
	if (this->elemType)
    {
		std::string delim = "[]";
		std::string str = this->elemType->GetTypeName();// + delim;
		str = str.append(delim);
			//		const char *arrType = str.c_str();
			//PrintDebug("debug", "ArrayType: %s\n",arrType);
		return str.c_str();;
    }
  else
    return NULL;
}

void NewArrayExpr::CheckStmts() {
  this->size->CheckStmts();
  if (strcmp(this->size->GetTypeName(), "int"))
    ReportError::NewArraySizeNotInteger(this->size);
  this->elemType->CheckTypeError();
}

ReadLineExpr::ReadLineExpr(yyltype loc)
: Expr(loc) {
  Expr::type = Type::stringType;
}

ReadIntegerExpr::ReadIntegerExpr(yyltype loc)
: Expr(loc) {
  Expr::type = Type::intType;
}

PostfixExpr::PostfixExpr(yyltype loc, LValue *lv, Operator *op)
: Expr(loc) {
  Assert(lv != NULL && op != NULL);
  (this->lvalue=lv)->SetParent(this);
  (this->optr=op)->SetParent(this);
}

void PostfixExpr::CheckStmts() {
  if (this->lvalue)
    {
		this->lvalue->CheckStmts();
		const char *name = this->lvalue->GetTypeName();
		if (strcmp(name, "int") && strcmp(name, "double"))
			ReportError::IncompatibleOperand(this->optr, this->lvalue->GetType());
    }
}
