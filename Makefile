MODULES = 2
all:
	for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} all); \
	done
clean:
	for dir in $(MODULES); do \
		(cd $$dir; ${MAKE} clean); \
	done
