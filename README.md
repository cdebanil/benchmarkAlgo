# README.md

This program uses run length encoding  and dictionary coding (i.e LZW algorithm) on 10 different custom test cases to benchmark (de)compression (with gprof)

# Instructions

To build, run

```bash
make
```

To run program on test files, run

```bash
python tests.py
```

If we run above code on the provided test cases we get output -

```
--------------------------------------DICTIONARY CODING---------------------------------------
-------MD5 Checksum before running and after running program to compress and decompress-------
----------------------------------------------------------------------------------------------
  Test Case  |              Before              | Match |               After             
----------------------------------------------------------------------------------------------
Test Case  1 | 0efea1b0e6a48d69885ea43544fba07b |   Y   | 0efea1b0e6a48d69885ea43544fba07b
Test Case  2 | 4872db41b480f6b3e17971acb6f01bc2 |   Y   | 4872db41b480f6b3e17971acb6f01bc2
Test Case  3 | 90dc86738db19c6c7ab185a4c812b88c |   Y   | 90dc86738db19c6c7ab185a4c812b88c
Test Case  4 | 2d50995cd741c8593b5c157c768aab02 |   Y   | 2d50995cd741c8593b5c157c768aab02
Test Case  5 | 5e5f0031edb099fe2348490bd39f054b |   Y   | 5e5f0031edb099fe2348490bd39f054b
Test Case  6 | 1eac40dea123292931a74cb60c98fb50 |   Y   | 1eac40dea123292931a74cb60c98fb50
Test Case  7 | 0b38d6313f9d7476104029ca0d5f7194 |   Y   | 0b38d6313f9d7476104029ca0d5f7194
Test Case  8 | 65b969b696827a66a70421177b96a6d7 |   Y   | 65b969b696827a66a70421177b96a6d7
Test Case  9 | 931d6a2c61ac6272a975bb8b40d3b020 |   Y   | 931d6a2c61ac6272a975bb8b40d3b020
Test Case 10 | 0687801f223a0d18e7701d9bf5ecdfb7 |   Y   | 0687801f223a0d18e7701d9bf5ecdfb7


--------------------------------------RUN LENGTH CODING---------------------------------------
-------MD5 Checksum before running and after running program to compress and decompress-------
----------------------------------------------------------------------------------------------
  Test Case  |              Before              | Match |               After             
----------------------------------------------------------------------------------------------
Test Case  1 | 0efea1b0e6a48d69885ea43544fba07b |   Y   | 0efea1b0e6a48d69885ea43544fba07b
Test Case  2 | 4872db41b480f6b3e17971acb6f01bc2 |   Y   | 4872db41b480f6b3e17971acb6f01bc2
Test Case  3 | 90dc86738db19c6c7ab185a4c812b88c |   Y   | 90dc86738db19c6c7ab185a4c812b88c
Test Case  4 | 2d50995cd741c8593b5c157c768aab02 |   Y   | 2d50995cd741c8593b5c157c768aab02
Test Case  5 | 5e5f0031edb099fe2348490bd39f054b |   Y   | 5e5f0031edb099fe2348490bd39f054b
Test Case  6 | 1eac40dea123292931a74cb60c98fb50 |   Y   | 1eac40dea123292931a74cb60c98fb50
Test Case  7 | 0b38d6313f9d7476104029ca0d5f7194 |   Y   | 0b38d6313f9d7476104029ca0d5f7194
Test Case  8 | 65b969b696827a66a70421177b96a6d7 |   Y   | 65b969b696827a66a70421177b96a6d7
Test Case  9 | 931d6a2c61ac6272a975bb8b40d3b020 |   Y   | 931d6a2c61ac6272a975bb8b40d3b020
Test Case 10 | 0687801f223a0d18e7701d9bf5ecdfb7 |   Y   | 0687801f223a0d18e7701d9bf5ecdfb7





 Test File - TEST1-
Original File Size (Bytes) = 9519822
After Run Length Compression Size (Bytes) = 3333291
Compression Ratio (Run Length) = 2.856
After LZW Compression Size (Bytes) = 5241514
Compression Ratio (LZW) = 1.8162


 Test File - TEST2-
Original File Size (Bytes) = 15184789
After Run Length Compression Size (Bytes) = 5310007
Compression Ratio (Run Length) = 2.8597
After LZW Compression Size (Bytes) = 8319646
Compression Ratio (LZW) = 1.8252


 Test File - TEST3-
Original File Size (Bytes) = 12446824
After Run Length Compression Size (Bytes) = 4355399
Compression Ratio (Run Length) = 2.8578
After LZW Compression Size (Bytes) = 6819612
Compression Ratio (LZW) = 1.8252


 Test File - TEST4-
Original File Size (Bytes) = 10442494
After Run Length Compression Size (Bytes) = 3654166
Compression Ratio (Run Length) = 2.8577
After LZW Compression Size (Bytes) = 5744642
Compression Ratio (LZW) = 1.8178


 Test File - TEST5-
Original File Size (Bytes) = 16151064
After Run Length Compression Size (Bytes) = 5652116
Compression Ratio (Run Length) = 2.8575
After LZW Compression Size (Bytes) = 8850034
Compression Ratio (LZW) = 1.825


 Test File - TEST6-
Original File Size (Bytes) = 11810890
After Run Length Compression Size (Bytes) = 4131546
Compression Ratio (Run Length) = 2.8587
After LZW Compression Size (Bytes) = 6482814
Compression Ratio (LZW) = 1.8219


 Test File - TEST7-
Original File Size (Bytes) = 12183678
After Run Length Compression Size (Bytes) = 4262278
Compression Ratio (Run Length) = 2.8585
After LZW Compression Size (Bytes) = 6679243
Compression Ratio (LZW) = 1.8241


 Test File - TEST8-
Original File Size (Bytes) = 9039476
After Run Length Compression Size (Bytes) = 3160220
Compression Ratio (Run Length) = 2.8604
After LZW Compression Size (Bytes) = 4966911
Compression Ratio (LZW) = 1.8199


 Test File - TEST9-
Original File Size (Bytes) = 15027049
After Run Length Compression Size (Bytes) = 5258343
Compression Ratio (Run Length) = 2.8578
After LZW Compression Size (Bytes) = 8233451
Compression Ratio (LZW) = 1.8251


 Test File - TEST10-
Original File Size (Bytes) = 13047039
After Run Length Compression Size (Bytes) = 4566664
Compression Ratio (Run Length) = 2.857
After LZW Compression Size (Bytes) = 7151443
Compression Ratio (LZW) = 1.8244
```

