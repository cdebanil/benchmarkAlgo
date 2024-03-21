import random 
import string 
import hashlib
import os

numberOfTestCases = 10

def runAlgo(algo, procedure, numTest):
    if algo == "dc" or algo == "rle":
        if procedure == "compress" or procedure == "decompress":
            os.system("./main " + algo + " " + procedure + " " + str(numTest))
            os.system("gprof ./main gmon.out > ./testfiles/analysis" + "_" + str(numTest) + "_" + algo + "_" + procedure)


def genTestFiles():
    for x in range(numberOfTestCases):
        sizeinbytes = random.randint(1024 * 1024 * 8, 1024 * 1024 * 16) # All test files are between 8MB and 16MB
        file = open("./testfiles/TEST" + str(x+1), "w")
        while sizeinbytes > 0 :
            ch = random.choice(string.printable)
            max = 20
            if ch in string.whitespace:
                max = 2
            for k in range(random.randint(1, max)):
                file.write(ch)
                sizeinbytes = sizeinbytes - 1
        file.close()


def checkAlgoAccuracy(algo, lstOfTestCases): 
    if algo == "dc":
        ex = "_dc"
        print("--------------------------------------DICTIONARY CODING--------------------------------------")
    if algo == "rle":
        ex = "_rle"
        print("--------------------------------------RUN LENGTH CODING--------------------------------------")
    print("-------MD5 Checksum before running and after running program to compress and decompress-------")
    print("----------------------------------------------------------------------------------------------")
    print("  Test Case  |" + "              Before              |" + " Match " + "|               After             ")
    print("----------------------------------------------------------------------------------------------")
    for x in lstOfTestCases:
        fileOriginal = open("./testfiles/TEST" + str(x+1), mode="rb")
        fileProcessed = open("./testfiles/TEST" + str(x+1) + ex + "_decompressed", mode="rb")
        dataOriginal = fileOriginal.read()
        dataProcessed = fileProcessed.read()

        hashOriginal = hashlib.md5(dataOriginal).hexdigest()
        hashProcessed = hashlib.md5(dataProcessed).hexdigest()

        st = "    N    "
        if hashOriginal == hashProcessed:
            st = "   Y   "

        if x > 8:
            print("Test Case " + str(x+1) + " | " + hashOriginal + " |" + st +  "| "+ hashProcessed)
        else:
            print("Test Case  " + str(x+1) + " | " + hashOriginal + " |" + st +  "| "+ hashProcessed)


        fileOriginal.close()
        fileProcessed.close()

#genTestFiles()


for x in range(numberOfTestCases):
    for algo in ["dc", "rle"]:
        for procedure in ["compress", "decompress"]:
            runAlgo(algo, procedure, x)

for algo in ["dc", "rle"]:
    checkAlgoAccuracy(algo, range(numberOfTestCases))



