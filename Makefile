cc=g++
cflags= -Wall -O -std=c++11
exe=genproj
binpath=/usr/local/bin/
#objs = main.o ctemplate.o
objs := $(patsubst %.cc,%.o,$(wildcard *.cc))

bin: $(exe)

.cc.o:
	$(cc) $(cflags) -c $< -o $@

$(exe): $(objs)
	$(cc) $(cflags) -o $(exe) $(objs)

run: $(exe)
	./$(exe)

install: $(exe)
	cp $(exe) $(binpath)

clean:
	rm -f *.o $(exe)
