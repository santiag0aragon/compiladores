/* File: ast_expr.h
 * ----------------
 * The Expr class and its subclasses are used to represent
 * expressions in the parse tree.  For each expression in the
 * language (add, call, New, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Expr classes to implement 
 * semantic analysis for rules pertaining to expressions.
 */


#ifndef _H_ast_expr
#define _H_ast_expr

#include "ast.h"
#include "ast_stmt.h"

#include "ast_type.h"
#include "list.h"
class FnDecl;
//class NamedType; // for new
//class Type; // for NewArray


class Expr : public Stmt 
{
  protected:
    Type* type;
  public:
    Expr(yyltype loc) : Stmt(loc) {}
    Expr() : Stmt() {}
    virtual Type *GetType() { return type; }
    virtual const char *GetTypeName() { if (type) return type->GetTypeName(); else return NULL;}

};

/* This node type is used for those places where an expression is optional.
 * We could use a NULL pointer, but then it adds a lot of checking for
 * NULL. By using a valid, but no-op, node, we save that trouble */
class EmptyExpr : public Expr
{
  public:
        const char *GetPrintNameForNode() { return "Empty"; }
};

class IntConstant : public Expr 
{
  protected:
    int value;
  
  public:
    IntConstant(yyltype loc, int val);
    const char *GetPrintNameForNode() { return "IntConstant"; }
    void PrintChildren(int indentLevel);
};

class DoubleConstant : public Expr 
{
  protected:
    double value;
    
  public:
    DoubleConstant(yyltype loc, double val);
    const char *GetPrintNameForNode() { return "DoubleConstant"; }
    void PrintChildren(int indentLevel);    
};

class BoolConstant : public Expr 
{
  protected:
    bool value;
    
  public:
    BoolConstant(yyltype loc, bool val);
    const char *GetPrintNameForNode() { return "BoolConstant"; }
    void PrintChildren(int indentLevel);    
};

class StringConstant : public Expr 
{ 
  protected:
    char *value;
    
  public:
    StringConstant(yyltype loc, const char *val);
    const char *GetPrintNameForNode() { return "StringConstant"; }
    void PrintChildren(int indentLevel);
};

class NullConstant: public Expr 
{
  public: 
    NullConstant(yyltype loc) ;
    const char *GetPrintNameForNode() { return "NullConstant"; }
};

class Operator : public Node 
{
  protected:
    char tokenString[4];
    
  public:
    Operator(yyltype loc, const char *tok);
    friend std::ostream& operator<<(std::ostream& out, Operator *o) { return out << o->tokenString; }
    const char *GetPrintNameForNode() { return "Operator"; }
    void PrintChildren(int indentLevel);
 };
 
class CompoundExpr : public Expr
{
  protected:
    Operator *op;
    Expr *left, *right; // left will be NULL if unary
    
  public:
    CompoundExpr(Expr *lhs, Operator *op, Expr *rhs); // for binary
    CompoundExpr(Operator *op, Expr *rhs);             // for unary
    void PrintChildren(int indentLevel);
};

class ArithmeticExpr : public CompoundExpr 
{
  public:
    ArithmeticExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    ArithmeticExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    void CheckStmts();
    Type *GetType() { return right->GetType(); }
    const char *GetTypeName() { return right->GetTypeName();}

    const char *GetPrintNameForNode() { return "ArithmeticExpr"; }
};

class RelationalExpr : public CompoundExpr 
{
  public:
    RelationalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    void CheckStmts();
    Type *GetType() { return Type::boolType; }
    const char *GetTypeName() { return "bool"; }
    const char *GetPrintNameForNode() { return "RelationalExpr"; }

};

class EqualityExpr : public CompoundExpr 
{
  public:
    EqualityExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "EqualityExpr"; }
    void CheckStmts();
    Type *GetType() { return Type::boolType; }
    const char *GetTypeName() { return "bool"; }
    
};

class LogicalExpr : public CompoundExpr 
{
  public:
    LogicalExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    LogicalExpr(Operator *op, Expr *rhs) : CompoundExpr(op,rhs) {}
    void CheckStmts();
    Type *GetType() { return Type::boolType; }
    const char *GetTypeName() { return "bool"; }
    const char *GetPrintNameForNode() { return "LogicalExpr"; }

};

