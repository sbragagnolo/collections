/*
 * ModuleInstallationTests.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: santiago
 */

#include <check.h>

#include <Collection.h>

int malloc_called = 0, realloc_called = 0, calloc_called = 0, free_called = 0;

void * custom_malloc(size_t size) {
	malloc_called++;
	return (void*) malloc(size);
}
void * custom_calloc(size_t size, size_t t) {
	calloc_called++;
	return (void*) calloc(size, t);
}
void * custom_realloc(void* ptr, size_t size) {
	realloc_called++;
	return (void*) realloc(ptr, size);
}
void custom_free(void* ptr) {
	free_called++;
	free(ptr);
}

TYPED_ARRAYED_COLLECTION_DEFINITION_H(Generated, char*);
TYPED_ARRAYED_COLLECTION_DEFINITION_C(Generated, char*);

typedef enum {
	VALUE, VALUE2

} ArbitraryTestingEnum;
TYPED_ARRAYED_COLLECTION_DEFINITION_H(GeneratedEnumCollection, ArbitraryTestingEnum);
TYPED_ARRAYED_COLLECTION_DEFINITION_C(GeneratedEnumCollection, ArbitraryTestingEnum);

START_TEST(ArrayedCollectionMemoryLayoutAsExpected)
	{
		//
		int fields, functions, data;
		fields = sizeof(int) * 4;
		data = sizeof(void*);
		functions = sizeof(void*) * 19;
		ck_assert_int_eq(sizeof(ArrayedCollection), fields + data + functions);
		ck_assert_int_eq(sizeof(ArrayedCollection), sizeof(GeneratedEnumCollection));

	}END_TEST

START_TEST(ArrayedCollectionCastsKeepsFunctionsPointersExpected)
	{

		ArrayedCollection* t;
		Collection* c;
		t = ArrayedCollection_New();
		c = (Collection *) t;

		ck_assert_ptr_eq(c->add, t->add);
		ck_assert_ptr_eq(c->remove, t->remove);
		ck_assert_ptr_eq(c->dequeue, t->dequeue);
		ck_assert_ptr_eq(c->addAll, t->addAll);
		ck_assert_ptr_eq(c->allSatisfy, t->allSatisfy);
		ck_assert_ptr_eq(c->anySatisfy, t->anySatisfy);
		ck_assert_ptr_eq(c->collect, t->collect);
		ck_assert_ptr_eq(c->detect, t->detect);
		ck_assert_ptr_eq(c->inject, t->inject);
		ck_assert_ptr_eq(c->select, t->select);
		ck_assert_ptr_eq(c->forEach, t->forEach);
		ck_assert_ptr_eq(c->count, t->count);
		ck_assert_ptr_eq(c->first, t->first);
		ck_assert_ptr_eq(c->last, t->last);
		ck_assert_ptr_eq(c->anyOne, t->anyOne);
		ck_assert_ptr_eq(c->finalize, t->finalize);

	}END_TEST

START_TEST(ArrayedCollectionUsesArrayedCollectionFunctions)
	{
		ArrayedCollection c;
		Initialize_ArrayedCollection_Object(&c);
		ck_assert_ptr_eq(c.add, Arrayed_Collection_Add);
		ck_assert_ptr_eq(c.dequeue, Arrayed_Collection_Dequeue);
		ck_assert_ptr_eq(c.remove, Arrayed_Collection_Remove);
		ck_assert_ptr_eq(c.addAll, Arrayed_Collection_AddAll);
		ck_assert_ptr_eq(c.allSatisfy, Arrayed_Collection_AllSatisfy);
		ck_assert_ptr_eq(c.anySatisfy, Arrayed_Collection_AnySatisfy);
		ck_assert_ptr_eq(c.collect, Arrayed_Collection_Collect);
		ck_assert_ptr_eq(c.detect, Arrayed_Collection_Detect);
		ck_assert_ptr_eq(c.inject, Arrayed_Collection_Inject);
		ck_assert_ptr_eq(c.select, Arrayed_Collection_Select);
		ck_assert_ptr_eq(c.forEach, Arrayed_Collection_ForEach);
		ck_assert_ptr_eq(c.count, Arrayed_Collection_Count);
		ck_assert_ptr_eq(c.first, Arrayed_Collection_First);
		ck_assert_ptr_eq(c.last, Arrayed_Collection_Last);
		ck_assert_ptr_eq(c.anyOne, Arrayed_Collection_AnyOne);
		ck_assert_ptr_eq(c.finalize, Arrayed_Collection_Finalize);
	}END_TEST

