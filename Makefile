CFLAGS=-Wall -g
FILENAME=ex15

clean:

	rm -fv $(FILENAME)
	make $(FILENAME)
	./$(FILENAME)
