bin=httpserver
src=httpserver.cc
cc=g++
ldflags=-lpthread

.PHONY:all
	
all:$(bin) cgi
$(bin):$(src)
	$(cc) -o $@ $^ $(ldflags) -std=c++11

.PHONY:cgi

cgi:
	g++ -o TestCgi TestCgi.cc

.PHONY:clean
clean:
	rm -rf $(bin)   TestCgi
