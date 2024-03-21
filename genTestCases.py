import random 
import string

numberOfTestCases = 10

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




genTestFiles()