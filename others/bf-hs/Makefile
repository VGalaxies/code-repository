.PHONY: clean

run: ./bf.hs
	ghc -dynamic -o bf bf.hs
	./bf < ./in

clean:
	rm -f ./bf.hi ./bf.o ./bf
