/* File: ast_type.h
 * ----------------
 * In our parse tree, Type nodes are used to represent and
 * store type information. The base Type class is used
 * for built-in types, the NamedType for classes and interfaces,
 * and the ArrayType for arrays of other types.  
 *
 * pp3: You will need to extend the Type classes to implement
 * the type system and rules for type equivalency and compatibility.
 */
 
#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"
#include <iostream>


class Type : public Node 
{
  protected:
    char *typeName;

  public :
    static Type *intType, *doubleType, *boolType, *voidType,
                *nullType, *stringType, *errorType;

    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);
    const char *GetPrintNameForNode() { return "Type"; }
	  char *GetName() { return this->typeName; }
    void PrintChildren(int indentLevel);
    virtual void PrintToStream(std::ostream& out) { out << typeName; }
    virtual Type *GetElemType() { return this; }
    virtual const char *GetTypeName() { return typeName; }
    virtual void CheckTypeError() {}
    friend std::ostream& operator<<(std::ostream& out, Type *t) { t->PrintToStream(out); return out; }
    virtual bool IsEquivalentTo(Type *other) { return this == other; }
};

class NamedType : public Type 
{
  protected:
    Identifier *id;
    
  public:
    NamedType(Identifier *i);
    Identifier *GetID() { return id; }
    Type *GetElemType() { return this; }
    const char *GetTypeName() { if (id) return id->GetName(); else return NULL; };
    void CheckTypeError();
    bool IsEquivalentTo(Type *nt);
    void PrintToStream(std::ostream& out) { out << id; }
    const char *GetPrintNameForNode() { return "NamedType"; }
    void PrintChildren(int indentLevel);
};

class ArrayType : public Type 
{
  protected:
    Type *elemType;

  public:
    ArrayType(yyltype loc, Type *elemType);
    Type *GetElemType() { return elemType; }
    const char *GetTypeName();
    void CheckTypeError();
    bool IsEquivalentTo(Type *at);
    void PrintToStream(std::ostream& out) { out << elemType << "[]"; }
    const char *GetPrintNameForNode() { return "ArrayType"; }
    void PrintChildren(int indentLevel);
};

 
#endif
