CELLO_DIR = ../Cello
CFLAGS = -g -I.. -I$(CELLO_DIR)/include -L$(CELLO_DIR) -lCello
SRCS = $(wildcard *.c)
BUILD_DIR = build

all: $(patsubst %.c, $(BUILD_DIR)/%, $(notdir $(SRCS)))
	@echo "all files compiled!"

$(BUILD_DIR)/%: %.c $(CELLO_DIR)/libCello.a $(BUILD_DIR)
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

$(CELLO_DIR)/libCello.a: $(CELLO_DIR)/Makefile
	$(MAKE) -C $(CELLO_DIR) libCello.a
