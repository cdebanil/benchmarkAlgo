#include <climits>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

#define COMPRESS 1
#define DECOMPRESS 2
#define RUNLENGTHENCODING 3
#define DICTIONARYCODING 4

using namespace std;

struct rleCharNumPair{     
    unsigned char ch;        
    unsigned long long int count; 
};

namespace rle
{
    string ex = "_rle"; 

    void compress(vector<unsigned char> &input, vector<unsigned char> &output)
    {
        vector<rleCharNumPair> arr;

        vector<unsigned char>::iterator it = input.begin();
        unsigned char character = *it;
        it++;
        unsigned long long int counter = 1;

        // Convert input to an array of pairs of unsigned char and number of occurrences 
        while (it != input.end())
        {
            if (character == *it)
            {
                counter++;
                it++;
                
            } else
            {
                rleCharNumPair chN;
                chN.ch = character;
                chN.count = counter;
                arr.push_back(chN);

                character = *it;
                counter = 1;
                it++;
            }
            if (it == input.end())
            {
                rleCharNumPair chN;
                chN.ch = character;
                chN.count = counter;
                arr.push_back(chN);
            }
        }
        
        // Push all characters and their frequencies to output buffer
        for (vector<rleCharNumPair>::iterator iter = arr.begin(); iter != arr.end(); iter++)
        {
            rleCharNumPair chN = *iter;

            // Push the character to output buffer
            output.push_back(chN.ch);

            // Convert number to null terminated string of unsigned char and push each to output buffer
            char * num = to_string(chN.count).data();
            char * x = num;
            while (1)
            {
                char y = *x;
                if (y != '\0')
                {
                    unsigned char c = static_cast<unsigned char>(y);
                    output.push_back(c);
                    x++;
                    continue;
                } else 
                {
                    unsigned char c = '\0';
                    output.push_back(c);
                    break;
                }
            }
            
            
        }
        
    }

    void deCompress(vector<unsigned char> &input, vector<unsigned char> &output)
    {
        vector<unsigned char>::iterator it = input.begin();
        while (it != input.end())
        {
            vector<unsigned char> chNPairs;
            if (*it == '\0')
            {
                chNPairs.push_back(*it);
                it++;
            }            
            while (*it != '\0')
            {
                chNPairs.push_back(*it);
                it++;
            }
            unsigned char ch = chNPairs.at(0);
            chNPairs.erase(chNPairs.begin());
            string str(chNPairs.begin(), chNPairs.end());
            unsigned long long int num = strtoull(str.c_str(), NULL, 10);
            for (unsigned long long int i = 0; i < num; i++)
            {
                output.push_back(ch);
            }
            it++;   
        }
    }
}

namespace dc
{
    string ex = "_dc"; 

    void compress(vector<unsigned char> &input, vector<unsigned char> &output)
    {
        for (vector<unsigned char>::iterator it = input.begin(); it != input.end(); it++)
        {
            output.push_back(*it);
        }
    }

    void deCompress(vector<unsigned char> &input, vector<unsigned char> &output)
    {
        for (vector<unsigned char>::iterator it = input.begin(); it != input.end(); it++)
        {
            output.push_back(*it);
        }
    }
}


int main()
{
    // int argProcess = COMPRESS;
    int argAlgorithm = RUNLENGTHENCODING;
    int argProcess = DECOMPRESS;
    // int argAlgorithm = DICTIONARYCODING;  

    string extension = "_copy";
    string inputFileName = "./testfiles/TEST";
    string outputFileName = "./testfiles/TEST";

    if (argAlgorithm == RUNLENGTHENCODING)
    {
        extension = rle::ex; 
    }
    if (argAlgorithm == DICTIONARYCODING)
    {
        extension = dc::ex;
    }
      

    int numOfTestFiles = 2;
    for (int i = 1; i <= numOfTestFiles; i++)
    {
        if (argProcess == COMPRESS)
        {
            inputFileName = "./testfiles/TEST" + to_string(i);
            outputFileName = inputFileName + extension;
        }
        if (argProcess == DECOMPRESS)
        {
            inputFileName = "./testfiles/TEST" + to_string(i) + extension;
            outputFileName = inputFileName + "_decompressed";
        }

        ifstream input( inputFileName, ios::binary );
        ofstream output( outputFileName, ios::binary ); 

        vector<unsigned char> inputDataBuffer(istreambuf_iterator<char>(input), {});
        vector<unsigned char> outputDataBuffer; 


        if (argProcess == COMPRESS)
        {
            if (argAlgorithm == RUNLENGTHENCODING)
            {
                rle::compress(inputDataBuffer, outputDataBuffer); 
            }
            if (argAlgorithm == DICTIONARYCODING)
            {
                dc::compress(inputDataBuffer, outputDataBuffer); 
            }
        }
        if (argProcess == DECOMPRESS)
        {
            if (argAlgorithm == RUNLENGTHENCODING)
            {
                rle::deCompress(inputDataBuffer, outputDataBuffer);
            }
            if (argAlgorithm == DICTIONARYCODING)
            {
                dc::deCompress(inputDataBuffer, outputDataBuffer);
            }
        }
        
        copy(outputDataBuffer.begin(), outputDataBuffer.end(), ostreambuf_iterator<char>(output));
  
    }
}