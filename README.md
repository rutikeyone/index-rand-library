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

### The main methods of the library look like this.

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/2.png)

## Connection the library

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/3.png)

## Using

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/4.png)

## Checking values

### Python

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/5.png)

### C++ 

![alt text](https://github.com/RuTiKeyOne/IndexRandLibrary/blob/master/doc/Screenshots/6.png)
