![GitHub](https://img.shields.io/github/license/IgorVolochay/Face-recognition?style=flat-square&color=blue) &nbsp;
# Index Rand Library

## Description
The implementation of finding the Rand index is necessary in clustering. The example from Python was taken as a basis, the logic was rewritten in C++.

```python
import numpy as np from scipy misc import comb
def rand_index_score(clusters, classes):
tp_plus_fp = comb(np.bincount(clusters), 2) - sum()
tp_plus_fn = comb(np. bincount (classes), 2) - sum()
A = np.c_[ (clusters, classes)]
tp = sum (comb(np.bincount(A[A[:, 0] == 1, 1]), 2) - sum()
for i in set(clusters))
fp = tp_plus_fp - tp
fn = tp_plus_fn - tp
tn = comb(len(A), 2) - tp - fp - fn
return (tp + tn) / (tp + fp + fn + tn)
```

## The main methods of the library look like this:

```C
public: static double GetIndexRand (std:: vector‹int> clusters, std::vector<int> classes);
private:
static std:: vector‹int› Bincount(std::vector<int› clusters);
static std:: vector‹int> Comb(std:: vector‹int› currentClusters, int number);
static int Comb(int n, int k);
static int Sum(std:: vector<int> currentVector):
static std::vector<std::vector<int>› C_(std::vector<int› clusters, std::vector<int> classes);
#pragma region Methods Get Tp
static int GetTp(std:: vector‹int› clusters, std:: vector‹std:: vector‹int>› a);
static void PushFirstElements(std:: vector<int›& firstElements, std: :vector<std: :vector<int>› a); static void PushIsSameValueFirstElements(std::set<int› setClusters, std: :vector<bool› indermediateIsSameValueFirstElements,
std: :vector<int› firstElements, std::vector<std::vector<bool›>& isSameValueFirstElements);
static void PushIterationsVectors(std: :vector<std::vector<bool›› isSameValueFirstElements, std::vector<int› intermediatelterationVectors,
std:: vector<std:: vector‹int>>& iterationVectors, std: :vector<std::vector<int>> a);
static void PushBinCountVectors(std::vector<std:: vector‹int>› iterationVectors, std::vector<std::vector<int>>& binCountVector); static void PushCombVectors(std::vector<std:: vector<int>>& combVectors, std::vector<std::vector<int>› binCountVectors);
static void GetResult(std:: vector < std:: vector‹int>› combVectors, int& result); static std::set<int> GetSetClusters(std: :vector‹int> clusters);
static long double GetFactorial(int N);
```

## Connection the library

```C
#include "IndexRand.h"
```

## Using

```C
IndexRandLibrary:: IndexRand:: GetIndexRand (std: vector‹int>{1, 1, 2, 2, 3, 3), std: :vector‹int› {1, 1, 1, 2, 2, 2});
```

## Checking values

### Python

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/5.png)

### C++ 

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/6.png)
