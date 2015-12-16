SUBDIRS = 0-mono 1-fgetc 2-read 3-inline 4-class 5-virtualFn

.SILENT:


subdirs: clean
	for dir in $(SUBDIRS); do \
	   $(MAKE) -C $$dir; \
	done

run:
	echo 'built-in wc'
	bash -c 'time wc long.txt; echo'
	bash -c 'echo 0-mono; time 0-mono/wc long.txt; echo'
	bash -c 'echo 1-fgetc; time 1-fgetc/wc long.txt; echo'
	bash -c 'echo 2-read; time 2-read/wc long.txt; echo'
	bash -c 'echo 3-inline; time 3-inline/wc long.txt; echo'
	bash -c 'echo 4-class; time 4-class/wc long.txt; echo'
	bash -c 'echo 5-virtualFn; time 5-virtualFn/wc long.txt; echo'

clean:
	/bin/rm -f *.o  *~
	for dir in $(SUBDIRS); do \
	   $(MAKE) -C $$dir clean; \
	done

