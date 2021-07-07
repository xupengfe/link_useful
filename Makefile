BIN = link link2

all: $(BIN)

$(all):
	$(CC) -o $@ $<

clean:
	rm -f $(BIN)
