/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
	//#include <typeinfo>
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"

Hashtable<Decl*> *Program::scope_table  = new Hashtable<Decl*>;

Program::Program(List<Decl*> *d) {
	Assert(d != NULL);
	(decls=d)->SetParentAll(this);
}
void Program::Check(){
	CheckDecl();
	CheckStmts();
}

void Program::CheckStmts(){
	PrintDebug("debug","=====================Program::CHECK stmt\n");
	for (int i = 0; i < this->decls->NumElements(); i++)
    this->decls->Nth(i)->CheckStmts();
}

void Program::CheckDecl() {
	/* pp3: here is where the semantic analyzer is kicked off.
	 *      The general idea is perform a tree traversal of the
	 *      entire program, examining all constructs for compliance
	 *      with the semantic rules.  Each node can have its own way of
	 *      checking itself, which makes for a great use of inheritance
	 *      and polymorphism in the node classes.
	 */
		PrintDebug("debug","-----INICIO\n");
		PrintDebug("debug","=====================Program::CHECK decl\n");
  if (this->decls)//decl
    {
		for (int i = 0; i < this->decls->NumElements(); i++)
			{
			//printf("=====================Program::CHECK decl %d\n",i);
			Decl *cur = decls->Nth(i);
			Decl *prev;
			const char *name = cur->GetID()->GetName();
			if (name)
				{
	      if ((prev = Program::scope_table->Lookup(name)) != NULL){
   				//printf("=====================Program::CHECK decl encontrado en prev %s\n",name);
          ReportError::DeclConflict(cur, prev);
        }
	      else
					PrintDebug("debug","=====================Program::CHECK decl guardando %s\n",name);
		      scope_table->Enter(name, cur);
					//scope_table->printTable();
				}
			}
		for (int i = 0; i < this->decls->NumElements(); i++){
			PrintDebug("debug","=====================Program::CHECK decl %d\n",i);
			this->decls->Nth(i)->CheckDecl();
		}
		}

}

StmtBlock::StmtBlock(List<VarDecl*>* d, List<Stmt*>* s) {
	Assert(d != NULL && s != NULL);
	(decls=d)->SetParentAll(this);
	(stmts=s)->SetParentAll(this);
	this->scope_table  = new Hashtable<Decl*>;
}

void StmtBlock::CheckStmts(){
	if (this->stmts)
    {
		for (int i = 0; i < this->stmts->NumElements(); i++)
			{
			Stmt *stmt = this->stmts->Nth(i);
			stmt->CheckStmts();
			}
    }
}
void StmtBlock::CheckDecl(){
	PrintDebug("debug","Checking StmtBlock %s \n",this->GetPrintNameForNode());
  if (this->decls)//decl
    {
			//printf("=====================StmtBlock::CHECK this->decls\n");
		for (int i = 0; i < this->decls->NumElements(); i++)
			{
			VarDecl *cur = this->decls->Nth(i);
			Decl *prev;
			const char *name = cur->GetID()->GetName();
			if (name)
				{
				if ((prev = this->scope_table->Lookup(name)) != NULL){
					ReportError::DeclConflict(cur, prev);
						
				}
	      else
					{
					scope_table->Enter(name, cur);
						//scope_table->printTable();
					PrintDebug("debug","=====================StmtBlock::CHECK Enter\n");
					cur->CheckDecl();
						
					}
				}
			}
    }
	if (this->stmts) //stmt
    {
		PrintDebug("debug","=====================StmtBlock::CHECK this->stms\n");
		for (int i = 0; i < this->stmts->NumElements(); i++)
			{
			PrintDebug("debug","=======================StmtBlock::Checking stmt %d\n",i);
			Stmt *stmt = this->stmts->Nth(i);
			stmt->CheckDecl();
			}
    }

}


ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) {
	Assert(t != NULL && b != NULL);
	(test=t)->SetParent(this);
	(body=b)->SetParent(this);
}

void ConditionalStmt::CheckStmts() {
  this->test->CheckStmts();
  if (strcmp(this->test->GetTypeName(), "bool"))
    ReportError::TestNotBoolean(this->test);
	
  this->body->CheckStmts();
}

void ConditionalStmt::CheckDecl() {

	this->body->CheckDecl();//decl
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) {
	Assert(i != NULL && t != NULL && s != NULL && b != NULL);
	(init=i)->SetParent(this);
	(step=s)->SetParent(this);
}

void ForStmt::CheckStmts() {
  if (this->init)//stmt
    this->init->CheckStmts();
  if (this->step)
    this->step->CheckStmts();
  ConditionalStmt::CheckStmts();
}

void WhileStmt::CheckStmts() {
  ConditionalStmt::CheckStmts();
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) {
	Assert(t != NULL && tb != NULL); // else can be NULL
	elseBody = eb;
	if (elseBody) elseBody->SetParent(this);
}

void IfStmt::CheckDecl() {
  ConditionalStmt::CheckDecl();
  if (this->elseBody)
    this->elseBody->CheckDecl();
}

void IfStmt::CheckStmts() {
  ConditionalStmt::CheckStmts();
  if (this->elseBody)
    this->elseBody->CheckStmts();
}

void BreakStmt::CheckStmts() {
  Node *parent = this->GetParent();
  while (parent)
    {
		if ((typeid(*parent) == typeid(WhileStmt)) ||
				(typeid(*parent) == typeid(ForStmt)) ||
				(typeid(*parent) == typeid(SwitchStmt)))
			return;
		parent = parent->GetParent();
    }
  ReportError::BreakOutsideLoop(this);
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) {
	Assert(e != NULL);
	(expr=e)->SetParent(this);
}

