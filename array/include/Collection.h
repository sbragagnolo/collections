
#ifndef COLLECTION_H_
#define COLLECTION_H_

#include<stdlib.h>
#include<string.h>


typedef enum {
	TRUE = 1,
	FALSE = 0
}bool;

typedef struct Collection {
// ADD - REMOVE
	int (*add) (struct Collection* self, void* item);
	bool (*remove) (struct Collection*,void*);
	int (*addAll) (struct Collection* self, struct Collection otherCollection);
// TEST
	bool (*allSatisfy) (struct Collection* self, bool (*Condition) (struct Collection* self, void* item, void* aParameter), void* aParameter);
	bool (*anySatisfy) (struct Collection* self, bool (*Condition) (void*self, void* item, void* aParameter), void* aParameter);
// ITERATION
	struct Collection* (*collect) (struct Collection* self, void* (*Map) (void* item));
	void* (*detect) (struct Collection* self, bool (*Comparator) (struct Collection* self, void* item, void*aParameter), void* aParameter);
	void* (*inject) (struct Collection* self, void* (*Into) (struct ArrayedCollection* self, void*item, void*Rslt), void* Rslt);
	void* (*select) (struct Collection* self, bool (*Condition) (void* item, void* aParameter), void* aParameter);
	void (*forEach) (struct Collection* self, void (*function) (struct Collection* self, void* item, void* aParameter), void* aParameter);
// COLLECTION 
	int (*count)(struct Collection* self);
	void* (*first) (struct Collection* self);
	void* (*last) (struct Collection* self);
	void* (*anyOne) (struct Collection* self);
	void (*finalize) (struct Collection* self);
	
}Collection;

 typedef struct ArrayedCollection {
// ADD - REMOVE
	int (*add) (struct ArrayedCollection* self, void* item);
	bool (*remove) (struct ArrayedCollection*,void*);
	int (*addAll) (struct ArrayedCollection* self, struct Collection* otherCollection );
// TEST
	bool (*allSatisfy) (struct ArrayedCollection* self, bool (*Condition) (struct ArrayedCollection* self, void* item, void* aParameter), void* aParameter);
	bool (*anySatisfy) (struct ArrayedCollection* self, bool (*Condition) (void*self, void* item, void* aParameter), void* aParameter);
// ITERATION
	struct Collection* (*collect) (struct ArrayedCollection* self, void* (*Map) (void* item));
	void* (*detect) (struct ArrayedCollection* self, bool (*Comparator) (struct ArrayedCollection* self, void* item, void*aParameter), void* aParameter);
	void* (*inject) (struct ArrayedCollection* self, void* (*Into) (struct ArrayedCollection* self, void*item, void*Rslt), void* Rslt);
	struct ArrayedCollection* (*select) (struct ArrayedCollection* self, bool (*Condition) (void* item, void* aParameter), void* aParameter);
	void (*forEach) (struct ArrayedCollection* self, void (*function) (struct ArrayedCollection* self, void* item, void* aParameter), void* aParameter);
// COLLECTION 
	int (*count)(struct ArrayedCollection* self);
	void* (*first) (struct ArrayedCollection* self);
	void* (*last) (struct ArrayedCollection* self);
	void* (*anyOne) (struct ArrayedCollection* self);
	void (*finalize) (struct ArrayedCollection* self);
	void** data;
	int size;
	int used; 
}ArrayedCollection;

int Arrayed_Collection_Add (struct ArrayedCollection* self, void* item);
bool Arrayed_Collection_Remove  (struct ArrayedCollection*,void*);
int Arrayed_Collection_AddAll (struct ArrayedCollection* self, struct Collection* otherCollection );

bool Arrayed_Collection_AllSatisfy (struct ArrayedCollection* self, bool (*Condition) (struct ArrayedCollection* self, void* item, void* aParameter), void* aParameter);
bool Arrayed_Collection_AnySatisfy (struct ArrayedCollection* self, bool (*Condition) (void*self, void* item, void* aParameter), void* aParameter);

Collection* Arrayed_Collection_Collect (struct ArrayedCollection* self, void* (*Map) (void* item));
void* Arrayed_Collection_Detect (struct ArrayedCollection* self, bool (*Comparator) (struct ArrayedCollection* self, void* item, void*aParameter), void* aParameter);
void* Arrayed_Collection_Inject (struct ArrayedCollection* self, void* (*Into) (struct ArrayedCollection* self, void*item, void*Rslt), void* Rslt);
struct ArrayedCollection* Arrayed_Collection_Select (struct ArrayedCollection* self, bool (*Condition) (void* item, void* aParameter), void* aParameter);
void Arrayed_Collection_ForEach (struct ArrayedCollection* self, void (*function) (struct ArrayedCollection* self, void* item, void* aParameter), void* aParameter);

