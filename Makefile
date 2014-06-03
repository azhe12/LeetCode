OBJ:=	\
	RemoveDuplicatesFromSortedArray 	\
	RemoveElement LengthOfLastWord 		\
	PlusOne 							\
	RemoveDuplicatesFromSortedList 		\
	SameTree 							\
	SymmetricTree 						\
	MaximumDepthOfBinaryTree 			\
	BalancedBinaryTree 					\
	MinimumDepthOfBinaryTree 			\
	PathSum 							\
	TwoSum 								\
	ReverseInteger 						\
	StringToInteger 					\
	PalindromeNumber 					\
	RomanToInteger						\
	LongestCommonPrefix					\
	ValidParentheses					\
	MergeTwoSortedLists					\
	SwapNodesinPairs					\
	SearchInsertPosition				\
	RemoveNthNodeFromEndofList			\
	ValidSudoku							\
	CountandSay							\
	UniquePaths							\
	ClimbingStairs						\
	RemoveDuplicatesfromSortedArrayII	\
	MergeSortedArray					\
	PascalsTriangleII					\
	BestTimetoBuyandSellStock			\
	ValidPalindrome						\
	AddTwoNumbers						\
	IntegertoRoman						\
	3Sum								\
	3SumClosest							\
	LetterCombinationsofaPhoneNumber	\
	GenerateParentheses					\
	4Sum								\
	MergekSortedLists					\
	Permutations						\
	PermutationsII						\
	Anagrams							\
	Pow									\
	MaximumSubarray						\
	JumpGame							\
	JumpGameII							\
	SpiralMatrix						\
	SpiralMatrixII						\
	RotateList							\
	UniquePathsII						\
	MinimumPathSum						\
	SetMatrixZeroes						\
	Subsets								\
	SubsetsII							\
	WordSearch



.PHONY:clean
CC:=g++
CPPFLAGS:='-g'

RemoveDuplicatesFromSortedArray:RemoveDuplicatesFromSortedArray.cpp

RemoveElement:RemoveElement.cpp

LengthOfLastWord:LengthOfLastWord.cpp

PlusOne:PlusOne.cpp

RemoveDuplicatesFromSortedList:RemoveDuplicatesFromSortedList.cpp

SameTree:SameTree.cpp

SymmetricTree:SymmetricTree.cpp

MaximumDepthOfBinaryTree:MaximumDepthOfBinaryTree.cpp

BalancedBinaryTree:BalancedBinaryTree.cpp

MinimumDepthOfBinaryTree:MinimumDepthOfBinaryTree.cpp

PathSum:PathSum.cpp

TwoSum:TwoSum.cpp

ReverseInteger:ReverseInteger.cpp

StringToInteger:StringToInteger.cpp

PalindromeNumber:PalindromeNumber.cpp

RomanToInteger:RomanToInteger.cpp

LongestCommonPrefix:LongestCommonPrefix.cpp

ValidParentheses:ValidParentheses.cpp

MergeTwoSortedLists:MergeTwoSortedLists.cpp

SwapNodesinPairs:SwapNodesinPairs.cpp

SearchInsertPosition:SearchInsertPosition.cpp

RemoveNthNodeFromEndofList:RemoveNthNodeFromEndofList.cpp

ValidSudoku:ValidSudoku.cpp

CountandSay:CountandSay.cpp

UniquePaths:UniquePaths.cpp

ClimbingStairs:ClimbingStairs.cpp

MergeSortedArray:MergeSortedArray.cpp

PascalsTriangleII:PascalsTriangleII.cpp

RemoveDuplicatesfromSortedArrayII:RemoveDuplicatesfromSortedArrayII.cpp

BestTimetoBuyandSellStock:BestTimetoBuyandSellStock.cpp

ValidPalindrome:ValidPalindrome.cpp

AddTwoNumbers:AddTwoNumbers.cpp

IntegertoRoman:IntegertoRoman.cpp

3Sum:3Sum.cpp

3SumClosest:3SumClosest.cpp

LetterCombinationsofaPhoneNumber:LetterCombinationsofaPhoneNumber.cpp

MergekSortedLists:MergekSortedLists.cpp

Permutations:Permutations.cpp

PermutationsII:PermutationsII.cpp

Anagrams:Anagrams.cpp

Pow:Pow.cpp

MaximumSubarray:MaximumSubarray.cpp

JumpGame:JumpGame.cpp

JumpGameII:JumpGameII.cpp

SpiralMatrix:SpiralMatrix.cpp

SpiralMatrixII:SpiralMatrixII.cpp

RotateList:RotateList.cpp

UniquePathsII:UniquePathsII.cpp

MinimumPathSum:MinimumPathSum.cpp

SetMatrixZeroes:SetMatrixZeroes.cpp

Subsets:Subsets.cpp

SubsetsII:SubsetsII.cpp

WordSearch:WordSearch.cpp

clean:
	rm -rf $(OBJ) *.o