START_TEST(ArrayedCollectionUsesSpecificFinalizeForNew)
	{
		ArrayedCollection * c = ArrayedCollection_New();
		ck_assert_ptr_eq(c->add, Arrayed_Collection_Add);
		ck_assert_ptr_eq(c->dequeue, Arrayed_Collection_Dequeue);
		ck_assert_ptr_eq(c->remove, Arrayed_Collection_Remove);
		ck_assert_ptr_eq(c->addAll, Arrayed_Collection_AddAll);
		ck_assert_ptr_eq(c->allSatisfy, Arrayed_Collection_AllSatisfy);
		ck_assert_ptr_eq(c->anySatisfy, Arrayed_Collection_AnySatisfy);
		ck_assert_ptr_eq(c->collect, Arrayed_Collection_Collect);
		ck_assert_ptr_eq(c->detect, Arrayed_Collection_Detect);
		ck_assert_ptr_eq(c->inject, Arrayed_Collection_Inject);
		ck_assert_ptr_eq(c->select, Arrayed_Collection_Select);
		ck_assert_ptr_eq(c->forEach, Arrayed_Collection_ForEach);
		ck_assert_ptr_eq(c->count, Arrayed_Collection_Count);
		ck_assert_ptr_eq(c->first, Arrayed_Collection_First);
		ck_assert_ptr_eq(c->last, Arrayed_Collection_Last);
		ck_assert_ptr_eq(c->anyOne, Arrayed_Collection_AnyOne);
		ck_assert_ptr_eq(c->finalize, Arrayed_Collection_Finalize_Object);
		ck_assert_ptr_eq(c->__Write, __Write_ArrayedCollection);
		ck_assert_ptr_eq(c->__Read, __Read_ArrayedCollection);

		c->finalize(c);
	}END_TEST

START_TEST(GeneratedCollectionUsesSpecificFinalizeForNew)
	{
		Generated * c = Generated_New();
		ck_assert_ptr_eq(c->add, Arrayed_Collection_Add);
		ck_assert_ptr_eq(c->dequeue, Arrayed_Collection_Dequeue);
		ck_assert_ptr_eq(c->remove, Arrayed_Collection_Remove);
		ck_assert_ptr_eq(c->addAll, Arrayed_Collection_AddAll);
		ck_assert_ptr_eq(c->allSatisfy, Arrayed_Collection_AllSatisfy);
		ck_assert_ptr_eq(c->anySatisfy, Arrayed_Collection_AnySatisfy);
		ck_assert_ptr_eq(c->collect, Arrayed_Collection_Collect);
		ck_assert_ptr_eq(c->detect, Arrayed_Collection_Detect);
		ck_assert_ptr_eq(c->inject, Arrayed_Collection_Inject);
		ck_assert_ptr_eq(c->select, Arrayed_Collection_Select);
		ck_assert_ptr_eq(c->forEach, Arrayed_Collection_ForEach);
		ck_assert_ptr_eq(c->count, Arrayed_Collection_Count);
		ck_assert_ptr_eq(c->first, Arrayed_Collection_First);
		ck_assert_ptr_eq(c->last, Arrayed_Collection_Last);
		ck_assert_ptr_eq(c->anyOne, Arrayed_Collection_AnyOne);
		ck_assert_ptr_eq(c->finalize, Arrayed_Collection_Finalize_Object);
		ck_assert_ptr_eq(c->__Write, __Write_Generated);
		ck_assert_ptr_eq(c->__Read, __Read_Generated);
		c->finalize(c);
	}END_TEST
