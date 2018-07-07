#! /bin/bash

make
output=$(./zed <<< 'Hello World!')

if ! [ "$output" = 'Hello World!' ]; then
  echo "Expected 'Hello World!' but got $output" >&2
  exit 1
fi

output=$(./zed -n <<< 'Hello')
if [ -n "$output" ]; then
  echo "Expected empty output but got $output" >&2
  exit 1
fi

output=$(./zed -e '[0-9]+/d' <<< $'998098\nHello')
if ! [ "$output" = 'Hello' ]; then
  echo "Expected 'Hello' but got $output" >&2
  exit 1
fi
