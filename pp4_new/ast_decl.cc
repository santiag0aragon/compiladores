/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */

#include <typeinfo>
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "errors.h"


Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
	Assert(n != NULL);
	(id=n)->SetParent(this);
}


VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
	Assert(n != NULL && t != NULL);
	(type=t)->SetParent(this);
}

bool VarDecl::HasSameTypeSig(VarDecl *vd) {
  if (this->type)
    return this->type->IsEquivalentTo(vd->GetType());
  else
    return false;
}
void VarDecl::PrintChildren(int indentLevel) {
	if (type) type->Print(indentLevel+1);
	if (id) id->Print(indentLevel+1);
}

void VarDecl::CheckStmts() {
		// do nothing here
}
	// check NamedType errors
void VarDecl::CheckDecl() {
		PrintDebug("debug","Checking VarDecl %s \n",this->GetPrintNameForNode());
  if (this->type){
    this->type->CheckTypeError();
	}
	
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
		//PrintDebug("debug", "New ClassDecl %s",n->GetName());
	Assert(n != NULL && imp != NULL && m != NULL);
	extends = ex;
	if (extends) extends->SetParent(this);
	(implements=imp)->SetParentAll(this);
	(members=m)->SetParentAll(this);
	this->scope_table = new Hashtable<Decl*>;
}

void ClassDecl::CheckStmts() {
  if (this->members)
    {
		for (int i = 0; i < this->members->NumElements(); i++){
				//printf("=====================ClassDecl::for member %s \n",i);
			this->members->Nth(i)->CheckStmts();
		}
    }
}
void ClassDecl::CheckDecl() {
	PrintDebug("debug","=====================ClassDecl::CHECK \n");

	
		// add itself to the symbol table
  this->scope_table->Enter(this->GetID()->GetName(), this);
	// check decl conflicts of its members and add the decl to symbol table if no errors
  if (this->members)
    {
		for (int i = 0; i < this->members->NumElements(); i++)
			{
			Decl *cur = this->members->Nth(i);
			Decl *prev;
			const char *name = cur->GetID()->GetName();
			if (name)
				{
	      if ((prev = this->scope_table->Lookup(name)) != NULL){
					ReportError::DeclConflict(cur, prev);
				//printf("=====================ClassDecl::node==null stms\n");					
				}
				
	      else{
					PrintDebug("debug","Entering in scope %s",name);
					this->scope_table->Enter(name, cur);
				}
				}
			}
    }
	
	
  NamedType *ex = this->extends;
  while (ex)
    {
		const char *name = ex->GetID()->GetName();
		if (name)
			{
			Node *node = Program::scope_table->Lookup(name);
			if (node == NULL)
				{
				//printf("=====================ClassDecl::node==null stms\n");
	      ReportError::IdentifierNotDeclared(ex->GetID(), LookingForClass);
	      
	      break;
				}
			else if (typeid(*node) == typeid(ClassDecl))
				{
	      ClassDecl *base = dynamic_cast<ClassDecl*>(node);
	      List<Decl*> *base_members = base->members;
	      List<Decl*> *inherited = new List<Decl*>;
				
	      if (base_members)
					{
					for (int i = 0; i < base_members->NumElements(); i++)
						{
						Decl *cur = base_members->Nth(i);
						Decl *prev;
						const char *name = cur->GetID()->GetName();
						if ((prev = this->scope_table->Lookup(name)) != NULL)
							{
							if (typeid(*cur) == typeid(VarDecl) || typeid(*cur) != typeid(*prev)) // data members
								ReportError::DeclConflict(prev, cur);
							else if (typeid(*cur) == typeid(FnDecl) && typeid(*cur) == typeid(*prev)) // member functions
								{
								FnDecl *fdcur = dynamic_cast<FnDecl*>(cur);
								FnDecl *fdprev = dynamic_cast<FnDecl*>(prev);
								if (!fdcur->HasSameTypeSig(fdprev))
									ReportError::OverrideMismatch(fdprev);
								}
							}
						else
							{
							inherited->Append(cur);
							}
						}
					for (int i = 0; i < inherited->NumElements(); i++)
						{
						Decl *decl = inherited->Nth(i);
						this->scope_table->Enter(decl->GetID()->GetName(), decl);
						}
					}
	      ex = base->GetExtends();
				}
			}
    }
	
  if (this->implements)
    {
		//printf("=====================ClassDecl::this-> interface \n");
		for (int i = 0; i < this->implements->NumElements(); i++)
			{
			NamedType *implement = this->implements->Nth(i);
			Identifier *id = implement->GetID();
			if (id)
				{
	      Node *node = Program::scope_table->Lookup(id->GetName());
	      if (node == NULL || (typeid(*node) != typeid(InterfaceDecl)))
					{
					ReportError::IdentifierNotDeclared(id, LookingForInterface);

					}
	      else if (typeid(*node) == typeid(InterfaceDecl))
					{
					InterfaceDecl *ifd = dynamic_cast<InterfaceDecl*>(node);
					List<Decl*> *members = ifd->GetMembers();
					for (int j = 0; j < members->NumElements(); j++)
						{
						FnDecl *cur = dynamic_cast<FnDecl*>(members->Nth(j));
						Decl *prev;
						const char *name = cur->GetID()->GetName();
						;
						if ((prev = this->scope_table->Lookup(name)) != NULL)
							{
							if (typeid(*prev) != typeid(FnDecl))
								ReportError::DeclConflict(cur, prev);
							else if (!cur->HasSameTypeSig(dynamic_cast<FnDecl*>(prev)))
								ReportError::OverrideMismatch(prev);
							}
						else
							ReportError::InterfaceNotImplemented(this, implement);
						}
					}
				}
			}
    }

	
	  // look into local scopes
		// again we do not go into the scope of extended classes or implemented interfaces
  if (this->members)
    {
		for (int i = 0; i < this->members->NumElements(); i++)
			this->members->Nth(i)->CheckDecl();
    }
}

