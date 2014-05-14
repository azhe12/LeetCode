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
	BestTimetoBuyandSellStock



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

clean:
	rm -rf $(OBJ) *.o
