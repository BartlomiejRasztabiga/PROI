#!/usr/bin/env sh

cmake --build ./cmake-build-debug --target CarPark_run
./cmake-build-debug/CarPark_run "$@"
