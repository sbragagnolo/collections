
#Using collections 

Collections is a simple library that adds a "generic fashion" typed collection. So far the only flavour available is Array based layout.


# General phylosophy. 

This collections are full C implementation, with OO/function pointer sauce. 

This library offers:

Collection: Generic struct that offers access only to the API of a collection. 
ArrayedCollection: Array implementation, based on void* elements. Nice for cases where we don't care to have casts anywhere.
Generated collection: This collections are based on ArrayedCollection implementation, but they do rely on typed signatures, and typed data container.


The general API is defined in the struct Collection as follow (The following definition was modified to be more readable. It would not compile. ):
```
typedef struct Collection {
// ADD - REMOVE
	int add (struct Collection* self, void* item);
	boolean remove (struct Collection*, void*);
	int  addAll (struct Collection* self, struct Collection otherCollection);
// TEST
	boolean allSatisfy (struct Collection* self, boolean Condition (struct Collection* self, void* item, void* aParameter), void* aParameter);
	boolean anySatisfy (struct Collection* self, boolean Condition (void*self, void* item, void* aParameter), void* aParameter);
// ITERATION
	struct Collection* collect (struct Collection* self, void* Map (void* item));
	void* detect (struct Collection* self, boolean Comparator (struct Collection* self, void* item, void*aParameter), void* aParameter);
	void* inject (struct Collection* self, void* Into (struct Collection* self, void*item, void*Rslt), void* Rslt);
	void* select (struct Collection* self, boolean Condition (void* item, void* aParameter), void* aParameter);
	void forEach (struct Collection* self, void function (struct Collection* self, void* item, void* aParameter), void* aParameter);
// COLLECTION 
	int count (struct Collection* self);
	void* first (struct Collection* self);
	void* last(struct Collection* self);
	void* anyOne (struct Collection* self);
	void finalize (struct Collection* self);
}
```

# General API 

```
  ArrayedCollection self = ArrayedCollection_New();
  self->add (self, item); // Adds an item to the collection 
  self->remove (self, item); // removes the item from the collection 
  self->addAll (self, otherCollection); // Adds all the elements from otherCollection into " self " 
// TEST
  boolean EqualsTo (struct Collection* aCollection, void* item, void* aParameter){
      return item == aParameter;
  }
  self->allSatisfy (self, EqualsTo, 2);  // Returns true if all the items are 2 
  self->anySatisfy (self, EqualsTo, 2); // Returns true if any of the items is 2 
// ITERATION
  
  void* MapToSubItem (void* item) {
    return item->subitem;
  }
  struct Collection* c =  self->collect (self,MapToSubItem); // Returns a collection with subitems per item. 
  void* item = self->detect (self, EqualsTo, 2); // returns the first item that is equals to 2 
  void * Sum (struct Collection* self, void* item, void* Rslt) {
    int i = (int) item; acc = (int) Rslt;
    return (void*) i + acc;
  }
  void* rslt =  self->inject (self, Sum, 0); // Folds / inject the Sum function through all the collection. 
  
  struct Collection* sub = self->select (self,EqualsTo, 2); // Returns a subset of all the items equals to 2 
  
  void Log (struct Collection* self, void* item, void* aParameter) {
      printf( " Log: %p ", item);
  }
  self->forEach (self,Log,NULL); // It executes the given function with each item in the collection 
// COLLECTION 
  self->count (self); // Returns the size of the collection 
  self->first ( self); // Returns the first element 
  self->last(self); // Returns the last element 
  self->anyOne (self); // Returns any element
  self->finalize (self); // Releases all the memory.
```

## Generating your own collection 

In your header file add the following lines:

```
#include <Collection.h>
TYPED_ARRAYED_COLLECTION_DEFINITION_H(CollectionName, ContainedType)
```

In your source file add the following lines: 

```
#include <MyHeader.h>
TYPED_ARRAYED_COLLECTION_DEFINITION_C(CollectionName, ContainedType)
```

This pragmas will generate the needed structures and functions for using the new type. 
In the source code you will be able to:

```
#include <MyHeader.h>
TYPED_ARRAYED_COLLECTION_DEFINITION_C(CollectionName, ContainedType)

CollectionName collection; 
Initialize_CollectionName_Object(&collection); 

CollectionName * collectionPtr;
collectionPtr = CollectionName_New();

```

Remeber to execute the finalize method for releasing the collection. 
Even if it is stored in a static memory variable, the content must be released. 
Note that the finalize function executed in a CollectionName * collection will automatically release the collection pointer as well. 

```
#include <MyHeader.h>
TYPED_ARRAYED_COLLECTION_DEFINITION_C(CollectionName, ContainedType)

CollectionName collection; 
Initialize_CollectionName_Object(&collection); 

CollectionName * collectionPtr;
collectionPtr = CollectionName_New();

collection.finalize(&collection);
collectionPtr->finalize(collectionPtr);
```
