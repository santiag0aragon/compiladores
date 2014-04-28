/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "hashtable.h"

class Decl;
class VarDecl;
class Expr;
class IntConstant;
  
class Program : public Node
{
  protected:
     List<Decl*> *decls;
     
  public:
     Program(List<Decl*> *declList);
		 void CheckStmts();
	   void CheckDecl();
		 void Check(); 
     static Hashtable<Decl*> *scope_table;
     const char *GetPrintNameForNode() { return "Program"; }
     void PrintChildren(int indentLevel);     
};

class Stmt : public Node
{
  public:
     Stmt() : Node() {}
     Stmt(yyltype loc) : Node(loc) {}
};

class StmtBlock : public Stmt 
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    Hashtable<Decl*> *scope_table; 
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);
    void CheckStmts();
    void CheckDecl();
    Hashtable<Decl*> *GetScopeTable() { return scope_table; }
    const char *GetPrintNameForNode() { return "StmtBlock"; }
    void PrintChildren(int indentLevel);    
};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);
    void CheckStmts();
		void CheckDecl();
};

class LoopStmt : public ConditionalStmt 
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
    void CheckStmts();// solo stmt
    const char *GetPrintNameForNode() { return "ForStmt"; }
    void PrintChildren(int indentLevel);    
};

class WhileStmt : public LoopStmt 
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
    void CheckStmts();//solo stmt
    const char *GetPrintNameForNode() { return "WhileStmt"; }
    void PrintChildren(int indentLevel);    
};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
    void CheckStmts();
		void CheckDecl();
    const char *GetPrintNameForNode() { return "IfStmt"; }
    void PrintChildren(int indentLevel);    
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
    void CheckStmts();//solo stmt
    const char *GetPrintNameForNode() { return "BreakStmt"; }    
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);
    void CheckStmts();//solo stmt
    const char *GetPrintNameForNode() { return "ReturnStmt"; }
    void PrintChildren(int indentLevel);    
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);
	void CheckStmts();//solo stmt
    const char *GetPrintNameForNode() { return "PrintStmt"; }
    void PrintChildren(int indentLevel);    

};

class DefaultStmt : public Stmt
{
  protected:
    List<Stmt*> *stmts;

  public:
    DefaultStmt(List<Stmt*> *sts);
	  void CheckStmts();
  	void CheckDecl();
    void PrintChildren(int indentLevel);
    const char *GetPrintNameForNode() { return "Default"; }

};


class CaseStmt : public DefaultStmt
{
  protected:
    IntConstant *intconst;

  public:
    CaseStmt(IntConstant *ic, List<Stmt*> *sts);
    const char *GetPrintNameForNode() { return "Case"; }
    void PrintChildren(int indentLevel);    
};

class SwitchStmt : public Stmt
{
  protected:
    Expr *expr;
    List<CaseStmt*> *cases;
    DefaultStmt *defaults;

  public:
    SwitchStmt(Expr *e, List<CaseStmt*> *cs, DefaultStmt *ds);
	  void CheckStmts();
  	void CheckDecl();
    void PrintChildren(int indentLevel) ;
    const char *GetPrintNameForNode() { return "SwitchStmt"; }
};

#endif
