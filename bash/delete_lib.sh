#!/bin/sh

# check argument
if [ $# -ne 1 ]; then
  echo "Need only one argument for directory name."
  exit 1
fi

# handle command line argument
LIB_NAME=$1
HOME_DIR=/design_pattern

# delete directory
rm -rf $HOME_DIR/src/$LIB_NAME

# delete line from $HOME_DIR/src/CMakeLists.txt
FILE="$HOME_DIR/src/CMakeLists.txt"
sed -i -e "/add_subdirectory($LIB_NAME)/d" $FILE
sed -i -e "/mod/d" $FILE

# delete line from $HOME_DIR/test/CMakeLists.txt
FILE=$HOME_DIR/test/CMakeLists.txt
sed -i -e /$LIB_NAME/d $FILE

# delete $HOME_DIR/test/$LIB_NAME_test.cc
FILE=$HOME_DIR/test/$LIB_NAME'_test.cc'
rm -f $FILE
