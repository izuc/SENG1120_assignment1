CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Node.cpp LinkedList.cpp Train.cpp TrainDemo.cpp
value_typeS=$(SOURCES:.cpp=.o)
EXECUTABLE=Train

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(value_typeS)
	$(CC) $(LDFLAGS) $(value_typeS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core