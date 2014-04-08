OBJ:=RemoveDuplicatesFromSortedArray RemoveElement LengthOfLastWord PlusOne


.PHONY:clean
CC:=g++
RemoveDuplicatesFromSortedArray:RemoveDuplicatesFromSortedArray.cpp

RemoveElement:RemoveElement.cpp

LengthOfLastWord:LengthOfLastWord.cpp

PlusOne:PlusOne.cpp

clean:
	rm -rf $(OBJ) *.o
