build: main.cpp
	g++ -pg main.cpp -o main

clean: 
	rm ./main
	rm ./gmon.out
	rm ./testfiles/TEST*_*
	rm ./testfiles/TEST*D*
	rm ./testfiles/analysis*