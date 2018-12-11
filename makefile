bin=httpserver
src=httpserver.cc
cc=g++
LDflags=-lpthread

.PHONY:all
	
all:$(bin)  Cal

$(bin):$(src)
	$(cc) -o $@ $^ $(LDflags) -std=c++11

.PHONY:clean
clean:
	rm -rf $(bin) Cal output 

.PHONY:Cal
Cal:Cal.cc
	g++ -o Cal Cal.cc

.PHONY:output
output:
	mkdir output
	cp $(bin) output
	cp -rf wwwroot output 
	cp start.sh output
	cp Cal output/wwwroot
