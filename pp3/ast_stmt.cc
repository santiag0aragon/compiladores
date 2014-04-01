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

Hashtable<Decl*> *Program::global_table  = new Hashtable<Decl*>;

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
          *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */
  for (int i = 0; i < this->decls->NumElements(); i++)//Stmt
    this->decls->Nth(i)->Check();
  if (this->decls)//decl
    {
      for (int i = 0; i < this->decls->NumElements(); i++)
	{
          Decl *cur = decls->Nth(i);
          Decl *prev;
          const char *name = cur->GetID()->GetName();
	  if (name)
	    {
	      if ((prev = Program::global_table->Lookup(name)) != NULL)
		ReportError::DeclConflict(cur, prev);
	      else
		scope_table->Enter(name, cur);
	    }
	}
      for (int i = 0; i < this->decls->NumElements(); i++)
	this->decls->Nth(i)->Check();
      

}
}
StmtBlock::StmtBlock(List<VarDecl*>* d, List<Stmt*>* s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
    this->scope_table  = new Hashtable<Decl*>;
}
void StmtBlock::Check(){
  if (this->stmts) //stmt
    {
      for (int i = 0; i < this->stmts->NumElements(); i++)
        {
          Stmt *stmt = this->stmts->Nth(i);
          stmt->Check();
        }
    }
  if (this->decls)//decl
    {
      for (int i = 0; i < this->decls->NumElements(); i++)
        {
	  VarDecl *cur = this->decls->Nth(i);
	  Decl *prev;
	  const char *name = cur->GetID()->GetName();
	  if (name)
	    {
	      if ((prev = this->scope_table->Lookup(name)) != NULL)
		{
		  ReportError::DeclConflict(cur, prev);
		}
	      else
		{
		  scope_table->Enter(name, cur);
		  cur->Check();
		}
	    }
        }
    }
  if (this->stmts)
    {
      for (int i = 0; i < this->stmts->NumElements(); i++)
        {
          Stmt *stmt = stmts->Nth(i);
          stmt->Check();
        }
    }

}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
  }
void ConditionalStmt::Check() {
  this->test->Check();//stmt
  if (strcmp(this->test->GetTypeName(), "bool"))
    ReportError::TestNotBoolean(this->test);

  this->body->Check();


  //this->body->Check();//decl
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}
void ForStmt::Check() {
  if (this->init)//stmt
    this->init->Check();
  if (this->step)
    this->step->Check();
  ConditionalStmt::Check();
}
void WhileStmt::Check() {
  ConditionalStmt::Check();
}
IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}
void IfStmt::Check() {
  ConditionalStmt::Check();
  if (this->elseBody)
    this->elseBody->Check();
}


void BreakStmt::Check() {
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
  
void ReturnStmt::Check() {

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
      this->expr->Check();
      const char *given = expr->GetTypeName();

      if (given && expected)
        {
          Decl *gdecl = Program::global_table->Lookup(given);
          Decl *edecl = Program::global_table->Lookup(expected);

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
PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}
void PrintStmt::Check() {
  if (this->args)
    {
      for (int i = 0; i < this->args->NumElements(); i++)
        {
          Expr *expr = this->args->Nth(i);
          expr->Check();
          const char *typeName = expr->GetTypeName();
          if (typeName && strcmp(typeName, "string") && strcmp(typeName, "int") && strcmp(typeName, "bool"))
            ReportError::PrintArgMismatch(expr, (i+1), new Type(typeName));
        }
    }
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
void DefaultStmt::Check() {
  if (this->stmts)//stmt
    {
      for (int i = 0; i < this->stmts->NumElements(); i++)
        {
          Stmt *stmt = this->stmts->Nth(i);
          stmt->Check();
        }
    }

/*  if (this->stmts)//decl
    {
      for (int i = 0; i < this->stmts->NumElements(); i++)
        {
          Stmt *stmt = this->stmts->Nth(i);
          stmt->Check();
        }
    }*/
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
void SwitchStmt::Check() {
  if (this->expr)//Stmt
    this->expr->Check();

  if (this->cases)
    {
      for (int i = 0; i < this->cases->NumElements(); i++)
        {
          CaseStmt *stmt = this->cases->Nth(i);
          stmt->Check();
        }
    }

  if (this->defaults)
    this->defaults->Check();

/*  if (this->cases)//decl
    {
      for (int i = 0; i < this->cases->NumElements(); i++)
        {
          CaseStmt *stmt = this->cases->Nth(i);
          stmt->Check();
        }
    }

  if (this->defaults)
    this->defaults->Check();*/
}

