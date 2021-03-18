#!/usr/bin/env sh

cmake --build ./cmake-build-debug --target Doctest_tests_run
./cmake-build-debug/Doctest_tests/Doctest_tests_run