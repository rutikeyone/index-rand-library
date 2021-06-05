#include "IndexRand.h"
#include <iostream>
#include "pch.h"

namespace IndexRandLibrary {

    double IndexRand::GetIndexRand(std::vector<int> clusters, std::vector<int> classes) {
        double IndexRand = 0;
        int tp_plus_fp = Sum(Comb(Bincount(clusters), 2));
        int tp_plus_fn = Sum(Comb(Bincount(classes), 2));

        std::vector<std::vector<int>> A = C_(clusters, classes);
        int tp = GetTp(clusters, A);
        int fp = tp_plus_fp - tp;
        int fn = tp_plus_fn - tp;

        int tn = Comb(A.size(), 2) - tp - fp - fn;

        IndexRand = (double)(tp + tn) / (tp + fp + fn + tn);
        return IndexRand;
    }

    std::vector<int> IndexRand::Bincount(std::vector<int> clusters) {
        std::vector<int> IntermediateClusters = clusters;
        int CountIterationNumbers;
        std::vector<int> Result;
        for (int elem : IntermediateClusters) {
            CountIterationNumbers = count(cbegin(IntermediateClusters), cend(IntermediateClusters), elem);
            Result.push_back(CountIterationNumbers);
            IntermediateClusters.erase(remove(IntermediateClusters.begin(), IntermediateClusters.end(), elem), IntermediateClusters.end());
        }

        Result.erase(remove(Result.begin(), Result.end(), 0), Result.end());
        if (clusters[0] == clusters[1]) {
            Result.push_back(0);
        }

        return Result;
    };

    std::vector<int> IndexRand::Comb(std::vector<int> currentClusters, int number) {
        std::vector<int> Result;
        for (auto elem : currentClusters) {
            if ((GetFactorial(number) * GetFactorial(elem - number)) == 0) {
                Result.push_back(0);
            }
            else {
                Result.push_back(GetFactorial(elem) / (GetFactorial(number) * GetFactorial(elem - number)));
            }
        }
        return Result;
    };

    int IndexRand::Comb(int n, int k) {
        return GetFactorial(n) / (GetFactorial(k) * GetFactorial((n - k)));
    }

    int IndexRand::Sum(std::vector<int> currentVector) {
        int Result = 0;
        for (int i = 0; i < currentVector.size(); i++) {
            Result += currentVector[i];
        }
        return Result;
    }

    std::vector<std::vector<int>> IndexRand::C_(std::vector<int> clusters, std::vector<int> classes) {
        std::vector<std::vector<int>> Result;
        for (int i = 0; i < clusters.size(); i++) {
            Result.push_back(std::vector<int> {clusters[i], classes[i]});
        }
        return Result;
    }

#pragma region Methods Get Tp

    int IndexRand::GetTp(std::vector<int> clusters, std::vector<std::vector<int>> a) {
        std::vector<int> FirstElements;
        std::vector<std::vector<bool>> IsSameValueFirstElements;
        std::vector<bool> IntermediateIsSameValueFirstElements;
        std::set<int> SetClusters = GetSetClusters(clusters);
        std::vector<bool> IndermediateIsSameValueFirstElements;
        std::vector<std::vector<int>> IterationVectors;
        std::vector<int> IntermediateIterationVectors;
        std::vector<std::vector<int>> BinCountVectors;
        std::vector<std::vector<int>> CombVectors;
        int Result = 0;

        PushFirstElements(FirstElements, a);
        PushIsSameValueFirstElements(SetClusters, IndermediateIsSameValueFirstElements, FirstElements, IsSameValueFirstElements);
        PushIterationsVectors(IsSameValueFirstElements, IntermediateIterationVectors, IterationVectors, a);
        PushBinCountVectors(IterationVectors, BinCountVectors);
        PushCombVectors(CombVectors, BinCountVectors);
        GetResult(CombVectors, Result);

        return Result;
    }

    void IndexRand::PushFirstElements(std::vector<int>& firstElements, std::vector<std::vector<int>> a) {
        for (std::vector<int> elem : a) {
            for (int i = 0; i < 1; i++) {
                firstElements.push_back(elem[0]);
            }
        }
    }

    void IndexRand::PushIsSameValueFirstElements(std::set<int> setClusters, std::vector<bool> indermediateIsSameValueFirstElements,
        std::vector<int> firstElements, std::vector<std::vector<bool>>& isSameValueFirstElements) {
        for (auto elem : setClusters) {
            indermediateIsSameValueFirstElements = {};
            for (auto number : firstElements) {
                indermediateIsSameValueFirstElements.push_back(elem == number);
            }
            isSameValueFirstElements.push_back(indermediateIsSameValueFirstElements);
        }
    }

    void IndexRand::PushIterationsVectors(std::vector<std::vector<bool>> isSameValueFirstElements, std::vector<int> intermediateIterationVectors,
        std::vector<std::vector<int>>& iterationVectors, std::vector<std::vector<int>> a) {
        for (std::vector<bool> equality : isSameValueFirstElements) {

            intermediateIterationVectors = {};
            for (int i = 0; i < a.size(); i++) {
                if (equality[i]) {
                    intermediateIterationVectors.push_back(a[i].back());
                }
            }
            iterationVectors.push_back(intermediateIterationVectors);
        }
    }

    void IndexRand::PushBinCountVectors(std::vector<std::vector<int>> iterationVectors, std::vector<std::vector<int>>& binCountVector) {
        for (auto elem : iterationVectors) {
            binCountVector.push_back(Bincount(elem));
        }
    }

    void IndexRand::PushCombVectors(std::vector<std::vector<int>>& combVectors, std::vector<std::vector<int>> binCountVectors) {
        for (std::vector<int> elem : binCountVectors) {
            combVectors.push_back(Comb(elem, 2));
        }
    }

    void IndexRand::GetResult(std::vector < std::vector<int>> combVectors, int& result) {
        for (auto elem : combVectors) {
            for (int number : elem) {
                result += number;
            }
        }
    }


    std::set<int> IndexRand::GetSetClusters(std::vector<int> clusters) {
        std::set<int> Result;
        for (auto elem : clusters) {
            Result.insert(elem);
        }
        return Result;
    }

    long double IndexRand::GetFactorial(int N)
    {
        if (N < 0)
            return 0;
        if (N == 0)
            return 1;
        else
            return N * GetFactorial(N - 1);
    }

};