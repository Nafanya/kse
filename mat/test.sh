make

echo "Well-cond matrix 5x5"

./gen 5 d > input.txt
echo "Matrix:"
cat input.txt

echo -e "\n\n\n*****\nCond"
cat input.txt | ./cond

echo -e "\n\n\n*****\nGauss"
cat input.txt | ./gauss

echo -e "\n\n\n*****\nJacobi"
cat input.txt | ./jacobi

echo -e "\n\n\n*****\nRelax"
cat input.txt | ./relax

echo -e "\n\n\n*****\nZeidel"
cat input.txt | ./zeidel



echo "Hilbert matrix 5x5"

./gen 5 g > input.txt
echo "Matrix:"
cat input.txt

echo -e "\n\n\n*****\nCond"
cat input.txt | ./cond

echo -e "\n\n\n*****\nGauss"
cat input.txt | ./gauss

echo -e "\n\n\n*****\nRelax"
cat input.txt | ./relax

echo -e "\n\n\n*****\nZeidel"
cat input.txt | ./zeidel



echo -e "\n\n\nSmall 2x2 matrix"
./gen 2 g > jacobi.in
echo "Matrix:"
cat jacobi.in

echo -e "\n\n\n*****\nJacobi"
cat jacobi.in | ./jacobi
