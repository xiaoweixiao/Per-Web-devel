bin=httpserver
src=httpserver.cc
cc=g++
ldflags=-lpthread

.PHONY:all
	
all:$(bin)  Cal
$(bin):$(src)
	$(cc) -o $@ $^ $(ldflags) -std=c++11

.PHONY:clean
clean:
	rm -rf $(bin) ./wwwroot/Cal output

.PHONY:Cal

Cal:Cal.cc
	g++ -o Cal Cal.cc

.PHONY:output
	mkdir output
	cp $(bin) output
	cp wwwroot output -rf
	cp start.sh output
	cp Cal output/wwwroot
