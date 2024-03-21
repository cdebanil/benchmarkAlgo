build: main.cpp
	g++ main.cpp -o main

clean: 
	rm ./main
	rm ./testfiles/TEST*_*
	rm ./testfiles/TEST*D*