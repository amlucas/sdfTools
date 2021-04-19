#! /bin/sh

# TEST: tuto.sphere
cd tuto
rm -f exit.out.txt
./sphere.py
echo $? > exit.out.txt

# TEST: tuto.union
cd tuto
rm -f exit.out.txt
./union.py
echo $? > exit.out.txt

# TEST: tuto.three
cd tuto
rm -f exit.out.txt
./three.py
echo $? > exit.out.txt

# TEST: tuto.cheese
cd tuto
rm -f exit.out.txt
./cheese.py
echo $? > exit.out.txt