void ReturnStmt::CheckStmts() {
	
  const char *expected; //stmt
  Node *parent = this->GetParent();
  while (parent)
    {
		if (typeid(*parent) == typeid(FnDecl))
			expected = dynamic_cast<FnDecl*>(parent)->GetTypeName();
		parent = parent->GetParent();
    }
  if (this->expr)
    {
		this->expr->CheckStmts();
		const char *given = expr->GetTypeName();
		
		if (given && expected)
			{
			Decl *gdecl = Program::scope_table->Lookup(given);
			Decl *edecl = Program::scope_table->Lookup(expected);
			
			if (gdecl && edecl) // objects
				{
				if (!strcmp(given, expected))
					return;
				else if (typeid(*gdecl) == typeid(ClassDecl))
					{
					ClassDecl *gcldecl = dynamic_cast<ClassDecl*>(gdecl);
					if (gcldecl->IsCompatibleWith(edecl))
						return;
					}
				}
			else if (edecl && !strcmp(given, "null"))
				return;
			else if (!strcmp(given, expected))
				return;
			
			ReportError::ReturnMismatch(this, new Type(given), new Type(expected));
			}
    }
  else if (strcmp("void", expected))
    ReportError::ReturnMismatch(this, new Type("void"), new Type(expected));
}


CaseStmt::CaseStmt(IntConstant *ic, List<Stmt*> *sts)
: DefaultStmt(sts) {
  (this->intconst=ic)->SetParent(this);
}

DefaultStmt::DefaultStmt(List<Stmt*> *sts) {
	if (sts) (stmts=sts)->SetParentAll(this);
}

void DefaultStmt::PrintChildren(int indentLevel) {
	if (stmts) stmts->PrintAll(indentLevel+1);
}

void DefaultStmt::CheckDecl() {

	  if (this->stmts)//decl{
	 for (int i = 0; i < this->stmts->NumElements(); i++){
	 	Stmt *stmt = this->stmts->Nth(i);
	 	stmt->CheckDecl();
	 }
}

	
void DefaultStmt::CheckStmts() {
  if (this->stmts)//stmt
    {
		for (int i = 0; i < this->stmts->NumElements(); i++)
			{
			Stmt *stmt = this->stmts->Nth(i);
			stmt->CheckStmts();
			}
    }
	

}


SwitchStmt::SwitchStmt(Expr *e, List<CaseStmt*> *cs, DefaultStmt *ds) {
	Assert(e != NULL && cs != NULL);
	(expr=e)->SetParent(this);
	(cases=cs)->SetParentAll(this);
	if (ds) (defaults=ds)->SetParent(this);
}

void SwitchStmt::PrintChildren(int indentLevel) {
	expr->Print(indentLevel+1);
	cases->PrintAll(indentLevel+1);
	if (defaults) defaults->Print(indentLevel+1);
}

void SwitchStmt::CheckDecl() {
	
	  if (this->cases)//decl
	 {
	 for (int i = 0; i < this->cases->NumElements(); i++)
	 {
	 CaseStmt *stmt = this->cases->Nth(i);
	 stmt->CheckDecl();
	 }
	 }
	 
	 if (this->defaults)
	 this->defaults->CheckDecl();
}

void SwitchStmt::CheckStmts() {
	if (this->expr)//Stmt
	this->expr->CheckStmts();

	if (this->cases)
	{
		for (int i = 0; i < this->cases->NumElements(); i++)
			{
			CaseStmt *stmt = this->cases->Nth(i);
			stmt->CheckStmts();
			}
		}

	if (this->defaults)
		this->defaults->CheckStmts();
	
	}

void Program::PrintChildren(int indentLevel) {
	decls->PrintAll(indentLevel+1);
	printf("\n");
}
void StmtBlock::PrintChildren(int indentLevel) {
	decls->PrintAll(indentLevel+1);
	stmts->PrintAll(indentLevel+1);
}
void ForStmt::PrintChildren(int indentLevel) {
	init->Print(indentLevel+1, "(init) ");
	test->Print(indentLevel+1, "(test) ");
	step->Print(indentLevel+1, "(step) ");
	body->Print(indentLevel+1, "(body) ");
}

void WhileStmt::PrintChildren(int indentLevel) {
	test->Print(indentLevel+1, "(test) ");
	body->Print(indentLevel+1, "(body) ");
}
void IfStmt::PrintChildren(int indentLevel) {
	if (test) test->Print(indentLevel+1, "(test) ");
	if (body) body->Print(indentLevel+1, "(then) ");
	if (elseBody) elseBody->Print(indentLevel+1, "(else) ");
}
PrintStmt::PrintStmt(List<Expr*> *a) {
	Assert(a != NULL);
	(args=a)->SetParentAll(this);
}

void PrintStmt::PrintChildren(int indentLevel) {
	args->PrintAll(indentLevel+1, "(args) ");
}

void PrintStmt::CheckStmts() {
  if (this->args)
    {
		for (int i = 0; i < this->args->NumElements(); i++)
			{
			Expr *expr = this->args->Nth(i);
			expr->CheckStmts();
			const char *typeName = expr->GetTypeName();
			if (typeName && strcmp(typeName, "string") && strcmp(typeName, "int") && strcmp(typeName, "bool"))
				ReportError::PrintArgMismatch(expr, (i+1), new Type(typeName));
			}
    }
}

