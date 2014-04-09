OBJ:=	\
	RemoveDuplicatesFromSortedArray \
	RemoveElement LengthOfLastWord \
	PlusOne \
	RemoveDuplicatesFromSortedList \
	SameTree


.PHONY:clean
CC:=g++
CPPFLAGS:='-g'

RemoveDuplicatesFromSortedArray:RemoveDuplicatesFromSortedArray.cpp

RemoveElement:RemoveElement.cpp

LengthOfLastWord:LengthOfLastWord.cpp

PlusOne:PlusOne.cpp

RemoveDuplicatesFromSortedList:RemoveDuplicatesFromSortedList.cpp

SameTree:SameTree.cpp

clean:
	rm -rf $(OBJ) *.o
