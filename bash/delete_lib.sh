#!/bin/sh

# Check argument
if [ $# -ne 1 ]; then
  echo "Need only one argument for directory name."
  exit 1
fi

# Handle to command line argument
LIB_NAME=$1
HOME_DIR=/design_pattern

# Changeble valiable
FILE=""

# Delete directory
rm -rf $HOME_DIR/src/$LIB_NAME

# Delete line from $HOME_DIR/src/CMakeLists.txt
FILE="$HOME_DIR/src/CMakeLists.txt"
sed -i -e "/add_subdirectory($LIB_NAME)/d" $FILE
sed -i -e "/$LIB_NAME/d" $FILE

# Delete line from $HOME_DIR/test/CMakeLists.txt
FILE=$HOME_DIR/test/CMakeLists.txt
sed -i -e /$LIB_NAME/d $FILE

# Delete $HOME_DIR/test/$LIB_NAME_test.cc
FILE=$HOME_DIR/test/$LIB_NAME'_test.cc'
rm -f $FILE