class AssignExpr : public CompoundExpr 
{
  public:
    AssignExpr(Expr *lhs, Operator *op, Expr *rhs) : CompoundExpr(lhs,op,rhs) {}
    const char *GetPrintNameForNode() { return "AssignExpr"; }
    void CheckStmts();
    Type *GetType() { return left->GetType(); }
    const char *GetTypeName() { return left->GetTypeName(); }
};

class LValue : public Expr 
{
  public:
    LValue(yyltype loc) : Expr(loc) {}

};

class This : public Expr 
{
  public:
    This(yyltype loc) : Expr(loc) {}
    const char *GetPrintNameForNode() { return "This"; }
    void CheckStmts();

};

class ArrayAccess : public LValue 
{
  protected:
    Expr *base, *subscript;
    
  public:
    ArrayAccess(yyltype loc, Expr *base, Expr *subscript);
    void CheckStmts();
    Type *GetType();
    const char *GetTypeName();
    const char *GetPrintNameForNode() { return "ArrayAccess"; }
    void PrintChildren(int indentLevel);
};

/* Note that field access is used both for qualified names
 * base.field and just field without qualification. We don't
 * know for sure whether there is an implicit "this." in
 * front until later on, so we use one node type for either
 * and sort it out later. */
class FieldAccess : public LValue 
{
  protected:
    Expr *base;	// will be NULL if no explicit base
    Identifier *field;
    Type* type; // Expr::type is protected and thus not inherited here
    
  public:
    FieldAccess(Expr *base, Identifier *field); //ok to pass NULL base
    void CheckStmts(); // its type is decided here
    Identifier *GetField() { return field; }
		Type *GetType(){return this->type;}
    //const char *GetTypeName() { if (type) return type->GetTypeName(); else return NULL; }
	const char *GetTypeName();
	const char *GetPrintNameForNode() { return "FieldAccess"; }
    void PrintChildren(int indentLevel);
};

/* Like field access, call is used both for qualified base.field()
 * and unqualified field().  We won't figure out until later
 * whether we need implicit "this." so we use one node type for either
 * and sort it out later. */
class Call : public Expr 
{
  protected:
    Expr *base;	// will be NULL if no explicit base
    Identifier *field;
    List<Expr*> *actuals;
    
  public:
    Call(yyltype loc, Expr *base, Identifier *field, List<Expr*> *args);
    void CheckArguments(FnDecl *fndecl); // check arguments against formal parameters
    void CheckStmts(); // its type is decided here
    Type* GetType() { return type; }
    const char* GetTypeName() { if (type) return type->GetTypeName(); else return NULL; }
    const char *GetPrintNameForNode() { return "Call"; }
    void PrintChildren(int indentLevel);
};

class NewExpr : public Expr
{
  protected:
    NamedType* cType;
    
  public:
    NewExpr(yyltype loc, NamedType *clsType);
    void CheckStmts();
    Type* GetType() { return cType; }
    const char* GetTypeName() { if (cType) return cType->GetTypeName(); else return NULL;  }
    const char *GetPrintNameForNode() { return "NewExpr"; }
    void PrintChildren(int indentLevel);
};

class NewArrayExpr : public Expr
{
  protected:
    Expr *size;
    Type *elemType;
    
  public:
    NewArrayExpr(yyltype loc, Expr *sizeExpr, Type *elemType);
    void CheckStmts();
		//const char *GetTypeName(){if (elemType) return elemType->GetTypeName(); else return NULL; };
		const char *GetTypeName();
		Type *GetType() { return elemType ;}
    const char *GetPrintNameForNode() { return "NewArrayExpr"; }
    void PrintChildren(int indentLevel);

};

class ReadIntegerExpr : public Expr
{
  public:
    ReadIntegerExpr(yyltype loc);
    const char *GetPrintNameForNode() { return "ReadIntegerExpr"; }
};

class ReadLineExpr : public Expr
{
  public:
    ReadLineExpr(yyltype loc);
    const char *GetPrintNameForNode() { return "ReadLineExpr"; }
};

class PostfixExpr : public Expr
{
  protected:
    LValue *lvalue;
    Operator *optr;

  public:
    PostfixExpr(yyltype loc, LValue *lv, Operator *op);
    void CheckStmts();
    Type* GetType() { if (lvalue) return lvalue->GetType(); else return NULL; }
    const char *GetTypeName() { if (lvalue) return lvalue->GetTypeName(); else return NULL; }
    const char *GetPrintNameForNode() { return "PostfixExpr"; }
    void PrintChildren(int indentLevel);
};
      
#endif
