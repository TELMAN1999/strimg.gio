EXE:=exe

$(EXE): main.cpp string.cpp string.h
	g++ $^ -o $@

clean: 
	rm $(EXE)
