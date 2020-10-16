/*
 * Rafael Basso
 * Tiago Gambim
 */
#include "unity.h"
#include "unity_fixture.h"

TEST_GROUP_RUNNER(Sort)
{
  RUN_TEST_CASE(Sort, TestSortOrderedArray);
  RUN_TEST_CASE(Sort, TestSortInvOrderedArray);
  RUN_TEST_CASE(Sort, TestZeroSize);
  RUN_TEST_CASE(Sort, TestMaxAndMinInt);
  RUN_TEST_CASE(Sort, TestConstantntInt);
  
}
