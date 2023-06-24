## OBJECTIVE
- デザインパターンの学習すること
- デザインパターンを用いた設計をできるようになること

## EVALUATED
- デザインパターンを網羅的に学習できていること
- それぞれのデザインパターンを適切なタイミングで実装できること

## STUDY
デザインパターンの学習は以下サイトで行うものとする。
https://refactoring.guru/ja/design-patterns

## SYSTEM DESIGN
設計は下記サイトの問題を扱うものとする
http://codekata.com/

## LANGUAGE
- C++
- CMake

build command:
``` docker-compose exec dev cmake ..```
``` docker-compose exec dev make```

execute command:
``` docker-compose exec dev src/my_app```

## CODING STYLE
以下 "Google C++ Stype Guide" に従うものとする
https://google.github.io/styleguide/cppguide.html

### LINT TOOL USAGE
- Cpplintを使用。以下コマンドで実行可能
``` cpplint <filename>```
ex: ``` docker-compose exec dev cpplint ../src/main.cc ```

## TESTS
- デザインパターン学習の優先度が高いため、テストコード＆テストケースの実装はしなくても良いものとする

### UNIT TEST TOOL
Google Testを使用。以下のコマンドで実行可能
``` ctest --verbose```
ex: ``` docker-compose exec dev ctest --verbose```
