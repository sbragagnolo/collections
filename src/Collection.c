#include "Collection.h" 

TYPED_ARRAYED_COLLECTION_DEFINITION_C(ArrayedCollection, void*);


void * (*CALLOC)(size_t count, size_t size) = calloc;
void * (*MALLOC)(size_t count) = malloc;
void * (*REALLOC)(void* ptr, size_t size) = realloc;
void (*FREE)(void*ptr) = free;

void setCallocFunction(void * (*fn)(size_t count, size_t size)) {
	CALLOC = fn;
}
void setMallocFunction(void * (*fn)(size_t count)) {
	MALLOC = fn;

}
void setReallocFunction(void * (*fn)(void* ptr, size_t size)) {
	REALLOC = fn;
}
void setFreeFunction(void (*fn)(void*ptr)) {
	FREE = fn;
}

void* (* getCallocFunction(void))(size_t count, size_t size) {
	return CALLOC;
}
void* (* getMallocFunction(void))(size_t size) {
	return MALLOC;
}
void*(* getReallocFunction(void))(void* ptr, size_t size) {
	return REALLOC;
}
void (* getFreeFunction(void))(void* ptr) {
	return FREE;
}

void __AUX_Collection_AddInto(struct Collection* self, void* item, void* into) {
	Arrayed_Collection_Add((struct ArrayedCollection*) into, item);
}

int Arrayed_Collection_Add(struct ArrayedCollection* self, void* item) {
	if (self->used >= self->size) {
		self->size += 2;
		self->data = getReallocFunction()(self->data, self->size * self->typeSize);
	}
	self->__Write(self, self->used, item);
	self->used++;
	return self->used - 1;
}

void* Arrayed_Collection_Dequeue(struct ArrayedCollection* self) {
	void* item = self->data[0];
	int i;
	for (i = 0; i < self->used; i++) {
		self->__Write(self, i, (self->__Read(self, i + 1)));
	}
	self->used--;

	return item;
}

boolean Arrayed_Collection_Remove(struct ArrayedCollection* self, void* item) {
	return FALSE;
}

int Arrayed_Collection_AddAll(struct ArrayedCollection* self, struct Collection* otherCollection) {
	otherCollection->forEach(otherCollection, (void (*)(void*, void*)) __AUX_Collection_AddInto, self);
	return otherCollection->count(otherCollection);
}

boolean Arrayed_Collection_AllSatisfy(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter) {
	int i;
	for (i = 0; i < self->used; i++) {
		if (!Condition(self->__Read(self, i), aParameter)) return FALSE;
	}
	return TRUE;
}

boolean Arrayed_Collection_AnySatisfy(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter) {
	int i;
	for (i = 0; i < self->used; i++) {
		if (Condition(self->__Read(self, i), aParameter)) return TRUE;
	}
	return FALSE;
}

struct Collection* Arrayed_Collection_Collect(struct ArrayedCollection* self, void* (*Map)(void* item)) {
	int i;
	ArrayedCollection * col = ArrayedCollection_New();

	for (i = 0; i < self->used; i++) {
		col->add(col, Map(self->__Read(self, i)));
	}
	return (struct Collection*) col;
}
struct ArrayedCollection* Arrayed_Collection_Select(struct ArrayedCollection* self, boolean (*Condition)(void* item, void* aParameter), void* aParameter) {
	int i;
	ArrayedCollection * col = ArrayedCollection_New();

	for (i = 0; i < self->used; i++) {
		if (Condition(self->__Read(self, i), aParameter)) {
			col->add(col, self->__Read(self, i));
		}
	}
	return col;
}
void* Arrayed_Collection_Detect(struct ArrayedCollection* self, boolean (*Comparator)(void* item, void*aParameter), void* aParameter) {
	int i;
	for (i = 0; i < self->used; i++) {
		if (Comparator(self->__Read(self, i), aParameter)) return self->__Read(self, i);
	}
	return NULL;
}
void* Arrayed_Collection_Inject(struct ArrayedCollection* self, void* (*Into)(void*, void*), void* parameter) {
	void * result = parameter;
	int i;
	for (i = 0; i < self->used; i++) {
		result = Into(self->__Read(self, i), result);
	}
	return result;

}

void Arrayed_Collection_ForEach(struct ArrayedCollection* self, void (*function)(void* item, void* aParameter), void* aParameter) {
	int i;
	for (i = 0; i < self->used; i++) {
		function(self->__Read(self, i), aParameter);
	}
}

int Arrayed_Collection_Count(struct ArrayedCollection* self) {
	return self->used;
}
void* Arrayed_Collection_First(struct ArrayedCollection* self) {
	return self->__Read(self, 0);
}
void* Arrayed_Collection_Last(struct ArrayedCollection* self) {
	return self->__Read(self, self->used - 1);
}
void* Arrayed_Collection_AnyOne(struct ArrayedCollection* self) {
	return self->__Read(self, 0);
}
void Arrayed_Collection_Finalize(struct ArrayedCollection* self) {
	FREE(self->data);
	memset(self, 0, sizeof(struct ArrayedCollection));
}
void Arrayed_Collection_Finalize_Object(struct ArrayedCollection* self) {
	FREE(self->data);
	memset(self, 0, sizeof(struct ArrayedCollection));
	FREE(self);
}

