#!/bin/bash

./make_release.sh

cd func_tests || exit
./all_tests.sh
cd ..

./make_clean.sh