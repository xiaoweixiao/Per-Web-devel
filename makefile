bin=httpserver
src=httpserver.cc
cc=g++
ldflags=-lpthread

$(bin):$(src)
	$(cc) -o $@ $^ $(ldflags)

.PHONY:clean
clean:
	rm -rf $(bin)
