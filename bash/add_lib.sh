#!/bin/sh

# check argument
if [ $# -ne 1 ]; then
  echo "Need only one argument for directory name."
  exit 1
fi

# handle command line argument
NAME=$1
UPPER_NAME=`echo $1 | tr '[a-z]' '[A-Z]'`
TEST_NAME=$1"_"test
HOME_DIR=/design_pattern
NEW_DIR="$HOME_DIR/src/$NAME"
NEW_TEST_DIR="$HOME_DIR/test"

# Create directory
if [ -e $NEW_DIR ]; then
  echo "Directory is aleady exist."
  exit 1
else
  mkdir -p $NEW_DIR
fi

# Create files
CMAKE_FILE="$NEW_DIR/CMakeLists.txt"
CC_FILE="$NEW_DIR/$NAME.cc"
HH_FILE="$NEW_DIR/$NAME.hh"
TEST_FILE=$NEW_TEST_DIR/$TEST_NAME.cc

touch $CMAKE_FILE
touch $CC_FILE
touch $HH_FILE
touch $TEST_FILE

# Create CMakeTexts.txt
GTEST_ROOT='${GTEST_ROOT}'
CMAKE_ROOT='${CMAKE_CURRENT_SOURCE_DIR}'

TEXT="add_library($NAME SHARED $NAME.cc)"

echo "$TEXT" > $CMAKE_FILE

# Create $NAME.hh
GUARD=SRC_$UPPER_NAME"_"$UPPER_NAME"_HH_"

TEXT="// Copyright $(date +%Y) saito
#ifndef $GUARD
#define $GUARD

#include <iostream>

namespace $NAME {
int sum(int, int);
}  // namespace $NAME

#endif  // $GUARD"
echo "$TEXT" > $HH_FILE

# create $NAME.cc
INCLUDE_FILE_NAME='"../../src/'$NAME/$NAME.hh'"'
TEXT="// Copyright $(date +%Y) saito
#include $INCLUDE_FILE_NAME


namespace $NAME {
int sum(int a, int b) {
  return a + b;
}
}  // namespace $NAME"
echo "$TEXT" > $CC_FILE

# create $NAME_test.cc
INCLUDE_FILE_NAME='"../src/'$NAME/$NAME.hh'"'
TEXT="// Copyright $(date +%Y) saito
#include $INCLUDE_FILE_NAME
#include <gtest/gtest.h>

TEST($NAME, sum_test) {
  EXPECT_EQ(3, $NAME::sum(1, 2));
}"
echo "$TEXT" > $TEST_FILE

# add to $HOME_DIR/src/CMakeLists.txt
FILE="$HOME_DIR/src/CMakeLists.txt"
TEXT="add_subdirectory($NAME)"
INSERTED_TEXT="add_executable(my_app main.cc)"
sed -i -e "/$INSERTED_TEXT/a $TEXT" $FILE

INSERTED_TEXT='PUBLIC "-pthread"'
sed -i -e "/$INSERTED_TEXT/a $NAME" $FILE

# add to $HOME_DIR/test/CMakeLists.txt
FILE="$HOME_DIR/test/CMakeLists.txt"
sed -i -e "8a $NAME" $FILE