**If desired, new test cases can be generated by running `python genTestCases.py`**


To clean, run 

```bash
make clean
```

# Benchmarking

The python script `tests.py` also runs gprof and whose output is stored in files with names having the name - `analysis_{testcasenumber}_{algorithm used}_{compression or decomression}`. Suppose we want to view the analysis of run length compression on test case 5. We can view it by -

```bash
cat ./testfiles/analysis_5_rle_compress
```

# Compression Ratios (File Sizes in bytes)
Here Compression Ration = (Uncompressed size / Compressed Size)
|  | Original File Size | After Run Length Compression | Compression Ratio (Run Length) | After LZW Compression | Compression Ratio (LZW) |
| --- | --- | --- | --- | --- | --- |
| TEST1 | 9519822 | 3333291  | 2.856  | 5241514  | 1.8162  |
| TEST2 | 15184789 | 5310007  | 2.8597  | 8319646  | 1.8252  |
| TEST3 | 12446824 | 4355399  | 2.8578  | 6819612  | 1.8252  |
| TEST4 | 10442494 | 3654166  | 2.8577  | 5744642  | 1.8178  |
| TEST5 | 16151064 | 5652116  | 2.8575  | 8850034  | 1.825  |
| TEST6 | 11810890 | 4131546  | 2.8587  | 6482814  | 1.8219  |
| TEST7 | 12183678 | 4262278  | 2.8585  | 6679243  | 1.8241  |
| TEST8 | 9039476 | 3160220  | 2.8604  | 4966911  | 1.8199  |
| TEST9 | 15027049 | 5258343  | 2.8578  | 8233451  | 1.8251  |
| TEST10 | 13047039 | 4566664  | 2.857  | 7151443  | 1.8244  |

# Runtime in seconds

|  | Run Length Compression | Run Length Decompression | LZW Compression | LZW Decompression |
| --- | --- | --- | --- | --- |
| TEST1 | 0.99 | 0.74 | 18.60 | 2.45 |
| TEST2 | 1.40 | 1.19 | 31.39 | 4.41 |
| TEST3 | 1.21 | 0.84 | 24.61 | 3.26 |
| TEST4 | 0.94 | 0.80 | 22.90 | 2.71 |
| TEST5 | 1.49 | 1.10 | 33.47 | 4.12 |
| TEST6 | 1.12 | 0.90 | 24.16 | 3.29 |
| TEST7 | 1.27 | 0.86 | 25.04 | 3.00 |
| TEST8 | 0.91 | 0.69 | 18.27 | 2.47 |
| TEST9 | 1.10 | 1.21 | 29.64 | 3.81 |
| TEST10 | 1.25 | 0.84 | 26.61 | 3.50 |

# Advantages and Disadvantages

Both of these algorithms are primarily useful in cases where we have repeating patterns. Outside of such cases, we may not achieve significant compression ratios

## Run Length

- Primarily useful where we have long sequences of repeating data.
- Hence can be used to achieve high compression in cases like image compression, etc, For example, lets say we have long sequences of image area with same color, then we can represent it with the byte which represents the pixel and an integer for how many time the pixel repeats.
- However, if we do not have long sequences of repeating data then it is not as useful. Even if data is very frequent, if it is not repeated in contiguous blocks of memory, we will not achieve significant compression.

## Dictionary Coding

- Primarily useful where we have a preexisting “dictionary” i.e. a database of repeating data segments of high frequency with associated codewords
- Not as useful when we don’t have a preexisting dictionary.
- In current implementation i.e. LZW coding (which is a subtype of dictionary coding), we use an algorithm which improves the dictionary during runtime.
- There may be a memory or performance overhead due to dictionary storage and dictionary lookup operations. This can slow down the algorithm.