START_TEST(GeneratedCollectionCastsKeepsFunctionsPointersExpected)
	{

		Generated* t = Generated_New();
		Collection* c;
		c = (Collection*) t;
		ck_assert_ptr_eq(c->add, t->add);
		ck_assert_ptr_eq(c->dequeue, t->dequeue);
		ck_assert_ptr_eq(c->remove, t->remove);
		ck_assert_ptr_eq(c->addAll, t->addAll);
		ck_assert_ptr_eq(c->allSatisfy, t->allSatisfy);
		ck_assert_ptr_eq(c->anySatisfy, t->anySatisfy);
		ck_assert_ptr_eq(c->collect, t->collect);
		ck_assert_ptr_eq(c->detect, t->detect);
		ck_assert_ptr_eq(c->inject, t->inject);
		ck_assert_ptr_eq(c->select, t->select);
		ck_assert_ptr_eq(c->forEach, t->forEach);
		ck_assert_ptr_eq(c->count, t->count);
		ck_assert_ptr_eq(c->first, t->first);
		ck_assert_ptr_eq(c->last, t->last);
		ck_assert_ptr_eq(c->anyOne, t->anyOne);
		ck_assert_ptr_eq(c->finalize, t->finalize);
		t->finalize(t);
	}END_TEST
START_TEST(GeneratedCollectionUsesArrayedCollectionFunctions)
	{

		Generated c;
		Initialize_Generated_Object(&c);
		ck_assert_ptr_eq(c.add, Arrayed_Collection_Add);
		ck_assert_ptr_eq(c.remove, Arrayed_Collection_Remove);
		ck_assert_ptr_eq(c.addAll, Arrayed_Collection_AddAll);
		ck_assert_ptr_eq(c.allSatisfy, Arrayed_Collection_AllSatisfy);
		ck_assert_ptr_eq(c.anySatisfy, Arrayed_Collection_AnySatisfy);
		ck_assert_ptr_eq(c.collect, Arrayed_Collection_Collect);
		ck_assert_ptr_eq(c.detect, Arrayed_Collection_Detect);
		ck_assert_ptr_eq(c.inject, Arrayed_Collection_Inject);
		ck_assert_ptr_eq(c.select, Arrayed_Collection_Select);
		ck_assert_ptr_eq(c.forEach, Arrayed_Collection_ForEach);
		ck_assert_ptr_eq(c.count, Arrayed_Collection_Count);
		ck_assert_ptr_eq(c.first, Arrayed_Collection_First);
		ck_assert_ptr_eq(c.last, Arrayed_Collection_Last);
		ck_assert_ptr_eq(c.anyOne, Arrayed_Collection_AnyOne);
		ck_assert_ptr_eq(c.finalize, Arrayed_Collection_Finalize);
		ck_assert_ptr_eq(c.__Write, __Write_Generated);
		ck_assert_ptr_eq(c.__Read, __Read_Generated);
	}END_TEST

START_TEST(ArrayedCollectionCallsMacroMalloc)
	{
		ArrayedCollection c, *o;
		ck_assert(malloc_called == 0);
		Initialize_ArrayedCollection_Object(&c);
		ck_assert(malloc_called == 0);
		o = ArrayedCollection_New();
		ck_assert(malloc_called == 1);
		c.finalize(&c);
		ck_assert(malloc_called == 1);
		o->finalize(o);
		ck_assert(malloc_called == 1);

	}END_TEST
START_TEST(ArrayedCollectionCallsMacroCalloc)
	{
		ArrayedCollection c, *o;
		ck_assert(calloc_called == 0);
		Initialize_ArrayedCollection_Object(&c);
		ck_assert(calloc_called == 1);
		o = ArrayedCollection_New();
		ck_assert(calloc_called == 2);
		c.finalize(&c);
		ck_assert(calloc_called == 2);
		o->finalize(o);
		ck_assert(calloc_called == 2);
	}END_TEST

START_TEST(ArrayedCollectionCallsMacroFree)
	{
		ArrayedCollection c, *o;
		ck_assert(free_called == 0);
		Initialize_ArrayedCollection_Object(&c);
		ck_assert(free_called == 0);
		o = ArrayedCollection_New();
		ck_assert(free_called == 0);
		c.finalize(&c);
		ck_assert(free_called == 1);
		o->finalize(o);
		ck_assert(free_called == 3);
	}END_TEST
