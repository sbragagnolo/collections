#include "Collection.h" 

TYPED_ARRAYED_COLLECTION_INITIALIZE(ArrayedCollection, void);
TYPED_ARRAYED_COLLECTION_NEW(ArrayedCollection);


void __AUX_Collection_AddInto (struct Collection* self, void* item, void* into) {
   Arrayed_Collection_Add ((struct ArrayedCollection*)into, item);
}


int Arrayed_Collection_Add (struct ArrayedCollection* self, void* item) {
   if (self->used >= self->size) {
        self->size += 2;
        self->data = realloc(self->data, self->size * sizeof(void*));
   }
    
   self->data[self->used] = item; 
   self->used ++;
   return self->used - 1;
}



bool Arrayed_Collection_Remove  (struct ArrayedCollection* self,void* item) {
	return FALSE; 
}

int Arrayed_Collection_AddAll (struct ArrayedCollection* self, struct Collection* otherCollection ) {
   otherCollection->forEach(otherCollection, (void(*)(struct Collection*,void*,void*))__AUX_Collection_AddInto, self);
   return otherCollection->count(otherCollection);
}

bool Arrayed_Collection_AllSatisfy (struct ArrayedCollection* self, bool (*Condition) (struct ArrayedCollection* self, void* item, void* aParameter), void* aParameter) {
int i;
	for( i = 0 ; i < self->used ; i ++ ) {
		if(!Condition(self, self->data[i], aParameter)) return FALSE;
	}
	return TRUE;
}


bool Arrayed_Collection_AnySatisfy (struct ArrayedCollection* self, bool (*Condition) (void*self, void* item, void* aParameter), void* aParameter) {
int i;
	for(  i = 0 ; i < self->used ; i ++ ) {
		if(Condition(self, self->data[i], aParameter)) return TRUE;
	}
	return FALSE;
}


struct Collection* Arrayed_Collection_Collect (struct ArrayedCollection* self, void* (*Map) (void* item)) {	
int i;
	ArrayedCollection * col = ArrayedCollection_New();
        
	for(  i = 0 ; i < self->used ; i ++ ) {
		col->add( col, Map(self->data[i]));
	}
	return (struct Collection*)col;
}
struct ArrayedCollection* Arrayed_Collection_Select (struct ArrayedCollection* self, bool (*Condition) (void* item, void* aParameter), void* aParameter) {
int i;
	ArrayedCollection * col = ArrayedCollection_New();
        
	for(  i = 0 ; i < self->used ; i ++ ) {
		if( Condition( self->data[i], aParameter )) {
			col->add( col, self->data[i]);		
		}
	}
	return col;
}
void* Arrayed_Collection_Detect (struct ArrayedCollection* self, bool (*Comparator) (struct ArrayedCollection* self, void* item, void*aParameter), void* aParameter) {
int i;
	for(  i = 0 ; i < self->used ; i ++ ) {
		if (Comparator(self, self->data[i], aParameter ) ) return self->data[i];
	}	
return NULL;
}
void* Arrayed_Collection_Inject (struct ArrayedCollection* self, void* (*Into) (struct ArrayedCollection*, void*, void*), void* parameter) {
void * result = parameter;
int i;
	for(  i = 0 ; i < self->used ; i ++ ) {
		result = Into(self, self->data[i], result ) ;
	}
return result; 

}


void Arrayed_Collection_ForEach (struct ArrayedCollection* self, void (*function) (struct ArrayedCollection* self, void* item, void* aParameter), void* aParameter){
int i;
	for(i = 0 ; i < self->used ; i ++ ) {
		function(self, self->data[i], aParameter );
	}	
}

int Arrayed_Collection_Count (struct ArrayedCollection* self) {
	return self->used;
}
void* Arrayed_Collection_First (struct ArrayedCollection* self) {
	return self->data[0];
}
void* Arrayed_Collection_Last (struct ArrayedCollection* self) {
	return self->data[self->used-1];
}
void* Arrayed_Collection_AnyOne (struct ArrayedCollection* self) {
	return self->data[0];
}
void Arrayed_Collection_Finalize (struct ArrayedCollection* self) {
	free(self->data);
	memset(self, 0, sizeof(struct ArrayedCollection));
}
