
ROOT = "." 
INPUT = "./gradient_descent.m"
INPUT2 = "./plot.gnu"
OUTPUT = "$(ROOT)/output.dat"
all:

plot : 
	@octave $(INPUT)
	@gnuplot $(INPUT2)
	@rm -rf input.dat

ProjectProposal :
	@pdflatex ProjectProposal
	@bibtex ProjectProposal
	@pdflatex ProjectProposal
	@pdflatex ProjectProposal

GayatriMantra :
	@devnag GayatriMantra.dn
	@pdflatex GayatriMantra 

clean : 
	@echo "Cleaning UP......"
	@rm -rf output.dat
	@rm -rf plot.png
	@rm -rf ProjectProposal.aux
	@rm -rf ProjectProposal.bbl
	@rm -rf ProjectProposal.blg
	@rm -rf ProjectProposal.log
	@rm -rf ProjectProposal.out
	@rm -rf ProjectProposal.pdf
	@rm -rf GayatriMantra.log
	@rm -rf GayatriMantra.tex
	@rm -rf GayatriMantra.aux
	@rm -rf GayatriMantra.pdf