START_TEST(ArrayedCollectionCallsMacroRealloc)
	{
		ArrayedCollection c;
		int * data = malloc(sizeof(int));
		*data = 1;

		ck_assert(realloc_called == 0);

		Initialize_ArrayedCollection_Object(&c);

		c.add(&c, data);
		ck_assert(realloc_called == 0);
		c.add(&c, data);
		ck_assert(realloc_called == 0);
		c.add(&c, data);
		ck_assert(realloc_called == 0);
		c.add(&c, data);
		ck_assert(realloc_called == 0);
		c.add(&c, data);
		ck_assert(realloc_called == 0);
		c.add(&c, data);
		ck_assert(realloc_called == 1);
		c.add(&c, data);
		ck_assert(realloc_called == 1);
		c.add(&c, data);
		ck_assert(realloc_called == 2);

		c.finalize(&c);
		ck_assert(realloc_called == 2);

	}END_TEST

int i;
void ForEachTest(void* item, void* aParameter) {
	ck_assert(*(int* )item == 1 || *(int* )item == 2);
	i++;
}

boolean ConditionEquals(void* item, void* aParameter) {

	return (*((int*) item) == *((int*) aParameter)) ? TRUE : FALSE;

}

boolean AllwaysTrueCondition(void* item, void* aParameter) {

	return TRUE;

}

ArrayedCollection createTestedCollection() {
	ArrayedCollection c;

	int * data = malloc(sizeof(int));
	int * data2 = malloc(sizeof(int));
	*data = 1;
	*data2 = 2;
	Initialize_ArrayedCollection_Object(&c);

	c.add(&c, data);
	c.add(&c, data2);
	c.add(&c, data);
	c.add(&c, data2);
	return c;

}
START_TEST(ArrayedCollectionForEachWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		i = 0;
		c.forEach(&c, ForEachTest, NULL);
		ck_assert_int_eq(i, 4);
		c.finalize(&c);
	}END_TEST

void* IntoTest(void*item, void*Rslt) {

	int * param = (int*) Rslt;
	int * each = (int*) item;
	*param = *param + *each;

	return Rslt;
}

START_TEST(ArrayedCollectionInjectIntoWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		int* value;
		i = 0;
		value = (int*) c.inject(&c, IntoTest, (void*) &i);
		ck_assert_int_eq(*value, 6);
		c.finalize(&c);
	}END_TEST

START_TEST(ArrayedCollectionSelectWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		i = 0;
		ArrayedCollection * selection = c.select(&c, ConditionEquals, (void*) &i);
		ck_assert_int_eq(selection->count(selection), 0);
		selection->finalize(selection);

		i = 1;
		selection = c.select(&c, ConditionEquals, (void*) &i);
		ck_assert_int_eq(selection->count(selection), 2);
		selection->finalize(selection);

		i = 2;
		selection = c.select(&c, ConditionEquals, (void*) &i);
		ck_assert_int_eq(selection->count(selection), 2);
		selection->finalize(selection);

		c.finalize(&c);

	}END_TEST

START_TEST(ArrayedCollectionDequeueWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		ck_assert_int_eq(c.count(&c), 4);
		int * data = c.dequeue(&c);
		ck_assert_int_eq(c.count(&c), 3);
		ck_assert_int_eq(*data, 1);
		data = c.dequeue(&c);
		ck_assert_int_eq(c.count(&c), 2);
		ck_assert_int_eq(*data, 2);

	}END_TEST

START_TEST(ArrayedCollectionAllSatisfyTrueWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		ck_assert(c.allSatisfy(&c, AllwaysTrueCondition, NULL));
	}END_TEST

START_TEST(ArrayedCollectionAllSatisfyFalseWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		int data = 1;
		ck_assert(!c.allSatisfy(&c, ConditionEquals, &data));
	}END_TEST
START_TEST(ArrayedCollectionAnySatisfyTrueWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		int data = 1;
		ck_assert(c.anySatisfy(&c, ConditionEquals, &data));
	}END_TEST

START_TEST(ArrayedCollectionAnySatisfyFalseWorksAsExpected)
	{
		ArrayedCollection c = createTestedCollection();
		int data = -1;
		ck_assert(!c.anySatisfy(&c, ConditionEquals, &data));
	}END_TEST

START_TEST(GeneratedEnumCallsMacroRealloc)
	{
		GeneratedEnumCollection c;

		ck_assert(realloc_called == 0);

		Initialize_GeneratedEnumCollection_Object(&c);

		c.add(&c, VALUE);
		ck_assert(realloc_called == 0);
		c.add(&c, VALUE2);
		ck_assert(realloc_called == 0);
		c.add(&c, VALUE);
		ck_assert(realloc_called == 0);
		c.add(&c, VALUE);
		ck_assert(realloc_called == 0);
		c.add(&c, VALUE2);
		ck_assert(realloc_called == 0);
		c.add(&c, VALUE2);
		ck_assert(realloc_called == 1);
		c.add(&c, VALUE2);
		ck_assert(realloc_called == 1);
		c.add(&c, VALUE);
		ck_assert(realloc_called == 2);

		c.finalize(&c);
		ck_assert(realloc_called == 2);

	}END_TEST
