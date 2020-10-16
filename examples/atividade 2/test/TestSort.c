/*
 * Rafael Basso
 * Tiago Gambim
 */

#include "sort.h"
#include "unity.h"
#include "unity_fixture.h"

#define ARRAY_SIZE 100

TEST_GROUP(Sort);

static int v[ARRAY_SIZE];
static int expected[ARRAY_SIZE];

TEST_SETUP(Sort){
	memset(v, 3, ARRAY_SIZE);
	memset(expected, 3, ARRAY_SIZE);
}

TEST_TEAR_DOWN(Sort){
}

static void with(const int * data, int size){
	memcpy(v, data, size*sizeof(int));
}

static void expect(const int * e, int size){
	memcpy(expected, e, size*sizeof(int));
	//verifica se ordenou e se nao editou as posicoes fora do limite
	TEST_ASSERT_EQUAL_INT_ARRAY(expected, v, ARRAY_SIZE);
}

TEST(Sort, TestSortOrderedArray){
	with((int[]) {1, 2, 3, 4, 5}, 5);
	sort(v, 5);
	expect((int[]) {1, 2, 3, 4, 5}, 5);
}

TEST(Sort, TestSortInvOrderedArray){
	with((int[]) {5, 4, 3,  2, 1}, 5);
	sort(v, 5);
	expect((int[]) {1, 2, 3, 4, 5}, 5);	
}

TEST(Sort, TestZeroSize){
	//não deve mexer no array
	with((int[]) {}, 0);
	sort(v, 0);
	expect((int[]) {}, 0);	
}

TEST(Sort, TestMaxAndMinInt){
	with((int[]) {INT_MAX, 4312, INT_MIN, INT_MAX-1, 0, INT_MIN+1}, 6);
	sort(v, 6);
	expect((int[]) {INT_MIN, INT_MIN+1, 0, 4312, INT_MAX-1, INT_MAX}, 6);	
}

TEST(Sort, TestConstantntInt){
	with((int[]) {1, 1, 1, 1, 1}, 5);
	sort(v, 5);
	expect((int[]) {1, 1, 1, 1, 1}, 5);	
}
