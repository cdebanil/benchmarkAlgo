#include <cstring>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#define COMPRESS 1
#define DECOMPRESS 2
#define RUNLENGTHENCODING 3
#define DICTIONARYCODING 4

using namespace std;

struct rleCharNumPair
{
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
            }
            else
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
            char *num = to_string(chN.count).data();
            char *x = num;
            while (1)
            {
                if (*x != '\0')
                {
                    output.push_back(static_cast<unsigned char>(*x));
                    x++;
                    continue;
                }
                else
                {
                    output.push_back('\0');
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

    typedef std::basic_string<unsigned char> ustring;

    vector<unsigned long long int> getInputIntegers(vector<unsigned char> &input){
        vector<unsigned long long int> result;
        vector<unsigned char>::iterator it = input.begin();
        while (it != input.end())
        {
            vector<unsigned char> number;
            while (*it != '\0' && it != input.end())
            {
                number.push_back(*it);
                it++;
            }
            string str(number.begin(), number.end());
            result.push_back(strtoull(str.c_str(), NULL, 10));
            it++;
        }
        return result;
    }

    void printIntegersToOutput(vector<unsigned char> &output, vector<unsigned long long int> intList){
            for (unsigned long long int i = 0; i < intList.size(); i++)
            {
                char *num = to_string(intList.at(i)).data();
                char *x = num;
                while (1)
                {
                    if (*x != '\0')
                    {
                        output.push_back(static_cast<unsigned char>(*x));
                        x++;
                        continue;
                    }
                    else
                    {
                        output.push_back('\0');
                        break;
                    }
                }
            }
    }

    map<ustring,unsigned long long int> constructCompressTable(vector<unsigned char> dict){
        map<ustring,unsigned long long int> table;
        for (unsigned long long i = 0; i < dict.size(); i++)
        {
            ustring str;
            str.push_back(dict.at(i));
            table.insert(pair<ustring, unsigned long long int> (str, i));
        }
        return table;
    }

    map<unsigned long long int, ustring> constructDecompressTable(vector<unsigned char> dict){
        map<unsigned long long int, ustring> table;
        for (unsigned long long i = 0; i < dict.size(); i++)
        {
            ustring str;
            str.push_back(dict.at(i));
            table.insert(pair<unsigned long long int, ustring> (i, str));
        }
        return table;
    }

    void compress(vector<unsigned char> &input, vector<unsigned char> &output, vector<unsigned char> table)
    {
        map<ustring,unsigned long long int> dict = constructCompressTable(table);
        ustring inputString;
        for (unsigned long long int i = 0; i < input.size(); i++)
        {
            inputString.push_back(input.at(i));
        }
        
        vector<unsigned long long int> outputINTS;

        // Input String =  inputString, Output Array = outputINTS, map = dict
        ustring p, c;
        p += inputString[0];
        for (int i = 0; i < inputString.length(); i++) {
            if (i != inputString.length() - 1) { c += inputString[i + 1]; }
            ustring m = p;
            m.append(c);
            if (dict.find(m) != dict.end()) {
                p = m;
            }
            else {
                outputINTS.push_back(dict[p]);
                dict.insert(pair<ustring, unsigned long long int> (m, dict.size()));
                p = c;
            }
            c.clear();
        }
        outputINTS.push_back(dict[p]);

        // ///////////////////////////////////
        printIntegersToOutput(output, outputINTS);
    }

    void deCompress(vector<unsigned char> &input, vector<unsigned char> &output, vector<unsigned char> table)
    {
        map<unsigned long long int, ustring> dict = constructDecompressTable(table);
        vector<unsigned long long int> inputINTS = getInputIntegers(input);
        ustring outputString;

        // Input Array =  inputINTS, Output String = outputString, map = dict

        unsigned long long int old = inputINTS[0], n;
        ustring s = dict[old];
        ustring c;
        c.push_back(s[0]);
        outputString.append(s);
        for (int i = 0; i < inputINTS.size() - 1; i++) {
            n = inputINTS[i + 1];
            if (dict.find(n) == dict.end()) {
                s = dict[old];
                s.append(c);
            }
            else {
                s = dict[n];
            }
            outputString.append(s);
            c.clear();
            c.push_back(s[0]);
            ustring str = dict[old];
            str.append(c);
            dict.insert(pair<unsigned long long int, ustring> (dict.size(), str));
            old = n;
        }

        // ////////////////////////////////////
        for (unsigned long long i = 0; i < outputString.size(); i++)
        {
            output.push_back(outputString.at(i));
        }
    }
}

int main( int argc, char *argv[] )
{
    int argProcess = COMPRESS;
    int argAlgorithm = RUNLENGTHENCODING;
    //int argProcess = DECOMPRESS;
    //int argAlgorithm = DICTIONARYCODING;

    if (strcmp( argv[1], "dc" ) == 0)
    {
        argAlgorithm = DICTIONARYCODING;
    }
    if (strcmp( argv[1], "rle" ) == 0)
    {
        argAlgorithm = DICTIONARYCODING;
    }
    if (strcmp( argv[2], "compress" ) == 0)
    {
        argProcess = COMPRESS;
    }
    if (strcmp( argv[2], "decompress" ) == 0)
    {
        argProcess = DECOMPRESS;
    }
    argv[3];
    int numOfTestFiles = strtol(argv[3], NULL, 10);

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

    for (int i = 0; i <= numOfTestFiles; i++)
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

        ifstream input(inputFileName, ios::binary);
        ofstream output(outputFileName, ios::binary);

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
                vector<unsigned char> dict = inputDataBuffer;
                sort(dict.begin(), dict.end());
                auto dictIT = unique(dict.begin(), dict.end());
                dict.erase(dictIT, dict.end());
                string outputDictName = "./testfiles/TEST" + to_string(i) + "DICT";
                ofstream outputDict(outputDictName, ios::binary);
                copy(dict.begin(), dict.end(), ostreambuf_iterator<char>(outputDict));

                dc::compress(inputDataBuffer, outputDataBuffer, dict);
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
                string inputDictName = "./testfiles/TEST" + to_string(i) + "DICT";
                ifstream inputDict(inputDictName, ios::binary);
                vector<unsigned char> dict(istreambuf_iterator<char>(inputDict), {});

                dc::deCompress(inputDataBuffer, outputDataBuffer, dict);
            }
        }

        copy(outputDataBuffer.begin(), outputDataBuffer.end(), ostreambuf_iterator<char>(output));
    }
}