void ClassDecl::PrintChildren(int indentLevel) {
	id->Print(indentLevel+1);
	if (extends) extends->Print(indentLevel+1, "(extends) ");
	implements->PrintAll(indentLevel+1, "(implements) ");
	members->PrintAll(indentLevel+1);
}

bool ClassDecl::IsCompatibleWith(Decl *decl)
{
  NamedType *extends = this->GetExtends();
  List<NamedType*> *implements = this->GetImplements();
	
  if (typeid(*decl) == typeid(ClassDecl))
    {
		ClassDecl *cldecl = dynamic_cast<ClassDecl*>(decl);
      // is B a base class of A
		if (extends)
			{
			const char *name = extends->GetTypeName();
			if (!strcmp(cldecl->GetID()->GetName(), name))
				return true;
			else
				{
				if (name)
					{
					Decl *exdecl = Program::scope_table->Lookup(name);
					if (exdecl && typeid(*exdecl) == typeid(ClassDecl))
						return dynamic_cast<ClassDecl*>(exdecl)->IsCompatibleWith(decl);
					}
				}
			}
    }
	
  else if (typeid(*decl) == typeid(InterfaceDecl))
    {
		InterfaceDecl *itfdecl = dynamic_cast<InterfaceDecl*>(decl);
		
		if (implements)
			{
			for (int i = 0; i < implements->NumElements(); i++)
				{
	      NamedType *implement = implements->Nth(i);
	      if (implement && !strcmp(itfdecl->GetID()->GetName(), implement->GetTypeName()))
					return true;
				
				}
			}
		if (extends)
			{
			const char *name = extends->GetTypeName();
			if (name)
				{
				Decl *exdecl = Program::scope_table->Lookup(name);
				if (exdecl && typeid(*exdecl) == typeid(ClassDecl))
					return dynamic_cast<ClassDecl*>(exdecl)->IsCompatibleWith(decl);
				}
			}
    }
	
  return false;
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
	Assert(n != NULL && m != NULL);
	(members=m)->SetParentAll(this);
  this->scope_table  = new Hashtable<Decl*>;
}

void InterfaceDecl::CheckDecl() {
	//printf("=====================InterfaceDecl::CHECK\n");
  if (this->members)
    {
		for (int i = 0; i < this->members->NumElements(); i++)
			{
			Decl *cur = members->Nth(i);
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
					}
				}
			}
    }
}


FnDecl::FnDecl(Identifier* n, Type *r, List<VarDecl*> *d) : Decl(n) {
	Assert(n != NULL && r!= NULL && d != NULL);
	(returnType=r)->SetParent(this);
	(formals=d)->SetParentAll(this);
	body = NULL;
	this->scope_table  = new Hashtable<Decl*>;
}


bool FnDecl::HasSameTypeSig(FnDecl *fd) {
  if (!strcmp(this->id->GetName(), fd->GetID()->GetName()))
    if (this->returnType->IsEquivalentTo(fd->GetType()))
      {
			List<VarDecl*> *f1 = formals;
			List<VarDecl*> *f2 = fd->GetFormals();
			
			if (f1 && f2)
				if (f1->NumElements() == f2->NumElements())
					{
					for (int i = 0; i < f1->NumElements(); i++)
						{
						VarDecl *vd1 = f1->Nth(i);
						VarDecl *vd2 = f2->Nth(i);
						if (!vd1->HasSameTypeSig(vd2))
							return false;
						}
					return true;
					}
      }
	return false;
}


void FnDecl::CheckStmts() {
	if (this->body){
	PrintDebug("debug","=====================FnDecl::this-> body \n");
		this->body->CheckStmts();
	}
}
	
void FnDecl::CheckDecl() {
	PrintDebug("debug","=====================FnDecl::Check \n");
	
  if (this->formals)
    {
		PrintDebug("debug","=====================FnDecl::Formals \n");
		for (int i = 0; i < this->formals->NumElements(); i++)
			{
			VarDecl *cur = this->formals->Nth(i);
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
					PrintDebug("debug""=====================FnDecl::Inserting in scope %s \n",name);
					scope_table->Enter(name, cur);
						//scope_table->printTable();
					cur->CheckDecl();
					}
				}
			}
    }
	
  if (this->body){
		PrintDebug("debug","=====================FnDecl::this-> body \n");
		this->body->CheckDecl();
	}
	
	



}

void FnDecl::PrintChildren(int indentLevel) {
	if (returnType) returnType->Print(indentLevel+1, "(return type) ");
	if (id) id->Print(indentLevel+1);
	if (formals) formals->PrintAll(indentLevel+1, "(formals) ");
	if (body) body->Print(indentLevel+1, "(body) ");
}

void FnDecl::SetFunctionBody(StmtBlock *b) {
	(body=b)->SetParent(this);
}




