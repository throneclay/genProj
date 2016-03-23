cc=g++
cflags= -Wall -O -std=c++11
cflags+=-DDEBUG
exe=genProj
objs=main.o \
	ctemplate.o \

#templateProj.o 

bin: $(exe)

.cc.o:
	$(cc) $(cflags) -c $< -o $@

$(exe): $(objs)
	$(cc) $(cflags) -o $(exe) $(objs)

run: $(exe)
	./$(exe)

install: $(exe)
	cp $(exe) /usr/bin

clean:
	rm -f *.o $(exe)
