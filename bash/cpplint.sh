#!/bin/bash

cpplint --recursive ../src \
&& cpplint --recursive ../test
