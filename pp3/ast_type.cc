/* File: ast_type.cc
 * -----------------
 * Implementation of type node classes.
 */
#include "ast_type.h"
#include "ast_decl.h"
#include <string.h>
#include "ast_stmt.h"
#include "errors.h"



/* Class constants
 * ---------------
 * These are public constants for the built-in base types (int, double, etc.)
 * They can be accessed with the syntax Type::intType. This allows you to
 * directly access them and share the built-in types where needed rather that
 * creates lots of copies.
 */

Type *Type::intType    = new Type("int");
Type *Type::doubleType = new Type("double");
Type *Type::voidType   = new Type("void");
Type *Type::boolType   = new Type("bool");
Type *Type::nullType   = new Type("null");
Type *Type::stringType = new Type("string");
Type *Type::errorType  = new Type("error");

Type::Type(const char *n) {
	Assert(n);
	typeName = strdup(n);
}


NamedType::NamedType(Identifier *i) : Type(*i->GetLocation()) {
	Assert(i != NULL);
	(id=i)->SetParent(this);
}
bool NamedType::IsEquivalentTo(Type *nt) {
  if (typeid(*nt) == typeid(NamedType))
    return !strcmp(this->GetTypeName(), nt->GetTypeName());
  else
    return false;
}

void NamedType::CheckTypeError() {
  //printf("=====================NamedType::CheckTypeError ");
	PrintDebug("debug","Checking NamedType %s \n",this->id->GetName());
  const char *name = this->id->GetName();
  Decl *decl = Program::scope_table->Lookup(name);
  if ((decl == NULL) || (((typeid(*decl) != typeid(ClassDecl))) && ((typeid(*decl) != typeid(InterfaceDecl)))))
    {
		ReportError::IdentifierNotDeclared(id, LookingForType);
		this->id = NULL;
    }
}

ArrayType::ArrayType(yyltype loc, Type *et) : Type(loc) {
	Assert(et != NULL);
	(elemType=et)->SetParent(this);
}
const char* ArrayType::GetTypeName() {
  if (this->elemType)
    {
		const char* d = "[]";
		int newSize = strlen(this->elemType->GetTypeName()) + strlen(d);
		char* newBuffer = (char *)malloc(newSize);
		strcpy(newBuffer, this->elemType->GetTypeName());
		strcat(newBuffer,d);
		const char* str = newBuffer;
		PrintDebug("debug", "PRINTING %s",str);
		return str;
    }
  else{
		PrintDebug("debug", "PRINTING NULL");
    return NULL;
	}
}




bool ArrayType::IsEquivalentTo(Type *at) {
  return this->elemType->IsEquivalentTo(at->GetElemType());
}

void ArrayType::CheckTypeError() {
	PrintDebug("debug","Checking NamedType %s \n",this->elemType->GetTypeName());
  this->elemType->CheckTypeError();
}

