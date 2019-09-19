#! /bin/bash

while true
do
  lockfile -r 0 file.lock || exit 1 #Locking
  current=$( tail -1 file )
  next=$(( current + 1 ))
  echo $next >> file
  rm -f file.lock #Unlocking
done

#As we can see, some numbers written several times because of race conditions
#... 4473 4473 4474 4474 4475 4475 ...
