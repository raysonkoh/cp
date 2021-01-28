if [ $1 == "cf" ]
then
  echo "Creating cf-contest folder for contest: $2 with $3 problems"
  mkdir codeforces/$2
  for ((i = 0; i < $3; i++))
  do
    ascii=$(($i+65))
    char=$(echo "$ascii" |  awk '{ printf("%c", $0); }')
    mkdir codeforces/$2/$char
    cp template.cc codeforces/$2/$char/m.cc
    mkdir codeforces/$2/$char/inputs
    touch codeforces/$2/$char/inputs/t.in
  done
elif [ $1 == "k" ]
then
  echo "Creating kattis folder for problem: $2"
  mkdir kattis/$2
  cp template.cc kattis/$2/m.cc
  mkdir kattis/$2/inputs
  touch kattis/$2/inputs/t.in
else
  echo "Unknown args, use \"cf [contest-number] [num-problems]\" for codeforces contest or \"k [problem-name]\" for kattis"
fi
