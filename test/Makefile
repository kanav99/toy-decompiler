all:
	gcc sample.c -o sample
	objdump -d sample | awk -v RS= '/^[[:xdigit:]]+ <_main>/' > assembly.s
	sed '1d' assembly.s > tmpfile; mv tmpfile assembly.s