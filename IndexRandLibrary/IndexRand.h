#pragma once
#include <vector>
#include <set>

namespace IndexRandLibrary {

	class IndexRand {

	public: static double GetIndexRand(std::vector<int> clusters, std::vector<int> classes);

	private:
		static std::vector<int> Bincount(std::vector<int> clusters);
		static std::vector<int> Comb(std::vector<int> currentClusters, int number);
		static int Comb(int n, int k);
		static int Sum(std::vector<int> currentVector);
		static std::vector<std::vector<int>> C_(std::vector<int> clusters, std::vector<int> classes);

	#pragma region Methods Get Tp

		static int GetTp(std::vector<int> clusters, std::vector<std::vector<int>> a);
		static void PushFirstElements(std::vector<int>& firstElements, std::vector<std::vector<int>> a);
		static void PushIsSameValueFirstElements(std::set<int> setClusters, std::vector<bool> indermediateIsSameValueFirstElements,
			std::vector<int> firstElements, std::vector<std::vector<bool>>& isSameValueFirstElements);
		static void PushIterationsVectors(std::vector<std::vector<bool>> isSameValueFirstElements, std::vector<int> intermediateIterationVectors,
			std::vector<std::vector<int>>& iterationVectors, std::vector<std::vector<int>> a);
		static void PushBinCountVectors(std::vector<std::vector<int>> iterationVectors, std::vector<std::vector<int>>& binCountVector);
		static void PushCombVectors(std::vector<std::vector<int>>& combVectors, std::vector<std::vector<int>> binCountVectors);
		static void GetResult(std::vector < std::vector<int>> combVectors, int& result);
		static std::set<int> GetSetClusters(std::vector<int> clusters);
		static long double GetFactorial(int N);
	
	#pragma endregion

	};

}