int Arrayed_Collection_Count (struct ArrayedCollection* self);
void* Arrayed_Collection_First (struct ArrayedCollection* self);
void* Arrayed_Collection_Last (struct ArrayedCollection* self);
void* Arrayed_Collection_AnyOne (struct ArrayedCollection* self);
void Arrayed_Collection_Finalize (struct ArrayedCollection* self);



#define TYPED_ARRAYED_COLLECTION(Name,X) typedef struct Name {\
	int (*add) (struct Name * self, X * item); \
	bool (*remove) (struct Name *,X *);\
	int (*addAll) (struct Name * self, struct Collection* otherCollection);\
	bool (*allSatisfy) (struct Name * self, bool (*Condition) (struct Name * self, X * item, void* aParameter), void* aParameter);\
	bool (*anySatisfy) (struct Name * self, bool (*Condition) (void*self, X * item, void* aParameter), void* aParameter);\
	Collection* (*collect) (struct Name * self, void* (*Map) (X * item));\
	X* (*detect) (struct Name * self, bool (*Comparator) (struct Name * self, X * item, void*aParameter), void* aParameter);\
	void* (*inject) (struct Name * self, void* (*Into) (struct Name * self, X * item, void*Rslt), void* Rslt);\
	struct Name * (*select) (struct Name * self, bool (*Condition) (X * item, void* aParameter), void* aParameter);\
	void (*forEach) (struct Name * self, void (*function) (struct Name * self, X * item, void* aParameter), void* aParameter);\
	int (*count)(struct Name * self);\
	X * (*first) (struct Name * self);\
	X * (*last) (struct Name * self);\
	X * (*anyOne) (struct Name * self);\
	void (*finalize) (struct Name *);\
	X * data;\
	int size;\
	int used;\
} Name;

#define TYPED_ARRAYED_COLLECTION_INITIALIZE(Name,X) void Initialize_## Name ##_Object (struct Name * Instance){\
        Instance->add = (int (*) (struct Name * self, X * item)) Arrayed_Collection_Add;\
	Instance->remove = (bool (*) (struct Name *,X *)) Arrayed_Collection_Remove;\
	Instance->addAll = (int (*) (struct Name * self, struct Collection* otherCollection)) Arrayed_Collection_AddAll;\
	Instance->allSatisfy = (bool (*) (struct Name * self, bool (*Condition) (struct Name * self, X * item, void* aParameter), void* aParameter)) Arrayed_Collection_AllSatisfy;\
	Instance->anySatisfy = (bool (*) (struct Name * self, bool (*Condition) (void*self, X * item, void* aParameter), void* aParameter)) Arrayed_Collection_AnySatisfy;\
	Instance->collect = (Collection* (*) (struct Name * self, void* (*Map) (X * item))) Arrayed_Collection_Collect;\
	Instance->detect = (X * (*) (struct Name * self, bool (*Comparator) (struct Name * self, X * item, void*aParameter), void* aParameter)) Arrayed_Collection_Detect;\
	Instance->inject = (void* (*) (struct Name * self, void* (*Into) (struct Name * self, X * item, void*Rslt), void* Rslt)) Arrayed_Collection_Inject;\
	Instance->select = (struct Name * (*) (struct Name * self, bool (*Condition) (X * item, void* aParameter), void* aParameter)) Arrayed_Collection_Select;\
	Instance->forEach = (void (*) (struct Name * self, void (*function) (struct Name * self, X* item, void* aParameter), void* aParameter)) Arrayed_Collection_ForEach;\
	Instance->count = (int (*)(struct Name * self)) Arrayed_Collection_Count;\
	Instance->first = (X * (*) (struct Name * self)) Arrayed_Collection_First;\
	Instance->last = (X * (*) (struct Name * self)) Arrayed_Collection_Last;\
	Instance->anyOne = (X * (*) (struct Name * self)) Arrayed_Collection_AnyOne;\
	Instance->finalize = (void (*) (struct Name *)) Arrayed_Collection_Finalize;\
	Instance->data = calloc(5, sizeof(X *));\
	Instance->size = 5;\
          Instance->used = 0; }


#define TYPED_ARRAYED_COLLECTION_SIGNATURES(Name) \
void Initialize_## Name ##_Object ( Name * Instance); \
 Name * ## Name ##_New (void);
  
#define TYPED_ARRAYED_COLLECTION_NEW(Name) struct Name * ## Name ##_New (){\
  struct Name * ret = malloc (sizeof(struct Name));\
  Initialize_## Name ##_Object(ret);\
    return ret;}\

#define TYPED_ARRAYED_COLLECTION_DEFINITION_H(Name,X)\
  TYPED_ARRAYED_COLLECTION(Name,X);\
  TYPED_ARRAYED_COLLECTION_SIGNATURES(Name);
#define TYPED_ARRAYED_COLLECTION_DEFINITION_C(Name,X)\
  TYPED_ARRAYED_COLLECTION_INITIALIZE(Name ,X);\
  TYPED_ARRAYED_COLLECTION_NEW(Name);

  
TYPED_ARRAYED_COLLECTION_SIGNATURES(ArrayedCollection);


#endif
