TEST_FILE_FIRST="TEST_FILES/test_file.txt"
TEMPLATE_NUMBER="[0-9]"
TEMPLATE_CHAR="sf"

grep -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -c ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -c ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -l ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -l ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -n ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -n ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt 
grep -i ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -i ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt 
grep -v ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -v ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

grep -is -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -is -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -io -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -io -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -io -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -io -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -ic -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -ic -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -vo -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -vo -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -so -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -so -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

grep -isl -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -isl -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -iov -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -iov -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -ioc -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -ioc -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -sic -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -sic -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -nvo -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -nvo -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
grep -iso -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > ORIGINAL.txt && ./s21_grep -iso -e ${TEMPLATE_CHAR} ${TEST_FILE_FIRST} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

rm -f ORIGINAL.txt MINE.txt