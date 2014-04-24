OBJ:=	\
	RemoveDuplicatesFromSortedArray \
	RemoveElement LengthOfLastWord \
	PlusOne \
	RemoveDuplicatesFromSortedList \
	SameTree \
	SymmetricTree \
	MaximumDepthOfBinaryTree \
	BalancedBinaryTree \
	MinimumDepthOfBinaryTree \
	PathSum \
	TwoSum \
	ReverseInteger \
	StringToInteger \
	PalindromeNumber \
	RomanToInteger	\
	LongestCommonPrefix	\
	ValidParentheses



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

clean:
	rm -rf $(OBJ) *.o
