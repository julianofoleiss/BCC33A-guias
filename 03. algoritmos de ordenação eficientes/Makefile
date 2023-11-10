all:
	pandoc -s topico3_1.md -o topico3_1.tex -V geometry:margin=1in -V colorlinks --template=/home/juliano/.pandoc/default.latex
	pandoc -s topico3_2.md -o topico3_2.tex -V geometry:margin=1in -V colorlinks --template=/home/juliano/.pandoc/default.latex
	pandoc -s topico3_3.md -o topico3_3.tex -V geometry:margin=1in -V colorlinks --template=/home/juliano/.pandoc/default.latex
	pdflatex topico3_1.tex
	pdflatex topico3_2.tex
	pdflatex topico3_3.tex
	rm *.out *.log
