bin=httpserver
src=httpserver.cc
cc=g++
ldflags=-lpthread

$(bin):$(src)
	$(cc) -o $@ $^ $(ldflags) -std=c++11

.PHONY:clean
clean:
	rm -rf $(bin)
