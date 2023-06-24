#!/bin/bash
apt-get update && apt-get install -yq libboost-all-dev
mkdir -p ~/boost
for dep in libboost-all-dev; do
  dpkg -L $dep | while IFS= read -r f; do
    if test -f $f; then
      echo $f;
    fi;
  done | xargs cp --parents --target-directory ~/boost/
done
