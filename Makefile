output = bdw-utils.a
object = bdw-utils.o

$(output): $(object)
	ar rcs $(output) $(object)

$(object): bdw-utils.c bdw-utils.h
	gcc -c bdw-utils.c

clean:
	rm -f $(output) $(object)
