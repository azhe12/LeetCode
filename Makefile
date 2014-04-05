OBJ:=RemoveDuplicatesFromSortedArray RemoveElement LengthOfLastWord


.PHONY:clean
CC:=g++
RemoveDuplicatesFromSortedArray:RemoveDuplicatesFromSortedArray.cpp

RemoveElement:RemoveElement.cpp

LengthOfLastWord:LengthOfLastWord.cpp

clean:
	rm -rf $(OBJ) *.o
