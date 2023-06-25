## BUILD
``` docker-compose exec dev cmake ..```
``` docker-compose exec dev make```
or
``` docker-compose exec dev ../bash/rebuild.sh```

## EXECUTE
``` docker-compose exec dev src/my_app```

## LINT TOOL
``` docker-compose exec dev ../bash/cpplint.sh```
or
``` docker-compose exec dev cpplint ../src/main.cc ```

## UNIT TEST TOOL
``` docker-compose exec dev ctest --verbose```

## CREATE LIBRARY
``` docker-compose exec dev ../bash/create_lib.sh <library name>```

## DELETE LIBRARY
``` docker-compose exec dev ../bash/delete_lib.sh <library name>```
