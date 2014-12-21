# IL file in latex della relazione
FILE_REL_TEX = $(wildcard ./latex/relazione_*.tex)
# Crea il nome del file .pdf da produrre dal nome del .tex
PDF_RELAZIONE = $(patsubst %.tex, %.pdf, $(FILE_REL_TEX) )
# Guarda i templatescript. Se non ci sono la variabile è vuota (a differenza della solita shell expansion) grazie a wildcard
TEMPLATE_SCRIPT = $(wildcard ./gnuplot/*.templatescript)

relazione: $(PDF_RELAZIONE)
	echo "Faccio la relazione..."
	cp $(PDF_RELAZIONE) ./

# Da aggiungere le tabelle
$(PDF_RELAZIONE): grafici
	echo "Faccio il pdf..."
#Ogni riga viene eseguita in una subshell diversa, quindi se faccio cd devo mettere sulla stessa linea gli altri comandi che necessitano dell'effetto di cd
	cd ./latex; pwd; pdflatex ./relazione_*.tex

grafici: generaGnuplotScript
	echo "Faccio i grafici..."
	./script/FaiGrafici.sh

generaGnuplotScript: $(TEMPLATE_SCRIPT)
	cd ./script; ./DriverPerTemplate.sh

# ./gnuplot/%.gnuplotscript: ./gnuplot/%.templatescript
	

.PHONY: clean
clean:
# @echo fa in modo che make non "echi" anche echo "Faccio il clean..."
	@echo "Faccio il clean..."
	-rm ./Relazione_*.pdf
	-rm $(PDF_RELAZIONE)
	-rm ./gnuplot/immagini/*
	-rm ./gnuplot/fit/*
	-rm ./*.log
	-rm ./latex/*.toc ./latex/*.log ./latex/*.aux ./latex/*.lof ./latex/*.lot
	-rm ./temp/*
