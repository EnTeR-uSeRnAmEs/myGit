#include "unity.h"
#include"unordered_map.h"
#include <stdio.h>

void test_Allocate_Size(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);

	TEST_ASSERT_EQUAL(expected_size,test_hash_table->size_);
	delete_map(test_hash_table);
}
void test_Allocate_Item_Array(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);

	TEST_ASSERT_NOT_EQUAL(NULL,test_hash_table->hash_table_);

	delete_map(test_hash_table);
}

void test_Deallocate_Item_Array(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);
	delete_map(test_hash_table);
	TEST_ASSERT_NOT_EQUAL(expected_size,test_hash_table->size_);
	TEST_ASSERT_EQUAL(NULL,test_hash_table->hash_table_);
}

void test_Deallocate_Size(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);
	delete_map(test_hash_table);
	TEST_ASSERT_NOT_EQUAL(expected_size,test_hash_table->size_);
}
void test_Insert_Non_Collider_Value_Key(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);
	int expected_key = 0;
	int expected_value =1;
	unordered_map_insert(test_hash_table,expected_key,expected_value);
	TEST_ASSERT_EQUAL(test_hash_table->hash_table_[0]->key_,expected_key);
	delete_map(test_hash_table);
}

void test_Insert_Non_Collider_Value_Value(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);
	int expected_key = 0;
	int expected_value =1;
	unordered_map_insert(test_hash_table,expected_key,expected_value);
	TEST_ASSERT_EQUAL(test_hash_table->hash_table_[0]->value_,expected_value);
	delete_map(test_hash_table);
}
void test_Insert_Collider_Value_Value_First_Item(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);
	int expected_key = 0;
	int expected_value =1;
	int collider_key = 10;
	int collider_value =10;
	unordered_map_insert(test_hash_table,expected_key,expected_value);
	unordered_map_insert(test_hash_table,collider_key,collider_value);
	TEST_ASSERT_EQUAL(test_hash_table->hash_table_[0]->value_,expected_value);
	delete_map(test_hash_table);
}
void test_Insert_Collider_Value_Value_Second_Item(void)
{
	size_t expected_size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(expected_size);
	int first_key = 0;
	int first_value =1;
	int expected_key = 0;
	int expected_value =10;

	unordered_map_insert(test_hash_table,first_key,first_value);
	unordered_map_insert(test_hash_table,expected_key,expected_value);
	item_t* second_item = (item_t*)test_hash_table->hash_table_[0]->next_;
	TEST_ASSERT_EQUAL(second_item->value_,expected_value);
	delete_map(test_hash_table);
}

void test_Retrieve_A_Non_Collider_Value(void){
	size_t size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(size);

	int expected_key = 1;
	int expected_value =11;
	int actual_value = 0;


	unordered_map_insert(test_hash_table, expected_key, expected_value);

	actual_value =*unordered_map_find(test_hash_table,expected_key);

	TEST_ASSERT_EQUAL(actual_value, expected_value);
	delete_map(test_hash_table);
}
void test_Retrieve_A_Collider_Value(void){
	size_t size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(size);
	int collider_key =1;
	int collider_value = 1;
	int expected_key = 11;
	int expected_value =11;
	int actual_value = 0;


	unordered_map_insert(test_hash_table, collider_key, collider_value);
	unordered_map_insert(test_hash_table, expected_key, expected_value);

	actual_value =*unordered_map_find(test_hash_table,expected_key);

	TEST_ASSERT_EQUAL(actual_value, expected_value);
	delete_map(test_hash_table);
}

void test_Retrieve_A_Non_Exiting_Value(void){
	size_t size = 10;
	unordered_map_t* test_hash_table = new_unordered_map(size);

	int test_key = 1;
	int* expected_value =NULL;
	int* actual_value = NULL;

	actual_value =unordered_map_find(test_hash_table,test_key);

	TEST_ASSERT_EQUAL(actual_value, expected_value);
	delete_map(test_hash_table);
}

int main(void)
{
UNITY_BEGIN();
	RUN_TEST(test_Allocate_Size);
	RUN_TEST(test_Allocate_Item_Array);
	RUN_TEST(test_Deallocate_Item_Array);
	RUN_TEST(test_Deallocate_Size);
	RUN_TEST(test_Insert_Non_Collider_Value_Value);
	RUN_TEST(test_Insert_Non_Collider_Value_Key);
	RUN_TEST(test_Insert_Collider_Value_Value_First_Item);
	RUN_TEST(test_Insert_Collider_Value_Value_Second_Item);
	RUN_TEST(test_Retrieve_A_Non_Collider_Value);
	RUN_TEST(test_Retrieve_A_Collider_Value);
	RUN_TEST(test_Retrieve_A_Non_Exiting_Value);

return UNITY_END();
}
