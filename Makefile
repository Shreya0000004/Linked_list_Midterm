all: linkedlist1 linkedlisttest linkedlist3

linkedlist1: linkedlist1.cpp
	g++ -o linkedlist1 linkedlist1.cpp

linkedlisttest: linkedlisttest.cpp
	g++ -o linkedlisttest linkedlisttest.cpp

linkedlist3: linkedlist3.cpp
	g++ -o linkedlist3 linkedlist3.cpp

clean:
	rm -f linkedlist1 linkedlisttest linkedlist3

.PHONY: all clean

