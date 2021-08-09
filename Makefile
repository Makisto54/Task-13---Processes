.PHONY: clean

all: process tree_process bash_interpretator

process: process.c
	gcc -g process.c -o process

tree_process: tree_process.c
	gcc -g tree_process.c -o tree_process

bash_interpretator: bash_interpretator.c
	gcc -g bash_interpretator.c -o bash_interpretator

clean:
	rm process tree_process bash_interpretator