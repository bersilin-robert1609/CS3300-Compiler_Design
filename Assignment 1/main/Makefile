clean:
	rm -f lex.yy.c *.tab.c a.out *.exe *~

%.exe: %.l %.y
	flex $<
	bison $(word 2,$^) -Wcounterexamples
	gcc $*.tab.c -o $@ -lfl
	# gcc $*.tab.c -o $@ -ll #on macOS