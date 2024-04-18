CC=g++
CFLAGS=-Wall -g
Target=res
Src:=$(wildcard ./src/*.cpp)
Objs:=$(patsubst %.cpp,%.o,$(Src))
INCLUDES = -I ./include
$(Target):$(Objs)
	echo $(Objs)
	@mkdir -p output
	$(CC) $(Objs) -o output/$(Target)

%.o:%.cpp
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm -f ./src/*.o