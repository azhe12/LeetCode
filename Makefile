OBJ:=	\
	RemoveDuplicatesFromSortedArray \
	RemoveElement LengthOfLastWord \
	PlusOne \
	RemoveDuplicatesFromSortedList \
	SameTree \
	SymmetricTree \
	MaximumDepthOfBinaryTree \
	BalancedBinaryTree


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

clean:
	rm -rf $(OBJ) *.o
