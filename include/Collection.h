#ifndef COLLECTION_H_
#define COLLECTION_H_

#include<string.h>
#include<stdlib.h>

void setCallocFunction(void * (*)(size_t count, size_t size));
void setMallocFunction(void * (*)(size_t count));
void setReallocFunction(void * (*)(void* ptr, size_t size));
void setFreeFunction(void (*)(void*ptr));

void* (* getCallocFunction())(size_t count, size_t size);void* (* getMallocFunction())(size_t size);void* (* getReallocFunction())(void* ptr, size_t size);void (* getFreeFunction())(void* ptr);

typedef enum {
	TRUE = 1, FALSE = 0
} boolean;

typedef struct Collection {
// ADD - REMOVE
	int (*add)(struct Collection* self, void* item);
	void* (*dequeue)(struct Collection*);
	boolean (*remove)(struct Collection*, void*);
	int (*addAll)(struct Collection* self, struct Collection otherCollection);
// TEST
	boolean (*allSatisfy)(struct Collection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
	boolean (*anySatisfy)(struct Collection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
// ITERATION
	struct Collection* (*collect)(struct Collection* self, void* (*Map)(void* item));
	void* (*detect)(struct Collection* self, boolean (*Comparator)(void* item, void*aParameter), void* aParameter);
	void* (*inject)(struct Collection* self, void* (*Into)(void*item, void*Rslt), void* Rslt);
	void* (*select)(struct Collection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
	void (*forEach)(struct Collection* self, void (*function)(void* item, void* aParameter), void* aParameter);
// COLLECTION 
	int (*count)(struct Collection* self);
	void* (*first)(struct Collection* self);
	void* (*last)(struct Collection* self);
	void* (*anyOne)(struct Collection* self);
	void (*finalize)(struct Collection* self);

} Collection;

typedef struct ArrayedCollection {
// ADD - REMOVE
	int (*add)(struct ArrayedCollection* self, void* item);
	void* (*dequeue)(struct ArrayedCollection*);
	boolean (*remove)(struct ArrayedCollection*, void*);
	int (*addAll)(struct ArrayedCollection* self, struct Collection* otherCollection);
// TEST
	boolean (*allSatisfy)(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
	boolean (*anySatisfy)(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
// ITERATION
	struct Collection* (*collect)(struct ArrayedCollection* self, void* (*Map)(void* item));
	void* (*detect)(struct ArrayedCollection* self, boolean (*Comparator)(void* item, void*aParameter), void* aParameter);
	void* (*inject)(struct ArrayedCollection* self, void* (*Into)(void*item, void*Rslt), void* Rslt);
	struct ArrayedCollection* (*select)(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
	void (*forEach)(struct ArrayedCollection* self, void (*function)(void* item, void* aParameter), void* aParameter);
// COLLECTION 
	int (*count)(struct ArrayedCollection* self);
	void* (*first)(struct ArrayedCollection* self);
	void* (*last)(struct ArrayedCollection* self);
	void* (*anyOne)(struct ArrayedCollection* self);
	void (*finalize)(struct ArrayedCollection* self);
	void (*__Write)(struct ArrayedCollection*, int, void*);
	void* (*__Read)(struct ArrayedCollection*, int);
	void** data;
	int size;
	int used;
	int typeSize;
} ArrayedCollection;

int Arrayed_Collection_Add(struct ArrayedCollection* self, void* item);
void* Arrayed_Collection_Dequeue(struct ArrayedCollection* self);
boolean Arrayed_Collection_Remove(struct ArrayedCollection*, void*);
int Arrayed_Collection_AddAll(struct ArrayedCollection* self, struct Collection* otherCollection);

boolean Arrayed_Collection_AllSatisfy(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
boolean Arrayed_Collection_AnySatisfy(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);

Collection* Arrayed_Collection_Collect(struct ArrayedCollection* self, void* (*Map)(void* item));
void* Arrayed_Collection_Detect(struct ArrayedCollection* self, boolean (*Comparator)(void* item, void*aParameter), void* aParameter);
void* Arrayed_Collection_Inject(struct ArrayedCollection* self, void* (*Into)(void*item, void*Rslt), void* Rslt);
struct ArrayedCollection* Arrayed_Collection_Select(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter);
void Arrayed_Collection_ForEach(struct ArrayedCollection* self, void (*function)(void* item, void* aParameter), void* aParameter);

int Arrayed_Collection_Count(struct ArrayedCollection* self);
void* Arrayed_Collection_First(struct ArrayedCollection* self);
void* Arrayed_Collection_Last(struct ArrayedCollection* self);
void* Arrayed_Collection_AnyOne(struct ArrayedCollection* self);
void Arrayed_Collection_Finalize(struct ArrayedCollection* self);
void Arrayed_Collection_Finalize_Object(struct ArrayedCollection* self);

#define TYPED_ARRAYED_COLLECTION(Name,X) typedef struct Name {\
	int (*add) (struct Name * self, X item); \
	X  (*dequeue)(struct Name*);\
	boolean(*remove) (struct Name *,X );\
	int (*addAll) (struct Name * self, struct Collection* otherCollection);\
	boolean(*allSatisfy) (struct Name * self, boolean(*Condition) ( X item, void* aParameter), void* aParameter);\
	boolean(*anySatisfy) (struct Name * self, boolean(*Condition) ( X item, void* aParameter), void* aParameter);\
	Collection* (*collect) (struct Name * self, void* (*Map) (X item));\
	X (*detect) (struct Name * self, boolean(*Comparator) ( X item, void*aParameter), void* aParameter);\
	void* (*inject) (struct Name * self, void* (*Into) ( X item, void*Rslt), void* Rslt);\
	struct Name * (*select) (struct Name * self, boolean(*Condition) (X item, void* aParameter), void* aParameter);\
	void (*forEach) (struct Name * self, void (*function) ( X item, void* aParameter), void* aParameter);\
	int (*count)(struct Name * self);\
	X (*first) (struct Name * self);\
	X (*last) (struct Name * self);\
	X (*anyOne) (struct Name * self);\
	void (*finalize) (struct Name *);\
	void (*__Write)(struct ArrayedCollection*, int, X);\
	X (*__Read)(struct ArrayedCollection*, int);\
	X * data;\
	int size;\
	int used;\
	int typeSize;\
} Name;

#define TYPED_ARRAYED_COLLECTION_SIGNATURES(Name) \
void Initialize_## Name ##_Object ( Name * Instance); \
Name * Name ##_New (void);

#define TYPED_ARRAYED_COLLECTION_ACCESS_SIGNATURES(Name, X) \
void __Write_ ## Name (struct ArrayedCollection*, int,  X); \
X __Read_ ## Name (struct ArrayedCollection*, int); \


#define TYPED_ARRAYED_COLLECTION_INITIALIZE(Name,X) void Initialize_## Name ##_Object (struct Name * Instance){\
    Instance->add = (int (*) (struct Name * self, X item)) Arrayed_Collection_Add;\
	Instance->remove = (boolean(*) (struct Name *,X )) Arrayed_Collection_Remove;\
	Instance->dequeue = (X(*) (struct Name * )) Arrayed_Collection_Dequeue;\
	Instance->addAll = (int (*) (struct Name * self, struct Collection* otherCollection)) Arrayed_Collection_AddAll;\
	Instance->allSatisfy = (boolean(*) (struct Name * self, boolean(*Condition) ( X item, void* aParameter), void* aParameter)) Arrayed_Collection_AllSatisfy;\
	Instance->anySatisfy = (boolean(*) (struct Name * self, boolean(*Condition) (X item, void* aParameter), void* aParameter)) Arrayed_Collection_AnySatisfy;\
	Instance->collect = (Collection* (*) (struct Name * self, void* (*Map) (X item))) Arrayed_Collection_Collect;\
	Instance->detect = (X (*) (struct Name * self, boolean(*Comparator) ( X item, void*aParameter), void* aParameter)) Arrayed_Collection_Detect;\
	Instance->inject = (void* (*) (struct Name * self, void* (*Into) (X item, void*Rslt), void* Rslt)) Arrayed_Collection_Inject;\
	Instance->select = (struct Name * (*) (struct Name * self, boolean(*Condition) (X item, void* aParameter), void* aParameter)) Arrayed_Collection_Select;\
	Instance->forEach = (void (*) (struct Name * self, void (*function) ( X item, void* aParameter), void* aParameter)) Arrayed_Collection_ForEach;\
	Instance->count = (int (*)(struct Name * self)) Arrayed_Collection_Count;\
	Instance->first = (X (*) (struct Name * self)) Arrayed_Collection_First;\
	Instance->last = (X  (*) (struct Name * self)) Arrayed_Collection_Last;\
	Instance->anyOne = (X (*) (struct Name * self)) Arrayed_Collection_AnyOne;\
	Instance->finalize = (void (*) (struct Name * self)) Arrayed_Collection_Finalize;\
	Instance->__Write =__Write_ ## Name; \
	Instance->__Read =__Read_ ## Name;\
	Instance->data = getCallocFunction()(5, sizeof(X));\
	Instance->size = 5;\
    Instance->used = 0;\
	Instance->typeSize = sizeof(X); }

#define TYPED_ARRAYED_COLLECTION_NEW(Name) struct Name * Name ##_New (){\
  struct Name * ret = (struct Name *) getMallocFunction() (sizeof(struct Name));\
  Initialize_## Name ##_Object(ret);\
  ret->finalize = (void (*) (struct Name *))Arrayed_Collection_Finalize_Object;\
  return ret;}

#define TYPED_ARRAYED_COLLECTION_WRITE(Name,X) void __Write_ ## Name (struct ArrayedCollection* this, int pos ,X data){\
	Name* self = (Name*) this;\
	self->data[pos] = data;\
  }

#define TYPED_ARRAYED_COLLECTION_READ(Name,X) X __Read_ ## Name (struct ArrayedCollection* this, int pos){\
	Name* self = (Name*) this;\
	return self->data[pos];\
  }

#define TYPED_ARRAYED_COLLECTION_DEFINITION_H(Name,X)\
  TYPED_ARRAYED_COLLECTION_ACCESS_SIGNATURES(Name, X)\
  TYPED_ARRAYED_COLLECTION(Name,X);\
  TYPED_ARRAYED_COLLECTION_SIGNATURES(Name);

#define TYPED_ARRAYED_COLLECTION_DEFINITION_C(Name,X)\
  TYPED_ARRAYED_COLLECTION_INITIALIZE(Name ,X);\
  TYPED_ARRAYED_COLLECTION_NEW(Name);\
  TYPED_ARRAYED_COLLECTION_WRITE(Name,X);\
  TYPED_ARRAYED_COLLECTION_READ(Name,X);

TYPED_ARRAYED_COLLECTION_ACCESS_SIGNATURES(ArrayedCollection, void*)
TYPED_ARRAYED_COLLECTION_SIGNATURES(ArrayedCollection);

#endif
