SOURCES := $(wildcard *.cpp)
OBJS := $(subst .cpp,.o,$(SOURCES))

main: $(OBJS)
	g++ -std=c++17 -o $@ $^
%.o: %.cpp
	g++ -o $@ -c $^ -I.
info:
	$(info $(SOURCES))
	$(info $(OBJS))
clean:
	rm *.o
