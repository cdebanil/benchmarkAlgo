import random 
import string 
import hashlib
import os

numberOfTestCases = 10

def printFileSizes():
    print("|  | Original File Size | After Run Length Compression | Compression Ratio (Run Length) | After LZW Compression | Compression Ratio (LZW) |")
    print("| --- | --- | --- | --- | --- | --- |")
    for x in range(1, numberOfTestCases + 1):
        original_size = os.path.getsize('./testfiles/TEST' + str(x))
        compressed_dc_size = os.path.getsize('./testfiles/TEST' + str(x) + "_dc")
        compressed_rle_size = os.path.getsize('./testfiles/TEST' + str(x) + "_rle")
        ratio_rle = round(float(original_size) / float(compressed_rle_size), 4)
        ratio_dc = round(float(original_size) / float(compressed_dc_size), 4)
        print("| TEST" + str(x) + " | " + str(original_size) + " | " + str(compressed_rle_size) + "  | " + str(ratio_rle) + "  | " + str(compressed_dc_size) + "  | " + str(ratio_dc) + "  |")

def runAlgo(algo, procedure, numTest):
    if algo == "dc" or algo == "rle":
        if procedure == "compress" or procedure == "decompress":
            os.system("./main " + algo + " " + procedure + " " + str(numTest))
            os.system("gprof ./main gmon.out > ./testfiles/analysis" + "_" + str(numTest) + "_" + algo + "_" + procedure)


def checkAlgoAccuracy(algo, lstOfTestCases): 
    if algo == "dc":
        ex = "_dc"
        print("--------------------------------------DICTIONARY CODING---------------------------------------")
    if algo == "rle":
        ex = "_rle"
        print("--------------------------------------RUN LENGTH CODING---------------------------------------")
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


# for x in range(1, numberOfTestCases + 1):
#     for algo in ["dc", "rle"]:
#         for procedure in ["compress", "decompress"]:
#             runAlgo(algo, procedure, x)

# for algo in ["dc", "rle"]:
#     checkAlgoAccuracy(algo, range(numberOfTestCases))

printFileSizes()