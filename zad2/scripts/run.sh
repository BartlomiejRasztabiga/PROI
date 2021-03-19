#!/usr/bin/env sh

cmake --build ./cmake-build-debug --target Chart_run
./cmake-build-debug/Chart_run "$@"
