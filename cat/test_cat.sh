TEST_FILE="TEST_FILES/test_file.txt"

cat -b ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -b ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -s ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -s ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -e ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -e ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -n ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -n ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -t ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -t ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -v ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -v ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

cat -be ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -be ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -bn ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -bn ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -bs ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -bs ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -et ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -et ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -en ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -en ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -es ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -es ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -ts ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -ts ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -tv ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -tv ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -tn ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -tn ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -be ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -be ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -en ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -en ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

cat -tse ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -tse ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -tvn ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -tvn ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -tns ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -tns ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -bet ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -bet ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -env ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -env ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

cat -vtse ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -vtse ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -sven ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -sven ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -nves ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -nves ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -bsen ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -bsen ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -esvn ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -esvn ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt

cat -vtsne ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -vtsne ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -stveb ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -stveb ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -bntes ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -bntes ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -snvet ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -snvet ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt
cat -ebnts ${TEST_FILE} > ORIGINAL.txt && ./s21_cat -ebnts ${TEST_FILE} > MINE.txt && diff -s ORIGINAL.txt MINE.txt


rm -f ORIGINAL.txt MINE.txt