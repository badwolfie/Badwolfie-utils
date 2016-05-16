OUTPUT = bdw-utils.a
OBJECT = bdw-utils.o

$(OUTPUT): $(OBJECT)
	ar rcs $(OUTPUT) $(OBJECT)

$(OBJECT): bdw-utils.c bdw-utils.h
	gcc -c bdw-utils.c

clean:
	rm -f $(OUTPUT) $(OBJECT)