START_TEST(GeneratedEnumCallsAddDequeue)
	{
		GeneratedEnumCollection c;

		ck_assert(realloc_called == 0);

		Initialize_GeneratedEnumCollection_Object(&c);

		c.add(&c, VALUE);
		c.add(&c, VALUE2);
		c.add(&c, VALUE);
		c.add(&c, VALUE);
		c.add(&c, VALUE2);
		c.add(&c, VALUE2);
		c.add(&c, VALUE2);
		c.add(&c, VALUE);

		ck_assert_int_eq(c.dequeue(&c), VALUE);
		ck_assert_int_eq(c.dequeue(&c), VALUE2);
		ck_assert_int_eq(c.dequeue(&c), VALUE);
		ck_assert_int_eq(c.dequeue(&c), VALUE);
		ck_assert_int_eq(c.dequeue(&c), VALUE2);
		ck_assert_int_eq(c.dequeue(&c), VALUE2);
		ck_assert_int_eq(c.dequeue(&c), VALUE2);
		ck_assert_int_eq(c.dequeue(&c), VALUE);

		c.finalize(&c);

	}END_TEST

/** SETUP */
static void SetUp() {
	malloc_called = 0;
	calloc_called = 0;
	realloc_called = 0;
	free_called = 0;
	setCallocFunction(custom_calloc);
	setMallocFunction(custom_malloc);
	setReallocFunction(custom_realloc);
	setFreeFunction(custom_free);

}
static void TearDown() {

}

Suite * CreateSuite(void) {
	Suite *s;
	TCase *tc_structure;
	TCase *tc_behaviour;

	s = suite_create("Collection");

	/* Core test case */
	tc_structure = tcase_create("collection-structure");
	tc_behaviour = tcase_create("collection-behaviour");
	tcase_add_test(tc_structure, ArrayedCollectionMemoryLayoutAsExpected);
	tcase_add_test(tc_structure, ArrayedCollectionCastsKeepsFunctionsPointersExpected);
	tcase_add_test(tc_structure, ArrayedCollectionUsesArrayedCollectionFunctions);
	tcase_add_test(tc_structure, ArrayedCollectionUsesSpecificFinalizeForNew);
	tcase_add_test(tc_structure, GeneratedCollectionUsesSpecificFinalizeForNew);
	tcase_add_test(tc_structure, GeneratedCollectionCastsKeepsFunctionsPointersExpected);
	tcase_add_test(tc_structure, GeneratedCollectionUsesArrayedCollectionFunctions);

	tcase_add_test(tc_behaviour, ArrayedCollectionCallsMacroMalloc);
	tcase_add_test(tc_behaviour, ArrayedCollectionCallsMacroCalloc);

	tcase_add_test(tc_behaviour, ArrayedCollectionCallsMacroFree);
	tcase_add_test(tc_behaviour, ArrayedCollectionCallsMacroRealloc);
	tcase_add_test(tc_behaviour, ArrayedCollectionForEachWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionInjectIntoWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionSelectWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionDequeueWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionAllSatisfyTrueWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionAllSatisfyFalseWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionAnySatisfyTrueWorksAsExpected);
	tcase_add_test(tc_behaviour, ArrayedCollectionAnySatisfyFalseWorksAsExpected);

	tcase_add_test(tc_behaviour, GeneratedEnumCallsMacroRealloc);
	tcase_add_test(tc_behaviour, GeneratedEnumCallsAddDequeue);

	tcase_add_unchecked_fixture(tc_structure, SetUp, TearDown);
	tcase_add_unchecked_fixture(tc_behaviour, SetUp, TearDown);

	suite_add_tcase(s, tc_structure);
	suite_add_tcase(s, tc_behaviour);

	return s;
}

int main(void) {

	int number_failed;
	Suite *s;
	SRunner *sr;

	s = CreateSuite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);

	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

}

